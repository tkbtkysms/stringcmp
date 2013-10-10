#include "Polynomial_lhm.hpp"
#include "Rule.hpp"
#include <cstdlib>

typedef unsigned long long int ullint;
class Extract_lhm{
private:
  std::vector<std::queue<char> > q; 
  std::vector<ullint> countsize; 
  std::vector<Polynomial_lhm> result;
  int result_size;
  ullint numExtract;
  ullint prun_size;
  std::vector<std::vector<Polynomial_lhm> > fomula;
  std::vector<std::vector<ullint> > leaf_size;
  int order;
private:
  void recursiveDecompose(Rule rule,uint recursivenum,int lnum);
  void Calculate(Rule rule,int recursivenum,int front);
  Polynomial_lhm Decompose(Initialdata Id,Rule rule,int newnumExtract,int lnum);
  void expandFomula(int size , int extractid);
  void monotopoly(int depth,int segment,int string_num,int lnum);
public:
  Extract_lhm();
  void CalcMilnor(Initialdata Id,Rule rule1,int newnumExtract,int order1,int lnum);
  void sub(Initialdata Id1, Initialdata Id2, Rule rule1, Rule rule2, int newnumExtracrt, int order1, int lnum1,int lnum2);
};

