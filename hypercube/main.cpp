//
//  main.cpp
//  HyperCube
//
//  Created by Linus Enroth Hansson on 2013-11-18.
//  Copyright (c) 2013 Linus Enroth Hansson. All rights reserved.
//

#include <iostream>
#include "hypercube.h"

int main(int argc, const char * argv[])
{
    Hypercube<1> h(2);
    std::cout << h[0] << std::endl;
    
    Hypercube<2> hc2(2);
    //Vector<int> iv(5);
    //Vector< Hypercube<1> > hv(2);
    return 0;
}

