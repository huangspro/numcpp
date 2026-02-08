#include "numcpp.h"

int main(){
  numcpp n({3, 4, 2});
  n.set({1, 2, 1}, 1001);
  std::cout<<n.get({1, 2, 1});
  return 0;
}
