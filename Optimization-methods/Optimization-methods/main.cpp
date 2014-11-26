//
//  main.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 09/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#include <iostream>
#include "binaryTree.h"
#include "read.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    view* v=new view();
    v->read();
    /*
    binaryTree* T = new binaryTree(v->c,v->a,v->d,v->c.size(),v->tracker_num,v->tempar, (v->ta)+1);
    T->start();
    
    ofstream SaveFile("result.txt");

    SaveFile<<"max(z)= "<<T->Z<<endl;
    for (int i=0; i<T->result.size(); i++) {
        SaveFile<<"X["<<i<<"]="<<T->result[i]<<endl;
    }
    */
    
    
    
    return 0;
}
