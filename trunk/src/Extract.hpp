#ifndef _EXTRACT_HPP
#define _EXTRACT_HPP
#include "Polynomial.hpp"
#include "Rule.hpp"
#include <cstdlib>

typedef unsigned long long int ullint;
class Extract{
private:
  std::vector<std::queue<char> > q; 
  std::vector<ullint> countsize; 
  ullint numExtract;
  ullint prun_size;
  std::vector<std::vector<Polynomial> > fomula;
  std::vector<std::vector<ullint> > leaf_size;
  int order;
public:  
private:
  void recursiveDecompose(Rule rule,uint recursivenum);
  void Calculate(Rule rule,int recursivenum,int front);
  Polynomial Decompose(Initialdata Id,Rule rule,int newnumExtract);
  void expandFomula(int size , int extractid);
  void monotopoly(int depth,int segment,int string_num);
public:
  void CalcMilnor(Initialdata Id,Rule rule1,int newnumExtract,int order1);
  void sub(Initialdata Id1, Initialdata id2,Rule rule1,Rule rule2,int newnumExtract,int order1);
};
#endif
