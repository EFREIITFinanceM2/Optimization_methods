//
//  twoPhase.h
//  Optimization_methods_hongyu
//
//  Created by hongyu on 14/11/28.
//  Copyright (c) 2014年 hongyu. All rights reserved.
//

#ifndef __Optimization_methods_hongyu__twoPhase__
#define __Optimization_methods_hongyu__twoPhase__

#include <stdio.h>
#include "simplex.h"

class twoPhase:public simplex
{
public:
    twoPhase();
    twoPhase(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax,string result);
    void calulateP();
    bool isEndU();
    void calulateU();
    bool isTwoPhase()
    {
        return true;
    }

    
};

#endif /* defined(__Optimization_methods_hongyu__twoPhase__) */
