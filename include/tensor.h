#ifndef _TENSOR_H_
#define _TENSOR_H_

#include "numcpp.h"

class tensor{
public:
  numcpp data, grad; //one is for storing data, the other one is for gradient
  tensor()
};

#endif
