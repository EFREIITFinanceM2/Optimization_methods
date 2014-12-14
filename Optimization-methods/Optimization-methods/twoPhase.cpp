//
//  twoPhase.cpp
//  Optimization_methods_hongyu
//
//  Created by hongyu on 14/11/28.
//  Copyright (c) 2014年 hongyu. All rights reserved.
//

#include "twoPhase.h"


twoPhase::twoPhase(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax,string result,readSimplex *read ):simplex(c,a,b,xnum,snum,anum,ai,rmax,colmax,result)
{
    this->read=read;
//result="twoPhaseResult";
}

void twoPhase::calulateP()
{
    double* min=new double[this->ai.size()];
    int* pos = new int[this->ai.size()];
    
    for (int i=0; i<this->ai.size(); i++) {
        min[i]=10000;
    }
    
    for (int j=0; j<this->ai.size(); j++) {
        pos[j]=0;
    }
    
    for (int i=0; i<this->ai.size(); i++) {
        for (int j=0; j<this->colmax; j++) {
            if (a[ai[i]][j]>0) {
                double temp= b[ai[i]]/a[ai[i]][j];
                if (temp<min[i]) {
                    min[i]=temp;
                    pos[i]=j;
                }
            }
        }
    }
    
    for (int i=0; i<this->ai.size(); i++) {
        int temp =1000;
        if (min[i]<temp) {
            temp = min[i];
            this->pivotx=ai[i];
            this->pivoty=pos[i];
        }
    }
    base[this->pivotx]=this->pivoty;
}

bool twoPhase::isEndU(){
    for (int i=0; i<this->rmax; i++) {
        if (base[i]>= this->snum+this->xnum)
            return false;
    }
        return true;
    
}

void twoPhase::calulateU(){
    int temp=0;
    while (!isEndU()&&(temp<1000)) {
        calulateP();
        Dantzig();
        temp++;
    }
    if (temp>=1000) {
        hasResult=false;
    }
    colmax-=anum;
}




