#include "../include/numcpp.h"

int main(){
  numcpp a1({3, 4, 2}, 5);
  numcpp a2({3, 4, 2}, 2);
  numcpp a3 = a1 + a2;
  std::cout<<a3.get({1, 1, 1});
  return 0;
}
