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
  int number;              //number of elements in array
  double* data;
  
  //construntor==========================================================================================================
  numcpp(std::initializer_list<int> s);
  
  //=====================================================================================================================
  int getIndex(std::initializer_list<int> indexs);//get index
  double get(std::initializer_list<int> indexs);//get element by indexs
  bool set(std::initializer_list<int> indexs, double d);//set value by indexs
  void print(int shape_info);//print the whole array, using recursion
  
  //operation to elements================================================================================================
  static void sin(numcpp);
  static void cos(numcpp);
  static void tan(numcpp);
  static void sum(numcpp);
  static void ave(numcpp);
  static void max(numcpp);
  static void min(numcpp);

  ~numcpp();
};

#endif
