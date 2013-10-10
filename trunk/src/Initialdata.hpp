#include<string.h>
#include<vector>
#include<iostream>

typedef unsigned char uchar;
typedef unsigned int uint;

class Initialdata{
private:
    std::vector<uchar> variable;
    uint size;
    char start;
public:
private:
public:
  void addvariables(std::vector<uchar> newlatitude,uint charsize);
    void setStart(char newstart);
    char getvariable(uint num);
    char getstart();
    uint getsize();
    Initialdata();
};
