#include "../include/numcpp.h"

int main(){
  numcpp a1=numcpp::normal({3, 2, 2}, 0, 1);
  a1.print();
  std::cout<<a1[{0}].dimension<<std::endl<<std::flush;
  a1.get({0}).print();
}
