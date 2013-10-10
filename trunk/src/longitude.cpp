#include "longitude.hpp"

longitude::longitude(){
  size = 0;
}

longitude::~longitude(){
  
}

void longitude::setvariable(uchar newvariable){
  //  std::cout << (int)newvariable << std::endl;
  variable.push_back(newvariable);
  size++;
}

char longitude::getvariable(int num){
    return variable[num];
}

uint longitude::getsize(){
  return size;
}
