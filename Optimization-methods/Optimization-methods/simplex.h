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
    int rmax,colmax=0;
    int pivotx,pivoty;
    simplex(vector<double> c,double a[][256],vector<double> b,int rmax,int colmax);
    void Dantzig(double** a,vector<double> b,vector<double> c);
    
};


#endif /* defined(__Optimization_methods__simplex__) */
