//
//  binaryTree.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 10/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#include <stdio.h>
#include "binaryTree.h"

binaryTree::binaryTree(vector<double> c,vector<vector<double>> a,vector<double> b,int numC,int numE){
    this->c=c;
    this->a=a;
    this->b=b;
    for (int n; n<numC; n++) {
        this->size=this->size*2;
    }
    
    for (int n=0; n<size; n++) {
        TNode* temp;
        temp=new TNode(numC-1,numE);
        tree.push_back(new TNode(numC-1,numE));
    }
    calculateB(tree[0]);
    calculateE(tree[0]);
}

void binaryTree::searchL(int pi, int i){
    changeX(pi,i,1);
    calculateB(tree[i],tree[pi]->b);
    calculateE(tree[i],tree[pi]->e);
    if (tree[i]->b<Z) {
        return;
    }
    for (int n=0; n<tree[i]->e.size(); n++) {
        if (tree[i]->e[n]<0) {
            return;
        }
    }
    searchL(i, 2*i+1);
    searchR(i, 2*i+2);
}

void binaryTree::searchR(int pi, int i){
    changeX(pi,i,0);
    calculateB(tree[i],tree[pi]->b);
    calculateE(tree[i],tree[pi]->e);
    if (tree[i]->b<Z) {
        return;
    }
    for (int n=0; n<tree[i]->e.size(); n++) {
        if (tree[i]->e[n]<0) {
            return;
        }
    }
    searchL(i, 2*i+1);
    searchR(i, 2*i+2);
}

void binaryTree::calculateB(TNode *node){
    node->b=0;
    for (int i=0; i<c.size(); i++) {
        if (c[i]<0) {
            node->b=node->b-c[i];
        }
        else{
            node->b=node->b+c[i];
        }
    }
}

void binaryTree::calculateB(TNode *node, double pb){
    if (node->e[node->changeI]==1) {
        node->b=pb;
    }
    else{
        node->b=pb-c[node->changeI];
    }
}

void binaryTree::calculateE(TNode *node){
    for (int i=0; i<node->e.size(); i++) {
        for (int j=0; j<a[0].size(); j++) {
            <#statements#>
        }
    }
}

void binaryTree::calculateE(TNode *node, vector<double> pe){
    for (int n=0; n<node->e.size(); n++) {
        if (node->changeI==1){
            node->e[n]=pe[n]-a[n][node->changeI];
        }
        else{
            node->e[n]=pe[n]+a[n][node->changeI];
        }
    }
}

void binaryTree::changeX(int pi, int i,int LR){
    int tempIndex=0;
    while (tree[pi]->x[tempIndex]!=-1) {
        tree[i]->x[tempIndex]=tree[pi]->x[tempIndex];
        tempIndex++;
    }
    tree[i]->x[tempIndex]=LR*1;
}