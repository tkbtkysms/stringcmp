#include "trie_ex.hpp"
#include <iostream>

trie_ex::trie_ex(){
  for(int i = 0; i < 5;i++){
    next[i] = NULL;
  }
  coe.set(0,0);
}

trie_ex::~trie_ex()
{
}

void trie_ex::set(std::string term, uint pos ,Fraction new_coe, uint length){
  if(length == pos){
    Fraction frc = coe.add(new_coe);
    coe.set(frc.getnumerator(),frc.getdenominator());
  }
  else{
    int var = term[pos] - 'X';
    if(var < 0){
      var = 5 + var;
    }
    if(next[var] == NULL){
      next[var] = new trie_ex();
    }
    next[var]->set(term,pos+1,new_coe,length);
  }
}

trie_ex* trie_ex::get(char term){
  int var = term - 'X';
  if(var < 0){
    var = 5 + var;
  }
  return next[var];
}

Fraction trie_ex::getcoe(){
  return coe;
}


void trie_ex::delete_trie(){
  for(int i = 0 ; i < 5; i++){
    if(next[i] != NULL){
      next[i]->delete_trie();
      delete next[i];
    }
  }
}

