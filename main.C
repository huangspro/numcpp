#include "numcpp.h"

int main(){
  numcpp<int> n({3, 4, 2});
  std::cout<<n.get({1, 2, 1});
  return 0;
}
