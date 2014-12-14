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
    readSimplex(readSimplex *read):view(read->myAdress)
    {
        this->xnum=read->xnum;
        this->snum=read->snum;
        this->anum=read->anum;
        this->colmax=read->colmax;
        this->rmax=read->rmax;
        this->symbol=read->symbol;
        this->ai=read->ai;
        this->c=read->c;
        this->d=read->d;
        this->tempar=read->tempar;
        this->ta=read->ta;
        this->myAdress=read->myAdress;
        for (int i=0; i<this->rmax; i++) {
            for (int j=0; j<this->colmax; j++) {
                this->a[i][j]=read->a[i][j];
            }
        }
    }
};


#endif /* defined(__Optimization_methods__readSimplex__) */
