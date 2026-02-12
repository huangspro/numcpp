#include "../include/numcpp.h"

int main(){
  numcpp a1=numcpp::normal({4, 3, 2, 5}, 0, 1);
  a1.print();
  numcpp b1 = a1.get({1});
  b1.print();
  return 0;
}
