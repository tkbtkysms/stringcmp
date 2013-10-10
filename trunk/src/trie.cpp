#include "trie.hpp"
#include <iostream>

trie::trie(){
  for(int i = 0; i < 5; i++){
    next[i] = NULL;
  }
  coe = 0;
}

trie::~trie()
{
}

void trie::set(std::string term, uint pos ,int new_coe, uint length){
  if(length == pos){
    coe += new_coe;
  }
  else{
    int var = term[pos] - 'X';
    if(var < 0){
      var = 5 + var;
    }
    if(next[var] == NULL){
      next[var] = new trie();
    }
    next[var]->set(term,pos+1,new_coe,length);
  }
}

trie* trie::get(char term){
  int var = term - 'X';
  if(var < 0){
    var = 5 + var;
  }
  return next[var];
}

int trie::getcoe(){
  return coe;
}

void trie::delete_trie(){
  for(int i = 0 ; i < 5; i++){
    if(next[i] != NULL){
      next[i]->delete_trie();
      delete next[i];
    }
  }
}
