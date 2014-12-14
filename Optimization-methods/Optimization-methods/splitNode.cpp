//
//  splitNode.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 14/12/13.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#include "splitNode.h"

splitNode::splitNode(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax,string result, readSimplex *read){
    this->node=new twoPhase(c, a,b,xnum,snum, anum, ai, rmax, colmax, result,read);
    node->calulateU();
    node->start();
}

splitNode::splitNode(){
    this->node=NULL;
}