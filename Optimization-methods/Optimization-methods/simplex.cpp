//
//  simplex.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 14/11/26.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#include "simplex.h"

simplex::simplex(vector<double> c,double a[][256],vector<double> b,int rmax,int colmax){
    this->c = c;
    for (int i=0; i<256;i++) {
        for (int j=0; j<256; j++) {
            this->a[i][j] = a[i][j];
        }
    }
    this->b = b;
    this->rmax=rmax;
    this->colmax= colmax;
    
}

void simplex::Dantzig(double** a, vector<double> b, vector<double> c)
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
    
    for (int j=0; j<colmax; j++) {        //j是列数，i是行数
        for (int i = 0; i<rmax; i++) {
            if (a[i][j]!=0) {
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
    
    
}


    
