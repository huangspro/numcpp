#ifndef _NUMCPP_
#define _NUMCPP_

#include<iostream>
#include<vector>
#include<cmath>
#include<random>
#include<string>

class numcpp{
public:
  std::vector<int> shape;                                                                           //store the shape of the multiple-dimension array
  int sum_shape = 0;                                                                                    //the sum of shape
  int dimension = 0;                                                                                    //the dimension of the array
  int number = 0;                                                                                       //number of elements in array
  double* data;
  //construntor==========================================================================================================
  numcpp(std::initializer_list<int> s);                                                             //using initializer_list as shape
  numcpp(std::vector<int> s);                                                                       //receive a vector as shape
  numcpp(int size);
  numcpp(){}
  static numcpp array(std::initializer_list<int> s);
  static numcpp array(std::vector<int> s);
  static numcpp Int(std::initializer_list<int> s, int n);                                           //fill the array with integer n
  numcpp(numcpp& other);                                                                            //copier
  static numcpp normal(std::initializer_list<int> s, double mean, double variance);                 //randomly initialize the array, with mean and variance
  static numcpp uniform(std::initializer_list<int> s, double start, double end, std::string type);  //with boundry and data type, excluding end
  static numcpp randn(int size);
  static numcpp arange(double start, double end, double step);                                      //initialize with fixed step
  static numcpp linespace(double start, double end, int size);                                      //initialize with fixed size and range
  static numcpp vector(int size);                                                                   //vector
  static numcpp vector(std::initializer_list<int> data);
  static numcpp matrix(int row, int col);                                                           //matrix
  static numcpp matrix(std::initializer_list<std::initializer_list<int>> data);
  //=====================================================================================================================
  int getIndex(std::initializer_list<int> indexs);                                                  //get index
  numcpp get(std::initializer_list<int> indexs);                                                    //get element by indexs
  bool set(std::initializer_list<int> indexs, double d);                                            //set value by indexs
  void print();                                                                                     //print the whole array, using recursion
  void reshape(std::initializer_list<int> s);                                                       //reshape the array
  void view();                                                                                      //flatten the array
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
  numcpp operator[](std::initializer_list<int> indexs);
  
  //vector and matrix operation
  void t();
  static numcpp matrix_mul(numcpp n1, numcpp n2);
  //tool method
  static bool check_is_shape_same(numcpp, numcpp);

  ~numcpp();
};

#endif
