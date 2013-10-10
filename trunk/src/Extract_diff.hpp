#ifndef EXTRACT_HPP
#define EXTRACT_HPP
#include "Polynomial.hpp"
#include "Rule.hpp"
#include "left.hpp"
#include "Latitude.hpp"
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>

typedef unsigned long long int ullint;
class Extract{
private:
  std::vector<std::queue<char> > q;
  std::vector<char> outbuf;
  std::vector<ullint> countsize;
  ullint numExtract;
  ullint prun_size;
  std::vector<std::vector<Polynomial> > fomula;
  std::vector<std::vector<ullint> > leaf_size;
  int order;
public:  
private:
  void recursiveDecompose(Rule rule,uint recursivenum,int lnum);
  void Calculate(Rule rule,int recursivenum,int front);
  Polynomial Decompose(Latitude lat,Rule rule,int newnumExtract,int order1, int lnum);
  void expandFomula(int swize , int extractid);
public:
  void CalcMilnor(Latitude lat1,Latitude lat2,Rule rule1,Rule rule2, int newnumExtract,int order,int new_num1,int new_num2);
  
};
#endif
