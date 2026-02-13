#include "../include/numcpp.h"

int main(){
  numcpp a1=numcpp::normal({4, 3, 2}, 0, 1);
  a1.print();
  a1[{0, 1}].print();
}