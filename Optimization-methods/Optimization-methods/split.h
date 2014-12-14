//
//  split.h
//  Optimization-methods
//
//  Created by ZN-MAC on 14/12/3.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#ifndef __Optimization_methods__split__
#define __Optimization_methods__split__

#include <stdio.h>
#include "twoPhase.h"
#include "readSimplex.h"
#include "splitNode.h"
#include "changeForm.h"
//#include <stdlib.h>
using namespace std;
class split {
    double zMax;
    double zMin=-100000;
    int size=0;
    splitNode* splitTree;
    int number=0;
    twoPhase *result=0;
    
public:
    split(readSimplex *read);
    void search(splitNode* node);
    bool createChildren(splitNode *node);
    bool isINT(double i);
    void start();
    char*itoa(int num,char*str,int radix)
    {
        char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        unsigned unum;
        int i=0,j,k;
        
        if(radix==10&&num<0)
        {
            unum=(unsigned)-num;
            str[i++]='-';
        }
        else unum=(unsigned)num;
        
        do{
            str[i++]=index[unum%(unsigned)radix];
            unum/=radix;
        }while(unum);
        str[i]='\0';
        if(str[0]=='-')k=1;
        else k=0;
        char temp;
        for(j=k;j<=(i-1)/2;j++)
        {
            temp=str[j];
            str[j]=str[i-1+k-j];
            str[i-1+k-j]=temp;
        }
        return str;
    }

};

#endif /* defined(__Optimization_methods__split__) */
