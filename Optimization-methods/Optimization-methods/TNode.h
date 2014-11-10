//
//  TNode.h
//  Optimization-methods
//
//  Created by ZN-MAC on 10/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#ifndef __Optimization_methods__TNode__
#define __Optimization_methods__TNode__

#include <stdio.h>
#include <vector>
using namespace std;

class TNode {
public:
    vector<double> x;
    int b=-1;
    vector<double> e;
    int changeI = 0;
    
public:
    TNode();
    TNode(int N,int M);
};

#endif /* defined(__Optimization_methods__TNode__) */
