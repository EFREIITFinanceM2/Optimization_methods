//
//  simplex.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 14/11/26.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved./Users/hongyu/Documents/workspace/Optimization_methods/Optimization-methods/Optimization-methods/simplex.cpp
//

#include "simplex.h"

simplex::simplex(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax){
    this->c = c;
    for (int i=0; i<256;i++) {
        for (int j=0; j<256; j++) {
            this->a[i][j] = a[i][j];
        }
    }
    this->b = b;
    this->rmax=rmax;
    this->colmax= colmax;
    this->xnum = xnum;
    this->snum = snum;
    this->anum = anum;
    this->ai=ai;
    for (int i=xnum; i<=anum+snum;i++ ) {
        base.push_back(i);
    }
    
}
void simplex::Cpivoty()
{
    double *min = new double[this->colmax];
    int *pos = new int[this->colmax];
    int max = 0;
    for (int j=0; j<this->colmax; j++) {
        min[j]=10000;
    }
    
    for (int j=0; j<this->colmax; j++) {
        pos[j]=0;
    }
    
    for (int j=0; j<colmax; j++) {        //j is column，i is row
        for (int i = 0; i<rmax; i++) {
            if (a[i][j] > 0) {
                int temp = b[i]/a[i][j];
                if(temp<min[j]){
                    min[j]=temp;
                    pos[j]=i;
                }
            }
        }
        int temp = min[j]*c[j];
        if (temp>max) {
            max = temp;
            this->pivoty=j;
            this->pivotx=pos[j];
        }
    }
    
    base[this->pivotx]=this->pivoty;

    
}
void simplex::Dantzig()
{
    for (int i=0; i<rmax;i++) {
        for (int j=0; j<colmax; j++) {
            if (i!=this->pivotx) {
                a[i][j]= a[i][j]-(a[i][this->pivoty]/a[this->pivotx][this->pivoty])*a[this->pivotx][j];
            }else{
                a[i][j]= a[i][j]/a[this->pivotx][this->pivoty];
            }
        }
        if (i!=this->pivotx) {
            b[i]=b[i]-b[this->pivotx]*(a[i][this->pivoty]/a[this->pivotx][this->pivoty]);
        }else{
            b[i]=b[i];
        }
    }
    for (int j=0; j<colmax; j++) {
        c[j]=c[j]-(c[this->pivoty]/a[this->pivotx][this->pivoty])*a[this->pivotx][j];
    }
    Z=Z-b[this->pivotx]*(c[this->pivoty]/a[this->pivotx][this->pivoty]);
}

bool simplex::isEnd()
{
    for (int j=0; j<colmax; j++) {
        if (c[j]> 0)
            return false;
    }
    return true;
}

void simplex::start()
{
    while (!isEnd()) {
        Cpivoty();
        Dantzig();
    }
}





    
