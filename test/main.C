#include "../include/numcpp.h"

int main(){
  numcpp a1=numcpp::array({3, 2, 3});
  a1.print();
  a1.reshape({2,9});
  a1.print();
  return 0;
}
