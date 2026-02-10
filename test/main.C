#include "../include/numcpp.h"

int main(){
  numcpp a1({300, 400, 2}, 0, 100, "int");
  numcpp a2({300, 400, 2}, 0, 300, "int");
  std::cout<<(a1 + 10000).get({0, 2, 2});
  return 0;
}
