//
//  TNode.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 10/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#include "TNode.h"

TNode::TNode(int N,int M){
    for (int i=0; i<N; i++) {
        x.push_back(-1);
    }
    for (int i=0; i<M; i++) {
        e.push_back(-1);
    }
}