#include "../include/numcpp.h"

int main(){
  numcpp a1=numcpp::normal({4, 3, 2}, 0, 1);
  numcpp a2=numcpp::normal({2, 12}, 0, 1);
  a1.reshape({2, 12});
  a1.print();
  std::cout<<"..."<<a1.shape[12];
  return 0;
}
