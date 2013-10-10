#include"Polynomial.hpp"

class Polynomial_one:public Polynomial{
private:
  std::vector<int*> valnum;
public:
  Polynomial_one();
  void product(Polynomial_one pol2,int max_len);
  int getvalnum(int idx1,int idx2);
  void push_monomial(std::string term, int coe);
  void push(Polynomial_one poly);
  void sub(Polynomial_lhm pol1,Polynomial_lhm pol2);
};
