#include"Polynomial.hpp"

class Polynomial_lhm:public Polynomial{
private:
  std::vector<int*> valnum;
public:
  Polynomial_lhm();
  void product(Polynomial_lhm pol2,int max_len);
  int getvalnum(int idx1,int idx2);
  void push_monomial(std::string term, int coe);
  void push(Polynomial_lhm poly);
};
