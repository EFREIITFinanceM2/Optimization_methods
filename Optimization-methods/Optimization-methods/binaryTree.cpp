//
//  binaryTree.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 10/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#include <stdio.h>
#include "binaryTree.h"

binaryTree::binaryTree(vector<double> c,double a[256][256],vector<double> b,int numC,int numE,int ar,int ac){
    this->c=c;
    for (int k=0; k<256; k++) {
        for (int j=0; j<256; j++) {
            this->a[k][j]=a[k][j];
        }
    }
    //this->a=a;
    //a[0][0];
    //this->a=a;
    this->b=b;
    this->ar=ar;
    this->ac=ac;
    int tempsq=1;
    for (int n=0; n<numC; n++) {
        size=size+tempsq;
        tempsq=tempsq*2;
    }
    
    for (int n=0; n<size; n++) {
        TNode* temp=new TNode(numC-1,numE+1);
        tree.push_back(temp);
    }
    calculateB(tree[0]);
    calculateE(tree[0]);
}

void binaryTree::searchL(int pi, int i){
    int temp=changeX(pi,i,1);
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
    if (temp==c.size()-2) {
        if (tree[i]->b>=Z) {
            this->result=tree[i]->x;
            Z=tree[i]->b;
        }
        return;
    }
    searchL(i, 2*i+1);
    searchR(i, 2*i+2);
}

void binaryTree::searchR(int pi, int i){
    int temp=changeX(pi,i,0);
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
    if (temp==c.size()-2) {
        if (tree[i]->b>=Z) {
            result=tree[i]->x;
            Z=tree[i]->b;
        }
                return;
    }
    searchL(i, 2*i+1);
    searchR(i, 2*i+2);
}

void binaryTree::calculateB(TNode *node){
    node->b=0;
    for (int i=0; i<c.size()-1; i++) {
        if (c[i]<0) {
            node->b=node->b;
        }
        else{
            node->b=node->b+c[i];
        }
    }
    node->b=node->b+c[c.size()-1];
}

void binaryTree::calculateB(TNode *node, double pb){
    if (node->x[node->changeI]==1) {
        node->b=pb;
    }
    else{
        node->b=pb-c[node->changeI];
    }
}

void binaryTree::calculateE(TNode *node){
    for (int i=0; i<node->e.size(); i++) {
        node->e[i]=b[i];
        for (int j=0; j<ac; j++) {
            if (a[i][j]<0) {
                node->e[i]=node->e[i]-a[i][j];
            }
        }
    }
}

void binaryTree::calculateE(TNode *node, vector<double> pe){
    for (int n=0; n<node->e.size(); n++) {
        if (node->x[node->changeI]==1){
            if (a[n][node->changeI]>0) {
                node->e[n]=pe[n]-a[n][node->changeI];
            }
        }
        else{
            if (a[n][node->changeI]<0) {
                node->e[n]=pe[n]+a[n][node->changeI];

            }
        }
    }
}

int binaryTree::changeX(int pi, int i,int LR){
    int tempIndex=0;
    while (tree[pi]->x[tempIndex]!=-1) {
        tree[i]->x[tempIndex]=tree[pi]->x[tempIndex];
        tempIndex++;
    }
    tree[i]->x[tempIndex]=LR*1;
    tree[i]->changeI=tempIndex;
    return tempIndex;
}

void binaryTree::start(){
    searchL(i, 2*i+1);
    searchR(i, 2*i+2);
}