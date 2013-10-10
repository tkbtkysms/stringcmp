#include "Rule.hpp"

void Rule::constructRule(std::vector<Initialdata> Id){
    int size = 0;
    int totalsize = 0;
    int intervalsize= 0;
    int presize = 0;
    uchar tmpvariable;
    for(int i = 0; i < Id.size(); i++){
      totalsize += Id[i].getsize()+1;
    }
    setofLeft.resize(totalsize*2);
    form.resize(totalsize*2);
    for(int i = 0;i < Id.size();i++){
        size = Id[i].getsize();
        intervalsize += size+1;
        for(int j = intervalsize*2-2;j >= presize*2; j-=2){
	  form[j] = i+1;
	  form[j+1] = -(i+1);
	  for(int k = size-1; k >= 0; k--){
     	    if((tmpvariable=Id[i].getvariable(k)) % 2 != 0){
	      setofLeft[j].setvariable(tmpvariable + 1);
	      setofLeft[j + 1].setvariable(tmpvariable + 1);
	    }
	    else{
	      setofLeft[j].setvariable(tmpvariable - 1);
	      setofLeft[j + 1].setvariable(tmpvariable -1);
	    }
          }
          setofLeft[j].setvariable(Id[i].getstart());
	  setofLeft[j + 1].setvariable(Id[i].getstart()+1);
	  for(int k = 0; k < size; k++){
            setofLeft[j].setvariable(Id[i].getvariable(k));
	    setofLeft[j+ 1].setvariable(Id[i].getvariable(k));
          }
	  size--;
        }
        presize = intervalsize;
    }
         
    /* Debug
     for(int i = 0; i < setofLeft.size(); i++){
       std::cout <<"form " <<(int)form[i] << " ";
       for(int j = 0; j < setofLeft[i].getsize(); j++){
	 std::cout << "left "<< (int)setofLeft[i].getvariable(j) << " ";
      }
      std::cout << std::endl;
      }
    */
}

longitude Rule::getleft(char num){
  if(num < 0){
    std::cerr << "index is strange."<< std::endl;
    exit(1);
  }
  return setofLeft[num-1];
}

char Rule::getform(char num){
  return form[num -1];
}

int Rule::getsize(){
  return setofLeft.size();
}
