//
//  readSimplex.h
//  Optimization-methods
//
//  Created by ZN-MAC on 14/11/28.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#ifndef __Optimization_methods__readSimplex__
#define __Optimization_methods__readSimplex__

#include <stdio.h>
#include "read.h"

class readSimplex:public view
{
public:
    int xnum = 0;
    int snum = 0;
    int anum = 0;
    int colmax = 0;
    int rmax = 0;
    vector<char> symbol;
    vector<int> ai;
    void read();
    readSimplex(string myAdress):view(myAdress){}
};


#endif /* defined(__Optimization_methods__readSimplex__) */
