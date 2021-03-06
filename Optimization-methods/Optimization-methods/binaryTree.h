//
//  binaryTree.h
//  Optimization-methods
//
//  Created by ZN-MAC on 10/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#ifndef Optimization_methods_binaryTree_h
#define Optimization_methods_binaryTree_h
#include "TNode.h"

class binaryTree {
public:
    //TNode node=new TNode();
    vector<TNode*> tree;
    vector<double> c;
    double a[256][256];
    vector<double> b;
    int size=1;
    int Z=0;
    int i=0;
    int ar=0;
    int ac=0;
    vector<int> result;
    int j=0;
    binaryTree(vector<double> c,double a[256][256],vector<double> b,int size,int numE,int ar,int ac);
    void searchL(int pi,int i);
    void searchR(int pi, int i);
    void calculateB(TNode* node);
    void calculateE(TNode* node);
    void calculateB(TNode* node,double pb);
    void calculateE(TNode* node,vector<double> pe);
    int changeX(int pi,int i,int LR);
    void start();
};

#endif
