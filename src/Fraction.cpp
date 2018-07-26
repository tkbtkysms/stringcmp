#include"Fraction.hpp"
#include <iostream>
#include <stdlib.h>
#include <numeric>

Fraction::Fraction(){
  denominator = 0;
  numerator = 0;
}
Fraction Fraction::product(Fraction frac){
  Fraction answer;
  if(denominator != 0 && frac.getdenominator() != 0){
    int tmp_denominator = denominator*frac.getdenominator();
    int tmp_numerator = numerator*frac.getnumerator();
    int gcd = std::gcd(abs(tmp_numerator),tmp_denominator);
    answer.set(tmp_numerator/gcd,tmp_denominator/gcd);
  }
  else{
    answer.set(0,0);
  }
  return answer;
}

Fraction Fraction::subtract(Fraction frac){
  Fraction answer;
  int tmp_numerator1,tmp_numerator2;
  int new_numerator;
  if(denominator == 0 && frac.getdenominator() == 0){
    answer.set(0,0);
  }
  else if(denominator == 0 && frac.getdenominator() != 0){
    answer.set(frac.getnumerator(),frac.getdenominator());
  }
  else if(denominator != 0 && frac.getdenominator() == 0){
    answer.set(numerator,denominator);
  }
  else{
    int lcm1 = lcm(denominator,frac.getdenominator());
    tmp_numerator1 = numerator*(lcm1/denominator);
    tmp_numerator2 = frac.getnumerator()*(lcm1/frac.getdenominator());
    if((new_numerator = tmp_numerator1 - tmp_numerator2) == 0){
      answer.set(0,0);
    }
    else{
      int gcd = std::gcd(new_numerator,lcm1);
      answer.set(new_numerator/gcd,lcm1/gcd);
    }
  }
  return answer;
}

Fraction Fraction::add(Fraction frac){
  Fraction answer;
  int tmp_numerator1,tmp_numerator2;
  int new_numerator;
  if(denominator == 0 && frac.getdenominator() == 0){
    answer.set(0,0);
  }
  else if(denominator == 0 && frac.getdenominator() != 0){
    answer.set(frac.getnumerator(),frac.getdenominator());
  }
  else if(denominator != 0 && frac.getdenominator() == 0){
    answer.set(numerator,denominator);
  }
  else{
    int lcm1 = lcm(denominator,frac.getdenominator());
    tmp_numerator1 = numerator*(lcm1/denominator);
    tmp_numerator2 = frac.getnumerator()*(lcm1/frac.getdenominator());
    if((new_numerator = tmp_numerator1 + tmp_numerator2) == 0){
      answer.set(0,0);
    }
    else{
      int gcd = std::gcd(abs(new_numerator),lcm1);
      answer.set(new_numerator/gcd,lcm1/gcd);
    }
  }
  return answer;
}

void Fraction::set(int new_numerator, int new_denominator){
  numerator = new_numerator;
  denominator = new_denominator;
}

int Fraction::getnumerator(){
  return numerator;
}

int Fraction::getdenominator(){
  return denominator;
}

int Fraction::lcm(int a, int b){
  return a*b/std::gcd(a,b);
}
