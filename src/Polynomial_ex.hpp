#include"trie_ex.hpp"
#include <iostream>


class Polynomial_ex{
private:
  std::vector<std::string> terms;
  std::vector<Fraction> coes;
  int length;
public:
  Polynomial_ex();
  void product(Polynomial_ex pol2,int max_len);
  void push_monomial(std::string term,int numerator,int denominator);
  std::string getterms(uint idx);
  Fraction getcoe(int idx);
  int getlength();
  void push(Polynomial_ex poly);
  void get_polynomial(trie_ex *tr);
  void print();
  void sub(Polynomial_ex pol1,Polynomial_ex pol2);
  void clear();
  void searchtrie(trie_ex *tri,std::string str,std::queue<std::string> &qu_str,std::queue<trie_ex*> &qu);
};
