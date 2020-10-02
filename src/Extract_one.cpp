#include "Extract_one.hpp"

Extract::Extract()
{
    result_size = 0;
}
void Extract::CalcMilnor(Initialdata Id, Rule rule1, int newnumExtract, int order1, int lnum)
{
    prun_size = 0;
    order = order1;
    result.push_back(Decompose(Id, rule1, newnumExtract, lnum));
    result_size++;
    //std::cout << "monomial size after pruning " << prun_size << std::endl;
    std::cout << "answer" << result_size << ": ";
    result[result_size - 1].print();
    std::cout << std::endl;
    std::cout << std::endl;
}

void Extract::sub(Initialdata Id1, Initialdata Id2, Rule rule1, Rule rule2, int newnumExtract, int order1, int lnum1, int lnum2)
{
    CalcMilnor(Id1, rule1, newnumExtract, order1, lnum1);
    CalcMilnor(Id2, rule2, newnumExtract, order1, lnum2);
    Polynomial_lhm diff;
    diff.sub(result[0], result[1]);
    std::cout << "diff: ";
    diff.print();
    std::cout << std::endl;
    std::cout << std::endl;
}

Polynomial_lhm Extract::Decompose(Initialdata Id, Rule rule, int newnumExtract, int lnum)
{
    longitude lf;
    countsize.push_back(0);
    q.push_back(std::queue<char>());
    expandFomula(rule.getsize(), 0);
    numExtract = newnumExtract;
    for(size_t i = 0; i < Id.getsize(); i++)
    {
        q[0].push(Id.getvariable(i));
        countsize[0]++;
    }
    recursiveDecompose(rule, 0, lnum);
    Polynomial_lhm answer;
    answer.push(fomula[0][Id.getvariable(0) - 1]);
    ullint allsize = leaf_size[0][Id.getvariable(0) - 1];
    for(size_t i = 1; i < Id.getsize(); i++)
    {
        answer.product(fomula[0][Id.getvariable(i) - 1], (int)order);
        allsize += leaf_size[0][Id.getvariable(i) - 1];
    }
    //std::cout << "all monomial size " << allsize << std::endl;
    countsize.clear();
    q.clear();
    for(int i = 0; i < fomula.size(); i++)
    {
        fomula[i].clear();
    }
    fomula.clear();
    leaf_size.clear();
    return answer;
}

void Extract::monotopoly(int depth, int segment, int string_num, int lnum)
{
    std::string term;
    int string_num_abs;
    fomula[depth][segment - 1].push_monomial("", 1);
    if((string_num_abs = abs(string_num)) != lnum)
    {
        if(string_num_abs < 3)
        {
            term = 'X' + string_num_abs - 1;
        }
        else
        {
            term = 'V' + string_num_abs - 4;
        }
        if(string_num < 0)
        {
            fomula[depth][segment - 1].push_monomial(term, -1);
        }
        else
        {
            fomula[depth][segment - 1].push_monomial(term, 1);
        }
    }
}

void Extract::recursiveDecompose(Rule rule, uint recursivenum, int lnum)
{
    if(q.size() < recursivenum + 2)
    {
        q.push_back(std::queue<char>());
        countsize.push_back(0);
        expandFomula(rule.getsize(), recursivenum + 1);
    }
    longitude lf;
    char form;
    if(numExtract == recursivenum)
    {
        while(!q[recursivenum].empty())
        {
            char front = q[recursivenum].front();
            q[recursivenum].pop();
            prun_size++;
            if(fomula[recursivenum][front - 1].getlength() == 0)
            {
                leaf_size[recursivenum][front - 1] = 1;
                monotopoly(recursivenum, front, rule.getform(front), lnum);
                countsize[recursivenum + 1]++;
            }
        }
    }
    else
    {
        while(!q[recursivenum].empty())
        {
            char front = q[recursivenum].front();
            q[recursivenum].pop();
            if(fomula[recursivenum][front - 1].getlength() == 0)
            {
                lf = rule.getleft(front);
                for(size_t i = 0; i < lf.getsize(); i++)
                {
                    q[recursivenum + 1].push(lf.getvariable(i));
                    countsize[recursivenum + 1]++;
                }
                recursiveDecompose(rule, recursivenum + 1, lnum);
                Calculate(rule, recursivenum, front);
            }
            else
            {
                prun_size++;
            }
        }
    }
}

void Extract::expandFomula(int size, int extractid)
{
    fomula.push_back(std::vector<Polynomial_lhm>());
    leaf_size.push_back(std::vector<ullint>());
    for(int i = 0; i < size; i++)
    {
        fomula[extractid].push_back(Polynomial_lhm());
        leaf_size[extractid].push_back(0);
    }
}

void Extract::Calculate(Rule rule, int recursivenum, int front)
{
    longitude lf = rule.getleft(front);
    fomula[recursivenum][front - 1].push(fomula[recursivenum + 1][lf.getvariable(0) - 1]);
    leaf_size[recursivenum][front - 1] = leaf_size[recursivenum + 1][lf.getvariable(0) - 1];
    for(size_t i = 1; i < lf.getsize(); i++)
    {
        fomula[recursivenum][front - 1].product(fomula[recursivenum + 1][lf.getvariable(i) - 1], (int)order);
        leaf_size[recursivenum][front - 1] += leaf_size[recursivenum + 1][lf.getvariable(i) - 1];
    }
}
