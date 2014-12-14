//
//  simplex.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 14/11/26.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved./Users/hongyu/Documents/workspace/Optimization_methods/Optimization-methods/Optimization-methods/simplex.cpp
//

#include "simplex.h"

simplex::simplex(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax,string result){
    this->result=result;
    this->c = c;
    for (int i=0; i<256;i++) {
        for (int j=0; j<256; j++) {
            this->a[i][j] = a[i][j];
        }
    }
    this->b = b;
    this->rmax=rmax;
    this->colmax= colmax;
    this->xnum = xnum;
    this->snum = snum;
    this->anum = anum;
    this->ai=ai;
    this->xResult =new vector<double>(xnum);
    for (int i=0; i<rmax;i++ ) {
        base.push_back(i+xnum);
    }
    for (int j=0; j<ai.size(); j++) {
        base[ai[j]]=snum+xnum+j;
    }
    
    ofstream SaveFile(result);
    SaveFile.clear();
    for (int i=0; i<rmax; i++) {
        SaveFile<<base[i]<<" ";
        for (int j=0; j<colmax; j++) {
            SaveFile<<a[i][j]<<" ";
        }
        SaveFile<<endl;
        //cout<<v->c[i]<<endl;
    }
    SaveFile<<"snum: "<<snum<<endl;
    SaveFile<<"c[]=\n";
    for (int i=0; i<c.size(); i++) {
        SaveFile<<c[i]<<" ";
    }
    SaveFile<<endl;

    SaveFile.close();
    
}
void simplex::Cpivoty()
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
    
    for (int j=0; j<colmax; j++) {        //j is column，i is row
        for (int i = 0; i<rmax; i++) {
            if (a[i][j] > 0) {
                double temp = b[i]/a[i][j];
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
    
    base[this->pivotx]=this->pivoty;

    
}
void simplex::Dantzig()
{
    double tampa[256][256]={0};
    vector<double> tampc = c;
    for (int i=0; i<rmax;i++) {
        for (int j=0; j<colmax; j++) {
            if (i!=this->pivotx) {
                tampa[i][j]= a[i][j]-(a[i][this->pivoty]/a[this->pivotx][this->pivoty])*a[this->pivotx][j];
            }else{
                tampa[i][j]= a[i][j]/a[this->pivotx][this->pivoty];
            }
        }
        if (i!=this->pivotx) {
            b[i]=b[i]-b[this->pivotx]*(a[i][this->pivoty]/a[this->pivotx][this->pivoty]);
        }else{
            b[i]=b[i];
        }
    }
    for (int j=0; j<colmax; j++) {
        tampc[j]=c[j]-(c[this->pivoty]/a[this->pivotx][this->pivoty])*a[this->pivotx][j];
    }
    Z=Z-b[this->pivotx]*(c[this->pivoty]/a[this->pivotx][this->pivoty]);
    b[this->pivotx]=b[this->pivotx]/a[this->pivotx][this->pivoty];
    
    for (int k=0; k<c.size(); k++) {
        c[k]=tampc[k];
    }
    for (int m=0; m<256; m++) {
        for (int n=0; n<256; n++) {
            a[m][n]=tampa[m][n];
        }
    }

    ofstream SaveFile(result,ios::app);

    
    SaveFile<<"pivotx"<<":"<<pivotx<<endl;
    SaveFile<<"pivoty"<<":"<<pivoty<<endl;
    
    for (int i=0; i<rmax; i++) {
        SaveFile<<"x"<<base[i]<<": ";
        for (int j=0; j<colmax; j++) {
            SaveFile<<a[i][j]<<" ";
        }
        SaveFile<<b[i];
        SaveFile<<endl;
        //cout<<v->c[i]<<endl;
    }
    SaveFile<<"Z: "<<-Z+c[c.size()];
    SaveFile<<endl;
    SaveFile.close();
}

bool simplex::isEnd()
{
    ofstream SaveFile(result,ios::app);
    SaveFile<<"c[]="<<endl;
    for (int i=0; i<c.size(); i++) {
        SaveFile<<c[i]<<" ";
    }
    SaveFile<<endl;
    for (int j=0; j<colmax; j++) {
        if (c[j]> 0)
            return false;
    }
    
    SaveFile.close();
    return true;
}

void simplex::start()
{
    int temp=0;
    if (hasResult) {
        while (!isEnd()&&(temp<1000)) {
            Cpivoty();
            Dantzig();
            temp++;
        }
        if (temp>=1000) {
            hasResult=false;
        }
    }
    
    ofstream SaveFile(result,ios::app);
    
    SaveFile<<"\n"<<"hasResult"<<hasResult<<endl;
    
    SaveFile<<"\n"<<"max(Z)="<<-Z+c[c.size()]<<endl;
    
    for (int i=0; i<base.size(); i++) {
        if (base[i]<xnum) {
            xResult->at(base[i])=b[i];
        }
    }
    for (int i=0; i<xResult->size(); i++) {
        SaveFile<<"x"<<i<<": "<<xResult->at(i)<<endl;
    }
    
    SaveFile.close();


}





    
