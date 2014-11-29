//
//  twoPhase.h
//  Optimization_methods_hongyu
//
//  Created by hongyu on 14/11/28.
//  Copyright (c) 2014年 hongyu. All rights reserved.
//

#ifndef __Optimization_methods_hongyu__twoPhase__
#define __Optimization_methods_hongyu__twoPhase__

#include <stdio.h>
#include "simplex.h"

class twoPhase:public simplex
{
    twoPhase();
    void calulateP();
    bool isEndU();
    void calulateU();
    
};

#endif /* defined(__Optimization_methods_hongyu__twoPhase__) */
