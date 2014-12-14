//
//  changeForm.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 14/11/26.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#include "changeForm.h"

readSimplex* changeForm::change(readSimplex* readb){
    readSimplex* read=new readSimplex(readb);
    double temp;
    vector<int> ai;
    temp=read->c.back();
    read->c.pop_back();
    for (int i=0; i<read->symbol.size(); i++) {
        if (read->symbol[i]=='L') {
            read->a[i][read->colmax+i]=1;
        }
        else{
            read->a[i][read->colmax+i]=-1;
            ai.push_back(i);
        }
        read->c.push_back(0);
    }
    read->colmax+=read->symbol.size();
    read->snum=read->symbol.size();
    for (int i=0; i<ai.size(); i++) {
        read->a[ai[i]][read->colmax+i]=1;
        read->c.push_back(0);
    }
    read->colmax+=ai.size();
    read->anum=ai.size();
    read->c.push_back(temp);
    read->ai=ai;
    return read;
}