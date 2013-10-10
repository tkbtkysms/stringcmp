#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Latitude.hpp"
#include "Rule.hpp"
#include "left.hpp"
#include "Extract.hpp"
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <string>
#include <time.h>
#include <sys/time.h>

int main(int argc, char** argv) {
    std::vector<Latitude> lats1,lats2;    
    Extract ext;
    Rule rule1,rule2;
    int lats_number1 = 0;
    int extractnum = 1;
    int lats_number2 = 0;
    int order = 1;
    std::string str_of_num;
    clock_t s,e;
    if(argc != 7){
      std::cerr << "引数は7つです。" << std::endl;
      exit(1);
    }
    std::ifstream ifs(argv[1]);
    std::ifstream ifs2(argv[2]);
    str_of_num = argv[3];
    std::istringstream isst1(str_of_num);
    isst1 >> lats_number1;
    str_of_num = argv[4];
    std::istringstream isst2(str_of_num);
    isst2 >> lats_number2;
    str_of_num = argv[5];
    std::istringstream isst3(str_of_num);
    isst3 >> extractnum;
    str_of_num = argv[6];
    std::istringstream isst4(str_of_num);
    isst4 >> order;
    if(!ifs){
      std::cerr << "入力ファイルがありません。" << std::endl;
      exit(1);
    }
      std::string str;
  int num;
  char c;
  int lats_size1 = 0;
  int start[5];
  int odd = 0;
  int even = 0;
  int diff[5];
  bool eo[5];
  start[0] = 1;
  for(int i = 0; i < 5;i++){
    diff[i] = 0;
    start[i] = 0;
    eo[i] = true;
  }
  start[0] = 1;
  int diff_sum = 0;
  int allstart = 0;
  std::vector<int> rule_size;
  std::vector<uchar> r;
  std::vector<std::vector<uchar> > r2;
  s = clock();
  while(getline(ifs,str)){
    r2.push_back(std::vector<uchar>());
    std::istringstream isst(str);
    rule_size.push_back(0);
    while(!isst.eof()){
      isst >> num;
      if(num%2 == 0){
	even++;
      }
      else{
	odd++;
      }
      r2[lats_size1].push_back((uchar)num);
      rule_size[lats_size1]++;
    }
    //    rule_size[lats_size1]++;
    if(odd > even){
      eo[lats_size1] = true;
      diff[lats_size1] = (odd - even);
    }
    else{
      eo[lats_size1] = false;
      diff[lats_size1] = (even - odd);
    }
    even = 0;
    odd = 0;
    for(int i = 0; i < rule_size[lats_size1];i++){
      std::cout << (int)r2[lats_size1][i] << " ";
    }
    std::cout << std::endl;
    //std::cout << rule_size[lats_size1] << std::endl;
    lats_size1++;
    lats1.resize(lats_size1);
    start[lats_size1] += (rule_size[lats_size1 - 1]*2 + 2 + start[lats_size1 -1]);
    r.clear();
  }
  for(int i = 0; i < lats_size1;i++){
    for(int j = 0 ;j < rule_size[i];j++){
      for(int k = 0; k < lats_size1;k++){
	if(r2[i][j] >= start[k]){
	  r2[i][j] += 2*diff[k];
	}
      }		   
    }
  }
  int sum = 0;
   std::cout << std::endl;
  for(int i = 0;i < lats_size1;i++){
    if(i > 0){
      sum += 2*diff[i-1];
      //std::cout <<"sum"<< sum << std::endl;
      if(sum != 0){
	start[i] += sum;
      }
    }
    for(int j = 0;j < diff[i];j++){
      if(eo[i]){
	r.push_back((uchar)start[i]+1);
      }
      else{
	r.push_back((uchar)start[i]);
      }
    }
    for(int j = 0; j < rule_size[i];j++){
      r.push_back(r2[i][j]);
    }
    rule_size[i] += diff[i];
    lats1[i].addvariables(r,rule_size[i]);
    //    std::cout << "start"<< start[i] << std::endl;
    lats1[i].setStart(start[i]);
    r.clear();
  }
  for(int i = 0; i < lats_size1; i++){
    for(int j = 0; j < lats1[i].getsize();j++){
      std::cout << (int)lats1[i].getvariable(j) << " ";
    }
    std::cout << std::endl;
  }
    ifs.close();

 int lats_size2 = 0;
  odd = 0;
  even = 0;
  for(int i = 0; i < 5;i++){
    diff[i] = 0;
    start[i] = 0;
    eo[i] = true;
  }
  start[0] = 1;
  diff_sum = 0;
  allstart = 0;
  r.clear();
  r2.clear();
  rule_size.clear();
  s = clock();
  // std::cout << "ab"<<std::endl;
  while(getline(ifs2,str)){
    r2.push_back(std::vector<uchar>());
    std::istringstream isst(str);
    rule_size.push_back(0);
    while(!isst.eof()){
      isst >> num;
      if(num%2 == 0){
	even++;
      }
      else{
	odd++;
      }
      r2[lats_size2].push_back((uchar)num);
      rule_size[lats_size2]++;
    }
    //    rule_size[lats_size1]++;
    if(odd > even){
      eo[lats_size2] = true;
      diff[lats_size2] = (odd - even);
    }
    else{
      eo[lats_size2] = false;
      diff[lats_size2] = (even - odd);
    }
    even = 0;
    odd = 0;
    for(int i = 0; i < rule_size[lats_size2];i++){
      std::cout << (int)r2[lats_size2][i] << " ";
    }
    std::cout << std::endl;
    //std::cout << rule_size[lats_size1] << std::endl;
    lats_size2++;
    lats2.resize(lats_size2);
    start[lats_size2] += (rule_size[lats_size2 - 1]*2 + 2 + start[lats_size2 -1]);
    r.clear();
  }
  for(int i = 0; i < lats_size2;i++){
    for(int j = 0 ;j < rule_size[i];j++){
      for(int k = 0; k < lats_size2;k++){
	if(r2[i][j] >= start[k]){
	  r2[i][j] += 2*diff[k];
	}
      }		   
    }
  }
  sum = 0;
  std::cout << std::endl;
  for(int i = 0;i < lats_size2;i++){
    if(i > 0){
      sum += 2*diff[i-1];
      //std::cout <<"sum"<< sum << std::endl;
      if(sum != 0){
	start[i] += sum;
      }
    }
    for(int j = 0;j < diff[i];j++){
      if(eo[i]){
	r.push_back((uchar)start[i]+1);
      }
      else{
	r.push_back((uchar)start[i]);
      }
    }
    for(int j = 0; j < rule_size[i];j++){
      r.push_back(r2[i][j]);
    }
    rule_size[i] += diff[i];
    lats2[i].addvariables(r,rule_size[i]);
    //    std::cout << "start"<< start[i] << std::endl;
    lats2[i].setStart(start[i]);
    r.clear();
  }
    
  for(int i = 0; i < lats_size2; i++){
    for(int j = 0; j < lats2[i].getsize();j++){
      std::cout << (int)lats2[i].getvariable(j) << " ";
    }
    std::cout << std::endl;
  }
  //std::cout << lats_size2 << std::endl;
    ifs2.close();
    rule1.constructRule(lats1);
    rule2.constructRule(lats2);
    if(lats_number1 > lats_size1){
      std::cerr << "展開する式の番号がおかしいです。式番号："<< lats_number1 << "式の数:"<< lats_size1+1<< std::endl;
      exit(1);
    }
    if(lats_number2 > lats_size2){
      std::cerr << "展開する式の番号がおかしいです。式番号："<< lats_number2 << "式の数:"<< lats_size2+1<< std::endl;
      exit(1);
    }
    ext.CalcMilnor(lats1[lats_number1 - 1],lats2[lats_number2-1],rule1,rule2,extractnum,order,lats_number1,lats_number2);
    e = clock();
    std::cout << "Calculating time:"<<(double)(e - s)/CLOCKS_PER_SEC << std::endl;
    return 0;
}



