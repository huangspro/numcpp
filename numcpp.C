#include "numcpp.h"

//construntor
numcpp::numcpp(std::initializer_list<int> s){
  int tem = 0;
  int temm = 1;
  for(int i: s){
    tem += i;
    temm *= i;
    shape.push_back(i);
  }
  data = new double[tem];
  sum = tem;
  dimension = shape.size();
  number = temm;
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
static void sin(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::sin(data[i]);
  }
}

static void cos(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::cos(data[i]);
  }
}

static void tan(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::tan(data[i]);
  }
}

static void arsin(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::asin(data[i]);
  }
}

static void arcos(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::acos(data[i]);
  }
}

static void artan(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::atan(data[i]);
  }
}

static void sqrt(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::sqrt(data[i]);
  }
}

static void square(numcpp){
  for(int i=0;i<number;i++){
    data[i] = data[i] * data[i];
  }
}

static void cube(numcpp){
  for(int i=0;i<number;i++){
    data[i] = data[i] * data[i] * data[i];
  }
}

static void exp(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::exp(data[i]);
  }
}

static void ln(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::log(data[i]);
  }
}

static void lg(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::log10(data[i]);
  }
}

static void sum(numcpp){
  double result = 0;
  for(int i=0;i<number;i++){
    result += data[i];
  }
  data[0] = result;
}

static void ave(numcpp){
  double sum = 0;
  for(int i=0;i<number;i++){
    sum += data[i];
  }
  data[0] = sum / number;
}

static void max(numcpp){
  double max_val = data[0];
  for(int i=1;i<number;i++){
    if(data[i] > max_val) max_val = data[i];
  }
  data[0] = max_val;
}

static void min(numcpp){
  double min_val = data[0];
  for(int i=1;i<number;i++){
    if(data[i] < min_val) min_val = data[i];
  }
  data[0] = min_val;
}

static void var(numcpp){
  double sum = 0, mean, variance = 0;
  for(int i=0;i<number;i++){
    sum += data[i];
  }
  mean = sum / number;
  for(int i=0;i<number;i++){
    variance += (data[i] - mean) * (data[i] - mean);
  }
  data[0] = variance / number;
}

static void standard(numcpp){
  double sum = 0, mean, variance = 0;
  for(int i=0;i<number;i++){
    sum += data[i];
  }
  mean = sum / number;
  for(int i=0;i<number;i++){
    variance += (data[i] - mean) * (data[i] - mean);
  }
  data[0] = std::sqrt(variance / number);
}

static void floor(numcpp){
  for(int i=0;i<number;i++){
    data[i] = std::floor(data[i]);
  }
}
  
numcpp::~numcpp(){
  delete[] data;
}
