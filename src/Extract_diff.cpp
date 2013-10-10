#include "Extract.hpp"
#include <iterator>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <sys/time.h>


void Extract::CalcMilnor(Latitude lat1,Latitude lat2 ,Rule rule1 ,Rule rule2, int newnumExtract, int order,int new_num1, int new_num2){
  prun_size = 0;
  Polynomial pol1 = Decompose(lat1,rule1,newnumExtract,order,new_num1);
  std::cout << "monomial size after pruning " << prun_size << std::endl;
  std::cout << "answer1 ";
  pol1.print();
  prun_size = 0;
  Polynomial pol2 = Decompose(lat2,rule2,newnumExtract,order,new_num2);
  Polynomial diff;
  diff.sub(pol1,pol2);
  std::cout << "monomial size after pruning " << prun_size << std::endl;
  std::cout <<"answer2 "; 
  pol2.print();
  std::cout <<"diff ";
  diff.print();
}


Polynomial Extract::Decompose(Latitude lat, Rule rule,int newnumExtract,int order1,int lnum){
    left lf;
    countsize.push_back(0);
    q.push_back(std::queue<char>());
    expandFomula(rule.getsize(),0);
    order = order1;
    numExtract = newnumExtract;
    for(size_t i = 0;i < lat.getsize();i++){
      q[0].push(lat.getvariable(i));
      countsize[0]++;
    }
    recursiveDecompose(rule,0,lnum);
    Polynomial answer;
    answer.push(fomula[0][lat.getvariable(0)-1]);
    ullint allsize = leaf_size[0][lat.getvariable(0)-1];
    for(size_t i = 1;i < lat.getsize();i++){
      answer.product(fomula[0][lat.getvariable(i)-1],(int)order);
      allsize += leaf_size[0][lat.getvariable(i)-1];
    }
    std::cout << "all monomial size " << allsize << std::endl;
    outbuf.clear();
    countsize.clear();
    q.clear();
    for(int i = 0; i < fomula.size(); i++){
      fomula[i].clear();
    }
    fomula.clear();
    leaf_size.clear();
    return answer;
}

void Extract::recursiveDecompose(Rule rule,uint recursivenum,int lnum){
  if(q.size() < recursivenum+2){
	 q.push_back(std::queue<char>());
	 countsize.push_back(0);
	 expandFomula(rule.getsize(),recursivenum+1);
       }
      left lf;
      char form;
      if(numExtract == recursivenum){
	while(!q[recursivenum].empty()){
	 char front = q[recursivenum].front();
	 q[recursivenum].pop();
	 prun_size++;
	 if(fomula[recursivenum][front -1].getlength() == 0){
	   leaf_size[recursivenum][front-1] = 1;
	   if((form = rule.getform(front)) > 0){
	     std::string term;
	     if(form == 1){
	       fomula[recursivenum][front-1].push_monomial(term,1);
	       if(lnum != 1){
		 fomula[recursivenum][front-1].push_monomial("X",1);
	       }
	     }
	     else if(form == 2){
	       fomula[recursivenum][front-1].push_monomial(term,1);
	       if(lnum != 2){
		 fomula[recursivenum][front-1].push_monomial("Y",1);
	       }
	     }
	     else if(form == 3){
	       fomula[recursivenum][front-1].push_monomial(term,1);
	       if(lnum != 3){
		 fomula[recursivenum][front-1].push_monomial("Z",1);	      
	       }
	     }
	     else if(form == 4){
	       fomula[recursivenum][front-1].push_monomial(term,1);
	       if(lnum != 4){
		 fomula[recursivenum][front-1].push_monomial("V",1);	      
	       } 

	     }
	     else if(form == 5){
	       fomula[recursivenum][front-1].push_monomial(term,1);
	       if(lnum != 5){
		 fomula[recursivenum][front-1].push_monomial("W",1);	      
	       } 
	     }
	   }
	   else{
	     form = -form;
     	     int coe = -1;
	     std::string term;
	     fomula[recursivenum][front-1].push_monomial(term,1);
	     if(form == 1){
	       if(lnum != 1){
		 for(size_t j = 1; j <= 1; j++){
		   term += "X";
		   fomula[recursivenum][front-1].push_monomial(term,coe);
		   coe *= -1;
		 }
	       }
	     }
	     else if(form == 2){
	       if(lnum != 2){
		 for(size_t j = 1; j <= 1; j++){
		   term += "Y";
		   fomula[recursivenum][front-1].push_monomial(term,coe);
		   coe *= -1;
		 }
	       }
      	     }
	     else if(form == 3){
	       if(lnum != 3){
		 for(size_t j = 1; j <= 1; j++){
		   term += "Z";
		   fomula[recursivenum][front-1].push_monomial(term,coe);
		   coe *= -1;
		 }
	       }
      	     }
	     else if(form == 4){
	       if(lnum != 4){
		 for(size_t j = 1; j <= 1;j++){
		   term += "V";
		   fomula[recursivenum][front-1].push_monomial(term,coe);
		   coe *= -1;
		 }
	       }
	     }
	     else if(form == 5){
	       if(lnum  != 5){
		 for(size_t j = 1; j <= 1; j++){
		   term += "V";
		   fomula[recursivenum][front-1].push_monomial(term,coe);
		   coe *= -1;
		 }
	       }
	     }
	   }
	   outbuf.push_back(front);
	   countsize[recursivenum+1]++;
	 }
	}
      }
     else{
       while(!q[recursivenum].empty()){
	 char front = q[recursivenum].front();
	 q[recursivenum].pop();
	 if(fomula[recursivenum][front-1].getlength() == 0){
	   lf = rule.getleft(front);
	   for(size_t i = 0; i < lf.getsize();i++){
	     q[recursivenum+1].push(lf.getvariable(i));
	     countsize[recursivenum+1]++;
	   }
	   recursiveDecompose(rule,recursivenum+1,lnum);
	   Calculate(rule,recursivenum,front);
	 }
	 else{
	   prun_size++;
	 }
       }
     }
}

void Extract::expandFomula(int size,int extractid){
  fomula.push_back(std::vector<Polynomial>());
  leaf_size.push_back(std::vector<ullint>());
  for(int i = 0; i < size;i++){
    fomula[extractid].push_back(Polynomial());
    leaf_size[extractid].push_back(0);
  }
}

void Extract::Calculate(Rule rule, int recursivenum, int front){
  left lf = rule.getleft(front);
  fomula[recursivenum][front-1].push(fomula[recursivenum+1][lf.getvariable(0)-1]);
  leaf_size[recursivenum][front-1] = leaf_size[recursivenum+1][lf.getvariable(0)-1];
  for(size_t i = 1; i < lf.getsize(); i++){
    fomula[recursivenum][front-1].product(fomula[recursivenum + 1][lf.getvariable(i)-1],(int)order);
    leaf_size[recursivenum][front-1] += leaf_size[recursivenum+1][lf.getvariable(i)-1];
  }
}

