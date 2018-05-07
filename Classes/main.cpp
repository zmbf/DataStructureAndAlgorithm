//
//  main.cpp
//  DataStructureAndAlgorithm
//
//  Created by xdlc on 2018/5/7.
//  Copyright © 2018年 zmbf. All rights reserved.
//

#include <iostream>
#include <list>
#include "DoubleLink.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::list<int> vec;
    for(int i =0;i<10;i++){
        vec.push_back(i);
    }
    int a = *vec.end();
    a  = 1000;
    for(auto & u : vec){
        std::cout<<u<<std::endl;
    }
    std::cout << "Hello, World!\n";
    DoubleLink<int> * dbl =new DoubleLink<int>();
    dbl->insert(0,5);
    return 0;
}
