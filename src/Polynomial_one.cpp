#include"Polynomial_one.hpp"

Polynomial_one::Polynomial_one(){
  Polynomial();
}

void Polynomial_one::product(Polynomial_one pol2,int max_len){
  trie *tr = new trie();
  std::string term1,term2;
  int interval;
  bool flag;
  for(int i = 0; i < getlength(); i++){
    term1 = getterms(i);
    interval = max_len - term1.length();
    for(int j = 0;j < pol2.getlength(); j++){
      if(pol2.getterms(j).length() > interval){
	break;
      }
      flag = true;
      for(int k = 0; k < 5; k++){
	if((valnum[i][k] + pol2.getvalnum(j,k)) > 1){
	  flag = false;
	}
      }
      
      if(flag){
	tr->set(term1 + pol2.getterms(j),0,getcoe(i)*pol2.getcoe(j),term1.length()+pol2.getterms(j).length());
      }
 
    }
  }
 
  clear();
  valnum.clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}

void Polynomial_one::push_monomial(std::string term,int coe){
  int *ab = new int[5];
  for(int i = 0; i < 5;i++){
    ab[i] = 0;
  }
  for(int i = 0; i < term.length(); i++){
    int char_num;
    if((char_num = (int)(term[i] - 'X')) < 0){
      char_num = 5 + char_num;
    }
    ab[char_num]++;
  }
  valnum.push_back(ab);
  Polynomial::push_monomial(term,coe);
}

void Polynomial_one::push(Polynomial_one poly){
  for(int i = 0; i < poly.getlength();i++){
    push_monomial(poly.getterms(i),poly.getcoe(i));
  }
}


int Polynomial_one::getvalnum(int idx1,int idx2){
  return valnum[idx1][idx2];
}
