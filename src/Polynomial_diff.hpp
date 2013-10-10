#include"trie.hpp"
#include <iostream>

class Polynomial{
private:
  std::vector<std::string> terms;
  std::vector<std::vector<int> > valnum;
  std::vector<int> coes;
  int size;
  int length;
public:
  Polynomial();
  void product(Polynomial pol2,int max_len);
  void push_monomial(std::string term,int coe);
  std::string getterms(uint idx);
  uint getcoe(uint idx);
  int getlength();
  void push(Polynomial pol);
  void get_polynomial(trie *tr);
  void print();
  void sub(Polynomial pol1, Polynomial pol2);
};
