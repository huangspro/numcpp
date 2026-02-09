#include "../include/numcpp.h"

int main(){
  numcpp n({3, 4, 2});
  n.set({1, 2, 1}, 1001);
  numcpp::sin(n);
  std::cout<<numcpp::min(n);;
  return 0;
}
