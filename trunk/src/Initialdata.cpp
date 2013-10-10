#include "Initialdata.hpp"


Initialdata::Initialdata(){
   variable.reserve(1); 
}

void Initialdata::addvariables(std::vector<uchar> newlatitude,uint charsize){
    size = charsize;
    variable.resize(size);
    for(int i = 0; i< size; i++){
        variable[i] = newlatitude[i];
    }
}

void Initialdata::setStart(char newstart){
    start = newstart;
}
char Initialdata::getvariable(uint num){
    return variable[num];
}

char Initialdata::getstart(){
    return start;
}

uint Initialdata::getsize(){
    return size;
}


