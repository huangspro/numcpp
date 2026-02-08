#ifndef _NUMCPP_
#define _NUMCPP_

#include<iostream>
#include<vector>
#include<cmath>


class numcpp{
public:
  std::vector<int> shape;  //store the shape of the multiple-dimension array
  int sum;                 //the sum of shape
  int dimension;           //the dimension of the array
  double* data;
  
  //construntor==========================================================================================================
  numcpp(std::initializer_list<int> s);
  
  //=====================================================================================================================
  int getIndex(std::initializer_list<int> indexs);//get index
  double get(std::initializer_list<int> indexs);//get element by indexs
  bool set(std::initializer_list<int> indexs, double d);//set value by indexs
  void print(int shape_info);//print the whole array, using recursion
  
  //operation to elements================================================================================================
  static void sqrt();
  static void sin();
  static void cos();
  static void tan();
  static void sqrt();
  static void sin();
  static void sqrt();
  static void sin();
  ~numcpp(){
    delete[] data;
  }
};

#endif
