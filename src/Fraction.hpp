#include<algorithm>

class Fraction{
private:
  int numerator;
  int denominator;
public:
  Fraction();
  Fraction product(Fraction frac);
  Fraction subtract(Fraction frac);
  Fraction add(Fraction frac);
  void set(int new_numerator, int new_denominator);
  int getnumerator();
  int getdenominator();
private:
  int lcm(int a, int b);
};
