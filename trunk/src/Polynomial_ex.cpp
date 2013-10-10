#include"Polynomial_ex.hpp"

Polynomial_ex::Polynomial_ex(){
  length = 0;
}

void Polynomial_ex::product(Polynomial_ex pol2,int max_len){
  trie_ex *tr = new trie_ex();
  std::string term1;
  int interval;

  for(int i = 0; i < getlength(); i++){
    term1 = getterms(i);
    interval = max_len - term1.length();
    for(int j = 0;j < pol2.getlength(); j++){
      if(pol2.getterms(j).length() > interval){
	break;
      }
      tr->set(term1 + pol2.getterms(j),0,coes[i].product(pol2.getcoe(j)),term1.length()+pol2.getterms(j).length());
    }
  }

  clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}

void Polynomial_ex::push_monomial(std::string term,int numerator,int denominator){
  Fraction frc;
  frc.set(numerator,denominator);
  terms.push_back(term);
  coes.push_back(frc);
  length++;
}

int Polynomial_ex::getlength(){
  return length;
}

std::string Polynomial_ex::getterms(uint idx){
  return terms[idx];
}

Fraction Polynomial_ex::getcoe(int idx){
  return coes[idx];
}

void Polynomial_ex::push(Polynomial_ex poly){
  for(int i = 0; i < poly.getlength();i++){
    Fraction frac = poly.getcoe(i);
    push_monomial(poly.getterms(i),frac.getnumerator(),frac.getdenominator());
  }
}


void Polynomial_ex::print(){
  if(length == 0){
    std::cout << 0 << std::endl;
  }
  else{
    for(int i = 0; i < length;i++){
      if(coes[i].getnumerator() >= 0){
	if(i != 0){
	  if(coes[i].getdenominator() != 1){
	    std::cout << " + " << coes[i].getnumerator()<< "/" << coes[i].getdenominator() << terms[i];
	  }
	  else{
	    if(coes[i].getnumerator() == 1){
	      std::cout << " + " << terms[i];
	    }
	    else{
	      std::cout << " + " << coes[i].getnumerator() <<
		terms[i];
	    }
	  }
	}
	else{
	  if(coes[i].getdenominator() == 1){
	    if(!terms[i].empty()){
	      if(coes[i].getnumerator() == 1){
		std::cout << terms[i];
	      }
	      else{
		std::cout << coes[i].getnumerator() << terms[i];
	      }
	    }
	    else{
	      std::cout << coes[i].getnumerator();
	    }
	  }
	  else{
	    std::cout << coes[i].getnumerator() << "/" << coes[i].getdenominator() << terms[i];
	  }
	}
      }
      else{
	if(coes[i].getdenominator() == 1){
	  if(coes[i].getnumerator() == -1 ){
	    std::cout << " - " << terms[i];
	  }
	  else{
	    std::cout << " - " << -coes[i].getnumerator() << terms[i];
	  }
	}
	else{
	  std::cout << " - " << -coes[i].getnumerator() << "/" << coes[i].getdenominator() << terms[i];
	}
      }
    }
  }
  std::cout << std::endl;
}


void Polynomial_ex::get_polynomial(trie_ex *tri){
  std::string tmp2;
  std::queue<std::string>qu_str;
  std::queue<trie_ex*>qu;
  searchtrie(tri,tmp2,qu_str,qu);
  trie_ex *tr_tmp2;
  while(!qu.empty()){
    tr_tmp2 = qu.front();
    qu.pop();
    tmp2 = qu_str.front();
    qu_str.pop();
    searchtrie(tr_tmp2,tmp2,qu_str,qu);
  }
}

void Polynomial_ex::searchtrie(trie_ex *tri,std::string str,std::queue<std::string> &qu_str,std::queue<trie_ex*> &qu){
  char char_tmp;
  Fraction frc = tri->getcoe();
  if(frc.getnumerator() != 0){
    push_monomial(str,frc.getnumerator(),frc.getdenominator());
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

void Polynomial_ex::sub(Polynomial_ex pol1, Polynomial_ex pol2){
  trie_ex *tr = new trie_ex();
  Fraction frc;
  for(int i = 0; i < pol1.getlength(); i++){
    tr->set(pol1.getterms(i),0,pol1.getcoe(i),pol1.getterms(i).length());
  }
  for(int i = 0; i < pol2.getlength(); i++){
    frc.set(-pol2.getcoe(i).getnumerator(),pol2.getcoe(i).getdenominator());
    tr->set(pol2.getterms(i),0,frc,pol2.getterms(i).length());
  }
  clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}


void Polynomial_ex::clear(){
  length = 0;
  terms.clear();
  coes.clear();
}
