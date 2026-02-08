#ifndef _NUMCPP_
#define _NUMCPP_

#include<iostream>
#include<vector>

template <typename T>
class numcpp{
public:
  std::vector<int> shape;  //store the shape of the multiple-dimension array
  int sum;                 //the sum of shape
  T* data;
  
  //construntor
  numcpp(std::initializer_list<int> s){
    int tem = 0;
    for(int i: s){
      tem += i;
      shape.push_back(i);
    }
    data = new T[tem];
    sum = tem;
  }
  
  //datainput element by index
  T get(std::initializer_list<int> indexs){
    int conduct = 1;
    int result = 0;
    for(int i = 0;i<shape.size()-1;i++){
      conduct *= shape[shape.size()-i-1];
      result += (*(indexs.begin() + shape.size()-i-2))*conduct;
    }
    result += *(indexs.begin() + shape.size()-1);
    return result;
  }
  
  ~numcpp(){
    delete[] data;
  }
};

#endif
