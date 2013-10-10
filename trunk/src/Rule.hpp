#ifndef _RULE_HPP
#define _RULE_HPP
#include "Initialdata.hpp"
#include "longitude.hpp"
#include <cstdlib>

class Rule{
private:
    std::vector<longitude> setofLeft;
    std::vector<char> form;
public:
  void constructRule(std::vector<Initialdata> lats);
  longitude getleft(char num);
  char getform(char num);
  int  getsize();
};

#endif
