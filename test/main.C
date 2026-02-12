#include "../include/numcpp.h"

int main(){
  numcpp a1=numcpp::normal({4, 3, 2}, 0, 1);
  std::cout<<a1. number<<std::endl<<std::flush;
  a1.print();
  std::cout<<a1. number<<std::endl<<std::flush;
  a1.reshape({2, 3, 4});
std::cout<<a1. number<<std::endl<<std::flush;
  a1.print();
std::cout<<a1. number<<std::endl<<std::flush;
  return 0;
}
