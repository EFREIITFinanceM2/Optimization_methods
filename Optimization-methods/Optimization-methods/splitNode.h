//
//  splitNode.h
//  Optimization-methods
//
//  Created by ZN-MAC on 14/12/13.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#ifndef __Optimization_methods__splitNode__
#define __Optimization_methods__splitNode__

#include <stdio.h>
#include <vector>
#include "twoPhase.h"
using namespace std;

class splitNode {
public:
    twoPhase *node;
    splitNode *R=NULL;
    splitNode *L=NULL;
public:
    splitNode(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax,string result, readSimplex *read);
    splitNode();
};

#endif /* defined(__Optimization_methods__splitNode__) */
