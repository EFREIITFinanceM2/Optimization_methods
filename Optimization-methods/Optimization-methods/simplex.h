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
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class simplex
{
public:
    vector<double> c;
    double a[256][256];
    vector<double> b;
    vector<int> base;
    vector<int> ai;
    vector<double> *xResult;
    int rmax,colmax=0;
    int pivotx,pivoty;
    int xnum,snum,anum=0;
    double Z=0;
    bool hasResult=true;
    
    string result = "simplexResult.txt";
    
    simplex(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax,string result);
    void Cpivoty();
    void Dantzig();
    bool isEnd();
    void start();
    bool isTwoPhase()
    {
        return false;
    }
    
};


#endif /* defined(__Optimization_methods__simplex__) */
