#include"Polynomial_one.hpp"

Polynomial::Polynomial(){
  length = 0;
}

void Polynomial::product(Polynomial pol2,int max_len){
  trie *tr = new trie();
  std::string term1,term2;
  int interval;
  bool flag;
  for(int i = 0; i <length; i++){
    term1 = terms[i];
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
	tr->set(term1 + pol2.getterms(j),0,coes[i]*pol2.getcoe(j),term1.length()+pol2.getterms(j).length());
      }
    }
  }
  length = 0;
  terms.clear();
  coes.clear();
  valnum.clear();
  get_polynomial(tr);
  tr->delete_trie();
  delete tr;
}

void Polynomial::push_monomial(std::string term,int coe){
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
  terms.push_back(term);
  coes.push_back(coe);
  length++;
}

int Polynomial::getvalnum(int idx1,int idx2){
  return valnum[idx1][idx2];
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

void Polynomial::print(){
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
  std::cout << std::endl;
}


void Polynomial::get_polynomial(trie *tri){
  std::string tmp2;
  std::queue<std::string>qu_str;
  std::queue<trie*>qu;
  char char_tmp;
  /*if(tri->getcoe() != 0){
    push_monomial(tmp2,tri->getcoe());
  }
  for(char i = 0; i < 3;i++){
    if(tri->get((char_tmp = 'X' + i)) != NULL){
      qu.push(tri->get(char_tmp));
      tmp2 = char_tmp;
      qu_str.push(tmp2);
    }
  }
  for(char i = 0; i < 2 ;i++){
    if(tri->get((char_tmp = 'V' + i)) != NULL){
      qu.push(tri->get(char_tmp));
      tmp2 = char_tmp;
      qu_str.push(tmp2);
    } 
  }*/
 searchtrie(tri,tmp2,qu_str,qu);
  trie *tr_tmp2;
  while(!qu.empty()){
    tr_tmp2 = qu.front();
    qu.pop();
    tmp2 = qu_str.front();
    qu_str.pop();
    /*    if(tr_tmp2->getcoe() != 0){
      push_monomial(tmp2,tr_tmp2->getcoe());
    }
    for(char i = 0; i < 3;i++){
      if(tr_tmp2->get((char_tmp = 'X' + i)) != NULL){
	qu.push(tr_tmp2->get(char_tmp));
	qu_str.push(tmp2 + char_tmp);
      }
    }
    for(char i = 0; i < 2 ;i++){
      if(tr_tmp2->get((char_tmp = 'V' + i)) != NULL){
	qu.push(tr_tmp2->get(char_tmp));
	qu_str.push(tmp2 + char_tmp);
      }
      }*/
      searchtrie(tr_tmp2,tmp2,qu_str,qu);
  }
}

void Polynomial::searchtrie(trie *tr,std::string str,std::queue<std::string> &qu_str,std::queue<trie*> &qu){
  char char_tmp;
  if(tr->getcoe() != 0){
    push_monomial(str,tr->getcoe());
  }
  for(char i = 0; i < 3;i++){
    if(tr->get((char_tmp = 'X' + i)) != NULL){
      qu.push(tr->get(char_tmp));
      qu_str.push(str + char_tmp);
    }
  }
  for(char i = 0; i < 2 ;i++){
    if(tr->get((char_tmp = 'V' + i)) != NULL){
      qu.push(tr->get(char_tmp));
      qu_str.push(str + char_tmp);
    } 
  }
}
