#include"Polynomial.hpp"

Polynomial::Polynomial(){
  length = 0;
}


void Polynomial::product(Polynomial pol2,int max_len){
  trie *tr = new trie();
  std::string term1;
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
  clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}

void Polynomial::push_monomial(std::string term,int coe){
  terms.push_back(term);
  coes.push_back(coe);
  length++;
}

int Polynomial::getlength(){
  return length;
}

void Polynomial::clear(){
  length = 0;
  terms.clear();
  coes.clear();
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

void Polynomial::print(){
  if(length == 0){
    std::cout << 0 << std::endl;
  }
  else{
    for(int i = 0; i < length;i++){
      if(coes[i] > 0){
	if(i != 0){
	  if(coes[i] != 1){
	    std::cout << " + " << coes[i] << terms[i];
	  }
	  else{
	    std::cout << " + " << terms[i];
	  }
	}
	else{
	  std::cout << coes[i] << terms[i];
 
	}
      }
      else{
	if(coes[i] != -1){
	  std::cout << " - " << -coes[i] << terms[i];
	}
	else{
	  std::cout << " - " << terms[i];
	}
      }
    }
  }
  std::cout << std::endl;
}


void Polynomial::get_polynomial(trie *tri){
  std::string tmp2;
  std::queue<std::string>qu_str;
  std::queue<trie*>qu;
  searchtrie(tri,tmp2,qu_str,qu);
  trie *tr_tmp2;
  while(!qu.empty()){
    tr_tmp2 = qu.front();
    qu.pop();
    tmp2 = qu_str.front();
    qu_str.pop();
    searchtrie(tr_tmp2,tmp2,qu_str,qu);
  }
}

void Polynomial::searchtrie(trie *tri,std::string str,std::queue<std::string> &qu_str,std::queue<trie*> &qu){
  char char_tmp;
  if(tri->getcoe() != 0){
    push_monomial(str,tri->getcoe());
  }
  for(char i = 0; i < 3;i++){
    if(tri->get((char_tmp = 'X' + i)) != NULL){
      qu.push(tri->get(char_tmp));
      qu_str.push(str + char_tmp);
    }
  }
  for(char i = 0; i < 2 ;i++){
    if(tri->get((char_tmp = 'V' + i)) != NULL){
      qu.push(tri->get(char_tmp));
      qu_str.push(str + char_tmp);
    } 
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
  clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}
