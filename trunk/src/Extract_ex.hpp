#ifndef _EXTRACT_EX_HPP
#define _EXTRACT_EX_HPP
#include "Polynomial_ex.hpp"
#include "Rule.hpp"
#include <cstdlib>

typedef unsigned long long int ullint;
class Extract_ex{
private:
  std::vector<std::queue<char> > q; 
  std::vector<ullint> countsize; 
  std::vector<Polynomial_ex> result;
  int result_size;
  ullint numExtract;
  ullint prun_size;
  std::vector<std::vector<Polynomial_ex> > fomula;
  std::vector<std::vector<ullint> > leaf_size;
  int order;
public:  
private:
  void recursiveDecompose(Rule rule,uint recursivenum);
  void Calculate(Rule rule,int recursivenum,int front);
  Polynomial_ex Decompose(Initialdata Id,Rule rule,int newnumExtract);
  void expandFomula(int size , int extractid);
  void monotopoly(int depth,int segment,int string_num);
public:
  Extract_ex();
  void CalcMilnor(Initialdata Id,Rule rule1,int newnumExtract,int order1);
  void sub(Initialdata Id1, Initialdata Id2, Rule rule1, Rule rule2, int newnumExtracrt, int order1);
};

#endif
