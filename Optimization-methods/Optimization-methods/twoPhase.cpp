//
//  twoPhase.cpp
//  Optimization_methods_hongyu
//
//  Created by hongyu on 14/11/28.
//  Copyright (c) 2014年 hongyu. All rights reserved.
//

#include "twoPhase.h"

void twoPhase::calulateP()
{
    double min[this->ai.size()];
    int pos[this->ai.size()];
    
    for (int i=0; i<this->ai.size(); i++) {
        min[i]=10000;
    }
    
    for (int j=0; j<this->colmax; j++) {
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
            this->pivotx=i;
            this->pivoty=pos[i];
        }
    }
}

bool twoPhase::isEndU(){
    for (int i=0; i<this->rmax; i++) {
        if (base[i]>= this->snum+this->xnum)
            return false;
    }
        return true;
    
}

void twoPhase::calulateU(){
    while (!isEndU()) {
        calulateP();
        Dantzig();
    }
    colmax-=anum;
}




