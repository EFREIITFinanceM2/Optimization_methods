//
//  main.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 09/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#include <iostream>
#include "binaryTree.h"
#include "simplex.h"
#include "readSimplex.h"
#include "changeForm.h"
#include "twoPhase.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";

    
    //Two Phase.
    readSimplex* vTwoPh=new readSimplex("twoPhase.txt");
    vTwoPh->read();
    vTwoPh=changeForm::change(vTwoPh);
    twoPhase *twoPh = new twoPhase(vTwoPh->c,vTwoPh->a,vTwoPh->d,vTwoPh->xnum,vTwoPh->snum,vTwoPh->anum,vTwoPh->ai,vTwoPh->rmax,vTwoPh->colmax,"twoPhaseResult.txt");
    twoPh->calulateU();
    twoPh->start();
    
    
    
    
    //Simplex.
    readSimplex* vSim=new readSimplex("Simplex.txt");
    vSim->read();
    vSim=changeForm::change(vSim);
    simplex *Sim = new simplex(vSim->c,vSim->a,vSim->d,vSim->xnum,vSim->snum,vSim->anum,vSim->ai,vSim->rmax,vSim->colmax,"simplexResult.txt");
    Sim->start();
    

    
    
    
    /*
    binaryTree* T = new binaryTree(v->c,v->a,v->d,v->c.size(),v->tracker_num,v->tempar, (v->ta)+1);
    T->start();
    
    ofstream SaveFile("result.txt");

    SaveFile<<"max(z)= "<<T->Z<<endl;
    for (int i=0; i<T->result.size(); i++) {
        SaveFile<<"X["<<i<<"]="<<T->result[i]<<endl;
    }
    */
   
        //simplex(vector<double> c,double a[][256],vector<double> b,int xnum,int snum, int anum,vector<int> ai, int rmax,int colmax);
    
    //ofstream SaveFile("result.txt");
    
    /* simplex

    simplex *s = new simplex(v->c,v->a,v->d,v->xnum,v->snum,v->anum,v->ai,v->rmax,v->colmax);
    s->start();
     
     */
    
    
    
    //simplex s = new simplex(v->c,v->a,v->d,v-)
    
    return 0;
}
