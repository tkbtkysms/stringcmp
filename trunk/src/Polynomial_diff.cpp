#include"Polynomial_diff.hpp"

Polynomial_diff::Polynomial_diff(){
  length = 0;
}

void Polynomial::product(Polynomial pol2,int max_len){
  trie *tr = new trie();
  std::string term1,term2;
  int interval;
  for(int i = 0; i <length; i++){
    term1 = terms[i];
    interval = max_len - term1.length();
    for(int j = 0;j < pol2.getlength(); j++){
      if(pol2.getterms(j).length() > interval){
	break;
      }
      tr->set(term1 + pol2.getterms(j),0,coes[i]*pol2.getcoe(j),term1.length()+pol2.getterms(j).length());
    }
  }
  length = 0;
  size = 0;
  terms.clear();
  coes.clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}

void Polynomial::push_monomial(std::string term,int coe){
  if(size <= length){
    size += 1;
    valnum.resize(size);
    valnum[size-1].resize(5);
    for(int i = 0; i < 5;i++){
      valnum[size-1][i] = 0;
    }
  }
  bool flag = true;
  for(int i = 0; i < term.length(); i++){
    if(term[i] == 'X'){
      valnum[length][0]++;
      if(valnum[length][0] > 1){
	flag = false;
	for(int j = 0; j < 5; j++){
	  valnum[length][j] = 0;
	}
      	break;
      }
    }
    else if(term[i] == 'Y'){
      valnum[length][1]++;
      if(valnum[length][1] > 1){
	flag = false;
	for(int j = 0; j < 5; j++){
	  valnum[length][j] = 0;
	}
      	break;
      }
    }
    else if(term[i] == 'Z'){
      valnum[length][2]++;
      if(valnum[length][2] > 1){
	flag = false;
	for(int j = 0; j < 5; j++){
	  valnum[length][j] = 0;
	}
	break;
      }
    }
    else if(term[i] == 'V'){
      valnum[length][3]++;
      if(valnum[length][3] > 1){
	flag = false;
	for(int j = 0; j < 5; j++){
	  valnum[length][j] = 0;
	}
	break;
      }
    }
    else if(term[i] == 'W'){
      valnum[length][4]++;
      if(valnum[length][4] > 1){
	flag = false;
	for(int j = 0; j < 4; j++){
	  valnum[length][j] = 0;
	}
	break;
      }
    }
  }
  if(flag){
    terms.push_back(term);
    coes.push_back(coe);
    length++;
  }
}

int Polynomial::getlength(){
  return length;
}

std::string Polynomial::getterms(uint idx){
  return terms[idx];
}

uint Polynomial::getcoe(uint idx){
  return coes[idx];
}

void Polynomial::push(Polynomial pol){
  for(int i = 0; i < pol.getlength();i++){
    push_monomial(pol.getterms(i),pol.getcoe(i));
  }
}


void Polynomial::sub(Polynomial pol1, Polynomial pol2){
  trie *tr = new trie();
  for(int i = 0; i < pol1.getlength(); i++){
    tr->set(pol1.getterms(i),0,pol1.getcoe(i),pol1.getterms(i).length());
  }
  for(int i = 0; i < pol2.getlength(); i++){
    tr->set(pol2.getterms(i),0,-pol2.getcoe(i),pol2.getterms(i).length());
  }
  size = 0;
  length = 0;
  terms.clear();
  coes.clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}
