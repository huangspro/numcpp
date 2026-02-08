#include "numcpp.h"

//construntor
numcpp::numcpp(std::initializer_list<int> s){
int tem = 0;
  for(int i: s){
    tem += i;
    shape.push_back(i);
  }
  data = new double[tem];
  sum = tem;
  dimension = shape.size();
}
  
//get index
int numcpp::getIndex(std::initializer_list<int> indexs){  
  //check if the indexs are valid
  int sum_tem = 0;
  for(int i:indexs){
    sum_tem += i;
  }
  if(sum_tem > sum)return -1;

  //calculate the index by loop
  int conduct = 1;
  int result = 0;
  for(int i = 0;i<shape.size()-1;i++){
    conduct *= shape[shape.size()-i-1];
    result += (*(indexs.begin() + shape.size()-i-2))*conduct;
  }
  result += *(indexs.begin() + shape.size()-1); //add the last index
  return result;
}
  
//get element by indexs
double numcpp::get(std::initializer_list<int> indexs){  
  int conduct = 1;
  int result = 0;
  for(int i = 0;i<shape.size()-1;i++){
    conduct *= shape[shape.size()-i-1];
    result += (*(indexs.begin() + shape.size()-i-2))*conduct;
  }
  result += *(indexs.begin() + shape.size()-1); //add the last index
  return data[result];
}
  
//set value by indexs
bool numcpp::set(std::initializer_list<int> indexs, double d){
  int tem = getIndex(indexs);
  if(tem == -1)return false;
  else{
    data[getIndex(indexs)] = d;
    return true;
  }
}
  
//print the whole array, using recursion
void numcpp::print(int shape_info){
  
}
  
//operation to elements
static void numcpp::sqrt()
  
~numcpp(){
  delete[] data;
}
