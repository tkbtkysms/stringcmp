#include <queue>
#include <string>
#include "Fraction.hpp"

typedef unsigned int uint;

class trie_ex{
private:
  trie_ex* next[5];
  Fraction coe;
public:
  trie_ex();
  ~trie_ex();
  void set(std::string term, uint pos, Fraction new_coe ,uint length);
  trie_ex* get(char term);
  Fraction getcoe();
  void delete_trie();
};
