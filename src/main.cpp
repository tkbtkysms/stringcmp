#include <fstream>
#include "Extract.hpp"
#include "Extract_lhm.hpp"
#include "Extract_ex.hpp"
#include <sstream>
#include <sys/time.h>


void read_input_data(std::vector<Initialdata> &Id,Rule &rule1,std::ifstream &ifs){
  int num;
  int Id_size = 0;
  int odd;
  int even;
  std::vector<int> start;
  std::vector<int> diff;
  std::vector<int> rule_size;
  std::vector<uchar> r;
  std::vector<std::vector<uchar> > r2;
  std::string str;
  std::stringstream sst;
  std::cout << "original Initial data" << std::endl;

  start.push_back(1);
  
  while(getline(ifs,str)){
    
    even = 0;
    odd = 0;
    start.push_back(0);
    diff.push_back(0);
    rule_size.push_back(0);
    r2.push_back(std::vector<uchar>());
    sst << str;

    while(!sst.eof()){
      sst >> num;
      r2[Id_size].push_back((uchar)num);
      rule_size[Id_size]++;
    }

    sst.clear();
    start[Id_size + 1] = start[Id_size] + 2*(rule_size[Id_size] + 1);
    
    for(int i = 0; i < rule_size[Id_size]; i++){
      if(start[Id_size] <= r2[Id_size][i] && r2[Id_size][i] < start[Id_size + 1]){
	if(r2[Id_size][i] % 2 == 0){
	  even++;
	}
	else{
	  odd++;
	}
      }
    }
    diff[Id_size] = odd - even;

    for(int i = 0; i < rule_size[Id_size];i++){
      std::cout << (int)r2[Id_size][i] << " ";
    }
    std::cout << std::endl;
    Id_size++;
    Id.resize(Id_size);
    r.clear();
  }
  for(int i = 0; i < Id_size;i++){
    for(int j = 0 ;j < rule_size[i];j++){
      for(int k = 0; k < Id_size;k++){
	if(r2[i][j] >= start[k]){
	  r2[i][j] += 2*abs(diff[k]);
	}
      }		   
    }
  }
  int sum = 0;
  std::cout << std::endl;
  std::cout << "transformed Initial data" << std::endl;
  for(int i = 0;i < Id_size;i++){
    if(i > 0){
      sum += 2*abs(diff[i-1]);
      if(sum != 0){
	start[i] += sum;
      }
    }
    for(int j = 0;j < abs(diff[i]);j++){
      if(diff[i] < 0){
	r.push_back((uchar)start[i]);
      }
      else{
	r.push_back((uchar)start[i] + 1);
      }
    }
    for(int j = 0; j < rule_size[i];j++){
      r.push_back(r2[i][j]);
    }
    rule_size[i] += abs(diff[i]);
    Id[i].addvariables(r,rule_size[i]);
    Id[i].setStart(start[i]);
    r.clear();
  }
    
  for(int i = 0; i < Id_size; i++){
    for(int j = 0; j < Id[i].getsize();j++){
      std::cout << (int)Id[i].getvariable(j) << " ";
    }
    std::cout << std::endl;
  }
     
  std::cout << std::endl;
  ifs.close();
  rule1.constructRule(Id);
}

void printerror(){
  std::cerr << "The command is like next senetense." << std::endl;
    std::cerr << "./milnor od nel set1 set2 Fl1 Fl2 Extnum order" << std::endl;
    std::cerr << "od: o:We Calculate one Milnor invariant. Then set2 is not needed"  << std::endl;
    std::cerr << "    d: Calculating the difference of two Milnor invariant." << std::endl;
    std::cerr << "nel: n: normal Milnor invariant." <<std::endl; 
    std::cerr << "     e: We use e^x in Maclaurin expansion." << std::endl;
    std::cerr << "     l: we calculate the Milnor invariant link homotopy."  << std::endl;
    std::cerr << "set1 and set2: First longitude files.Please read README to know How to make this file." << std::endl;
    std::cerr << "FL1 and Fl2: We use FL1(FL2)-th Firstlongitude in set1(set2)." << std::endl;
    std::cerr << "Extnum: the number of Magnus expansion." << std::endl;
    std::cerr << "order: The maximum order in Polynomial." << std::endl;
}

int main(int argc, char** argv) {
  
  clock_t s,e;
  s = clock();
  int Id_num1 = 0;
  int Id_num2 = 0;
  int extractnum = 1;
  int order = 1;
  std::ifstream ifs1, ifs2;
  std::stringstream sst;
  std::string str;
  std::string od;
  std::string nel;
  int ac = 1;
  if(argc != 7){
    if(argc != 9){
      std::cerr << "The number of argument is 7 or 9." << std::endl;
      printerror();
      exit(1);
    }
  }
  od = argv[ac++];
  if(od.length() != 1 || (od != "o" && od != "d")){
    std::cerr << "2nd argumet is o or d." << std::endl;
    printerror();
    exit(1);
  }
  if(od  == "o"){
    if(argc != 7){
      std::cerr << "The number of argument is 7 using option o." << std::endl;
      printerror();
      exit(1);
    }
  }
  else{
    if(argc != 9){
      std::cerr << "The number of argument is 9 using option d." << std::endl;
      printerror();
      exit(1);
    }
  }
  nel = argv[ac++];
  if(nel.length() != 1 || (nel != "n" && nel != "e" && nel != "l")){
    std::cerr << "3rd argumet is n,e or l." << std::endl;
    printerror();
    exit(1);
  }
  ifs1.open(argv[ac++]);
  if(!ifs1){
    std::cerr << "The file" <<argv[ac - 1]<< " is not found." << std::endl;
    printerror();
    exit(1);
  }
  if(od == "d"){
    ifs2.open(argv[ac++]);
    if(!ifs2){
      std::cerr << "The file" << argv[ac - 1] << " is not found." << std::endl;
      printerror();
      exit(1);
    }
  }
  str = argv[ac++];
  sst << str;
  sst >> Id_num1;
  sst.clear();
  if(od == "d"){
    str = argv[ac++];
    sst << str;
    sst >> Id_num2;
    sst.clear();
  }
  str = argv[ac++];
  sst << str;
  sst >> extractnum;
  sst.clear();
  str = argv[ac];
  sst << str;
  sst >> order;
  sst.clear();
  Rule rule1,rule2;
  std::vector<Initialdata> Id1,Id2;
  read_input_data(Id1,rule1,ifs1);
  if(Id_num1 > Id1.size() ){
    std::cerr << "Initial data number is "<<  Id_num1 << ". The number of initial data:"<< Id1.size()  << std::endl;
    exit(1);
  }
  if(od == "d"){
    read_input_data(Id2,rule2,ifs2);
    if(Id_num2 > Id2.size()){
      std::cerr << "Initial data number is "<<  Id_num2 << ". The number of initial data:"<< Id2.size() << std::endl;
      exit(1);
    }
    if(nel == "n"){
      Extract ext;
      ext.sub(Id1[Id_num1 - 1],Id2[Id_num2 - 1],rule1,rule2,extractnum,order);
    }
    else if(nel == "e"){
      Extract_ex ext;
      ext.sub(Id1[Id_num1 - 1],Id2[Id_num2 - 1],rule1,rule2,extractnum,order);
    }
    else{
      Extract_lhm ext;
      ext.sub(Id1[Id_num1 - 1],Id2[Id_num2 - 1],rule1,rule2,extractnum,order,Id_num1,Id_num2);
    }
  }
  else{
    if(nel == "n"){
      Extract ext;
      ext.CalcMilnor(Id1[Id_num1 - 1],rule1,extractnum,order);
    }
    else if(nel == "e"){
      Extract_ex ext;
      ext.CalcMilnor(Id1[Id_num1 - 1],rule1,extractnum,order);
    }
    else{
      Extract_lhm ext;
      ext.CalcMilnor(Id1[Id_num1 - 1],rule1,extractnum,order,Id_num1);
    }
  }
  
  e = clock();
  std::cout << "Calculating time:"<<(double)(e - s)/CLOCKS_PER_SEC << std::endl;
  return 0;
}

