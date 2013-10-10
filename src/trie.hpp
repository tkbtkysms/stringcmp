#ifndef _TRIE_HPP
#define _TRIE_HPP
#include <queue>
#include <string>

typedef unsigned int uint;

class trie{
private:
  trie* next[5];
  int coe;
public:
  trie();
  ~trie();
  void set(std::string term, uint pos, int new_coe ,uint length);
  trie* get(char var);
  int getcoe();
  void delete_trie();
};
#endif
