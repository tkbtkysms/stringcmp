#include"trie.hpp"
#include <iostream>

class Polynomial{
private:
  std::vector<std::string> terms;
  std::vector<int*> valnum;
  std::vector<int> coes;
  int length;
private:
  void searchtrie(trie *tr,std::string str,std::queue<std::string> &qu_str,std::queue<trie*> &qu);
public:
  Polynomial();
  void product(Polynomial pol2,int max_len);
  void push_monomial(std::string term,int coe);
  std::string getterms(uint idx);
  uint getcoe(uint idx);
  int getlength();
  void push(Polynomial pol);
  void get_polynomial(trie *tr);
  int getvalnum(int idx1,int idx2);
  void print();
};
