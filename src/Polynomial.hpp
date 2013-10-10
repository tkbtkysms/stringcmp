#ifndef _POLYNOMIAL_HPP
#define _POLYNOMIAL_HPP

#include"trie.hpp"
#include <iostream>

class Polynomial{
private:
  std::vector<std::string> terms;
  std::vector<int> coes;
  int length;
private:
  void searchtrie(trie *tr,std::string str,std::queue<std::string> &qu_str,std::queue<trie*> &qu);
public:
  Polynomial();
  void product(Polynomial pol2,int max_len);
  virtual void push_monomial(std::string term,int coe);
  std::string getterms(uint idx);
  uint getcoe(uint idx);
  int getlength();
  void clear();
  void push(Polynomial pol);
  void get_polynomial(trie *tr);
  void print();
  void sub(Polynomial pol1, Polynomial pol2);
};

#endif
