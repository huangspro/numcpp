#ifndef _NUMCPP_
#define _NUMCPP_

#include<iostream>
#include<vector>
#include<cmath>
#include<random>
#include<string>

class numcpp{
public:
  std::vector<int> shape;  //store the shape of the multiple-dimension array
  int sum_shape;                 //the sum of shape
  int dimension;           //the dimension of the array
  int number;              //number of elements in array
  double* data;
  
  //construntor==========================================================================================================
  numcpp(std::initializer_list<int> s);           //using initializer_list as shape
  numcpp(std::vector<int> s);                     //receive a vector as shape
  numcpp(std::initializer_list<int> s, int n);    //fill the array with integer n
  numcpp(numcpp& other);                    //copier
  numcpp(std::initializer_list<int> s, double mean, double variance);    //randomly initialize the array, with mean and variance
  numcpp(std::initializer_list<int> s, double start, double end, std::string type);  //with boundry and data type, excluding end
  //=====================================================================================================================
  int getIndex(std::initializer_list<int> indexs);//get index
  double get(std::initializer_list<int> indexs);//get element by indexs
  bool set(std::initializer_list<int> indexs, double d);//set value by indexs
  void print();//print the whole array, using recursion
  
  //operation to elements================================================================================================
  static void sin(numcpp);
  static void cos(numcpp);
  static void tan(numcpp);
  static void arsin(numcpp);
  static void arcos(numcpp);
  static void artan(numcpp);
  static void sqrt(numcpp);
  static void square(numcpp);
  static void cube(numcpp);
  static void exp(numcpp);
  static void ln(numcpp);
  static void lg(numcpp);
  
  static double sum(numcpp);
  static double ave(numcpp);
  static double max(numcpp);
  static double min(numcpp);
  static double var(numcpp);
  static double standard(numcpp);

  //operator overload, element-wise operation
  numcpp operator+(numcpp other);
  numcpp operator-(numcpp other);
  numcpp operator*(numcpp other);
  numcpp operator/(numcpp other);
  numcpp operator+(double other);
  numcpp operator-(double other);
  numcpp operator*(double other);
  numcpp operator/(double other);
  
  //tool method
  static bool chech_is_shape_same(numcpp, numcpp);

  ~numcpp();
};

#endif
