//
//  simplex.h
//  Optimization-methods
//
//  Created by ZN-MAC on 14/11/26.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#ifndef __Optimization_methods__simplex__
#define __Optimization_methods__simplex__

#include <stdio.h>
#include <vector>
using namespace std;

class simplex
{
public:
    vector<double> c;
    double a[256][256];
    vector<double> b;
    vector<int> base;
    vector<int> ai;
    int rmax,colmax=0;
    int pivotx,pivoty;
    int xnum,snum,anum=0;
    int Z=0;
    simplex(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax);
    void Cpivoty();
    void Dantzig();
    bool isEnd();
    void start();
    
};


#endif /* defined(__Optimization_methods__simplex__) */
