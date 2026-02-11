#include "../include/numcpp.h"

//construntor
numcpp::numcpp(std::initializer_list<int> s){
  int tem = 0;
  int temm = 1;
  for(int i: s){
    tem += i;
    temm *= i;
    shape.push_back(i);
  }
  data = new double[temm];
  sum_shape = tem;
  dimension = shape.size();
  number = temm;
}
numcpp::numcpp(std::vector<int> s){
  int tem = 0;
  int temm = 1;
  for(int i: s){
    tem += i;
    temm *= i;
    shape.push_back(i);
  }
  data = new double[temm];
  sum_shape = tem;
  dimension = shape.size();
  number = temm;
}

numcpp numcpp::array(std::initializer_list<int> s){
  numcpp newone(s);
  return newone;
} 

numcpp numcpp::array(std::vector<int> s){
  numcpp newone(s);
  return newone;
} 

numcpp numcpp::Int(std::initializer_list<int> s, int n){
  numcpp newone(s);
  for(int i=0;i<newone.number;i++)newone.data[i] = n;
  return newone;
}

numcpp::numcpp(numcpp& other){
  this->shape = other.shape;
  this->number = other.number;
  this->sum_shape = other.sum_shape;
  this->dimension = other.dimension;
  data = new double[number];
  for(int i=0;i<number;i++)this->data[i] = other.data[i];
}

numcpp numcpp::normal(std::initializer_list<int> s, double mean, double variance){
  //seed random
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> distrib(mean, variance);
  numcpp newone(s);
  for(int i=0;i<newone.number;i++)newone.data[i] = distrib(gen);
  return newone;
}

numcpp numcpp::uniform(std::initializer_list<int> s, double start, double end, std::string type){
  //seed random
  std::random_device rd;
  std::mt19937 gen(rd());
  numcpp newone(s);
  
  if(type == "int"){
    std::uniform_int_distribution<int> distrib(start, end);
    for(int i=0;i<newone.number;i++)newone.data[i] = (double)distrib(gen);
  }else{
    std::uniform_real_distribution<double> distrib(start, end);
    for(int i=0;i<newone.number;i++)newone.data[i] = distrib(gen);
  }
  return newone;
}

numcpp randn(int size){
  numcpp newone();
} 

numcpp arange(double start, double end, double step){
  numcpp newone();
} 

numcpp linespace(double start, double end, int size){
  numcpp newone();
} 

//get index
int numcpp::getIndex(std::initializer_list<int> indexs){  
  //check if the indexs are valid
  int sum_tem = 0;
  for(int i:indexs){
    sum_tem += i;
  }
  if(sum_tem > sum_shape)return -1;

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
//according to the formula
void numcpp::print(){
  std::vector<int> prepare;
  int tem = shape[shape.size()-1];
  for(int i=0;i<dimension-1;i++){
    prepare.push_back(tem);
    tem = (tem + 2) * shape[shape.size()-i-2];
  }
  prepare.push_back(tem);std::cout<<tem<<std::endl;
  std::string result = "";
  for(int i=0;i<number;i++){
    result += "#";
  }
  
  for(int i=0;i<dimension;i++){
    int temm = result.length();
    result += "]" ;
    for(int ii=temm-1;ii>=0;ii--){  //operate reversely
      if(ii==0)result.insert(0, "[");
      else{
        if(ii%prepare[i] == 0)result.insert(ii, "][");
      }
    }
  }
  int temmm = result.length();
  int index = --number;
  for(int i=temmm-1;i>=0;i--){
    if(result[i] == '#'){
      result.replace(i, 1, " " + std::to_string(data[index]) + " ");
      index --;
    } 
  }
  std::cout<<result<<std::flush;
}

//================================================================================================

void numcpp::sin(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::sin(n.data[i]);
  }
}

void numcpp::cos(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::cos(n.data[i]);
  }
}

void numcpp::tan(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::tan(n.data[i]);
  }
}

void numcpp::arsin(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::asin(n.data[i]);
  }
}

void numcpp::arcos(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::acos(n.data[i]);
  }
}

void numcpp::artan(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::atan(n.data[i]);
  }
}

void numcpp::sqrt(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::sqrt(n.data[i]);
  }
}

void numcpp::square(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = n.data[i] * n.data[i];
  }
}

void numcpp::cube(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = n.data[i] * n.data[i] * n.data[i];
  }
}

void numcpp::exp(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::exp(n.data[i]);
  }
}

void numcpp::ln(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::log(n.data[i]);
  }
}

void numcpp::lg(numcpp n){
  for(int i=0;i<n.number;i++){
    n.data[i] = std::log10(n.data[i]);
  }
}

double numcpp::sum(numcpp n){
  double result = 0;
  for(int i=0;i<n.number;i++){
    result += n.data[i];
  }
  return result;
}

double numcpp::ave(numcpp n){
  double sum = 0;
  for(int i=0;i<n.number;i++){
    sum += n.data[i];
  }
  return sum / n.number;
}

double numcpp::max(numcpp n){
  double max_val = n.data[0];
  for(int i=1;i<n.number;i++){
    if(n.data[i] > max_val) max_val = n.data[i];
  }
  return max_val;
}

double numcpp::min(numcpp n){
  double min_val = n.data[0];
  for(int i=1;i<n.number;i++){
    if(n.data[i] < min_val) min_val = n.data[i];
  }
  return min_val;
}

double numcpp::var(numcpp n){
  double sum = 0, mean, variance = 0;
  for(int i=0;i<n.number;i++){
    sum += n.data[i];
  }
  mean = sum / n.number;
  for(int i=0;i<n.number;i++){
    variance += (n.data[i] - mean) * (n.data[i] - mean);
  }
  return variance / n.number;
}

double numcpp::standard(numcpp n){
  double sum = 0, mean, variance = 0;
  for(int i=0;i<n.number;i++){
    sum += n.data[i];
  }
  mean = sum / n.number;
  for(int i=0;i<n.number;i++){
    variance += (n.data[i] - mean) * (n.data[i] - mean);
  }
  return std::sqrt(variance / n.number);
}


bool numcpp::chech_is_shape_same(numcpp n1, numcpp n2){
  if(n1.shape.size() != n2.shape.size())return false;
  for(int i=0;i<n1.shape.size();i++){
    if(n1.shape[i] != n2.shape[i])return false;
  }
  return true;
}

numcpp numcpp::operator+(numcpp other){
  numcpp newone(other.shape);
  if(chech_is_shape_same(*(this), other)){
    for(int i=0;i<this->number;i++){
      newone.data[i] = this->data[i] + other.data[i];
    }
  }
  return newone;
}

numcpp numcpp::operator-(numcpp other){
  numcpp newone(other.shape);
  if(chech_is_shape_same(*(this), other)){
    for(int i=0;i<this->number;i++){
      newone.data[i] = this->data[i] - other.data[i];
    }
  }
  return newone;
}

numcpp numcpp::operator*(numcpp other){
  numcpp newone(other.shape);
  if(chech_is_shape_same(*(this), other)){
    for(int i=0;i<this->number;i++){
      newone.data[i] = this->data[i] * other.data[i];
    }
  }
  return newone;
}

numcpp numcpp::operator/(numcpp other){
  numcpp newone(other.shape);
  if(chech_is_shape_same(*(this), other)){
    for(int i=0;i<this->number;i++){
      if(other.data[i] == 0)throw "error: divided by 0";
      newone.data[i] = this->data[i] / other.data[i];
    }
  }
  return newone;
}
numcpp numcpp::operator+(double other){
  numcpp newone(this->shape);
  for(int i=0;i<this->number;i++){
      newone.data[i] = this->data[i] + other;
  }
  return newone;
}

numcpp numcpp::operator-(double other){
  numcpp newone(this->shape);
  for(int i=0;i<this->number;i++){
      newone.data[i] = this->data[i] - other;
  }
  return newone;
}

numcpp numcpp::operator*(double other){
  numcpp newone(this->shape);
  for(int i=0;i<this->number;i++){
      newone.data[i] = this->data[i] * other;
  }
  return newone;
}

numcpp numcpp::operator/(double other){
  numcpp newone(this->shape);
  for(int i=0;i<this->number;i++){
      if(other == 0)throw "error: divided by 0";
      newone.data[i] = this->data[i] / other;
  }
  return newone;
}
numcpp::~numcpp(){
  delete[] data;
}
