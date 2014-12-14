//
//  split.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 14/12/3.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#include "split.h"

split::split(readSimplex *readb){
    readSimplex *read;
    read=changeForm::change(readb);
    splitTree=new splitNode(read->c,read->a,read->d,read->xnum,read->snum,read->anum,read->ai,read->rmax,read->colmax,"split0.txt", readb);
    this->zMax=this->splitTree->node->Z;
}

void split::search(splitNode *node){
    if (!createChildren(node)) {
        return;
    }
    search(node->L);
    search(node->R);
}

bool split::createChildren(splitNode *node){
    if (!node->node->hasResult) {
        return false;
    }
    if (node->node->Z<zMin) {
        return false;
    }
    for (int i=0; i<node->node->xResult->size(); i++) {
        if (!isINT(node->node->xResult->at(i))) {
            node->node->read->a[node->node->read->rmax][i]=1;
            node->node->read->rmax++;
            node->node->read->d.push_back(int(node->node->xResult->at(i)));
            node->node->read->symbol.push_back('L');
            readSimplex *vTwoPh;
            vTwoPh=changeForm::change(node->node->read);
            number++;
            char temp[100];
            node->R = new splitNode(vTwoPh->c,vTwoPh->a,vTwoPh->d,vTwoPh->xnum,vTwoPh->snum,vTwoPh->anum,vTwoPh->ai,vTwoPh->rmax,vTwoPh->colmax,"split"+string(itoa(number, temp, 10))+".txt",node->node->read);
            delete vTwoPh;
            
            node->node->read->d.push_back(int(node->node->xResult->at(i))+1);
            node->node->read->symbol[node->node->read->symbol.size()-1]='B';
            vTwoPh=changeForm::change(node->node->read);
            number++;
            char tempp[100];
            node->L = new splitNode(vTwoPh->c,vTwoPh->a,vTwoPh->d,vTwoPh->xnum,vTwoPh->snum,vTwoPh->anum,vTwoPh->ai,vTwoPh->rmax,vTwoPh->colmax,"split"+string(itoa(number, tempp, 10))+".txt",node->node->read);
            delete vTwoPh;
            
            return true;
        }
    }
    zMin=node->node->Z;
    result=node->node;
    return false;
}

bool split::isINT(double i){
    if (i-int(i)<0.11 || i-int(i)>0.89) {
        return true;
    }
    else{
        return false;
    }
}
void split::start(){
    search(this->splitTree);
    ofstream SaveFile("splitResult.txt");
    string temp;
    if (zMin==-100000) {
        temp="No result";
        SaveFile<<temp<<"\n";
    }
    else{
        temp="has result";
        SaveFile<<temp<<"\n";
        SaveFile<<"In the file: "<<result->result<<endl;
    }

}