//
//  main.cpp
//  DD2387_lab1
//
//  Created by Linus Enroth Hansson on 2013-11-09.
//  Copyright (c) 2013 Linus Enroth Hansson. All rights reserved.
//

#include <iostream>
#include "Matrix.h"
#include <vector>
#include <string.h>
#include <sstream>

int main(int argc, const char * argv[])
{
    /*
    Matrix m(5,5);
    Matrix m2(5,5);
    m = m+m2+m2+m+m2;
    
    std::cout << "Addition\n";
    std::cout << m << std::endl;
    
    m = m*2;
    std::cout << "\nScalar multiplication\n";
    std::cout << m << std::endl;
    
    Matrix sub = m-m2;
    std::cout << "\nSubtraction\n";
    std::cout << sub << std::endl;
    
    Matrix m3(3, 6);
    for (int i=0; i<3; ++i)
        for (int j=0; j<6; ++j)
            m3[i][j] = i*j;
    Matrix tran;
    tran = m3.transpose();
    std::cout << "\nTranspose\n";
    std::cout << tran << std::endl;
    
    Matrix mult1(m3);
    Matrix mult2(6,3);
    Matrix res = mult1*mult2;
    std::cout << "\nmultiplication with matrix\n";
    std::cout << res << std::endl;
     */
    
    Matrix m;
    std::stringstream s(" [ 1 2 3 ; -4 2 7 ] ");
    s >> m;
    
    std::cout << m;
    m = m+m;
    std::cout << m;
    
    std::cout << "\n\n\n";
    
    Matrix m2(3,6);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 6; ++j)
            m2[i][j] = i*j;
    
    std::cout << m2 << std::endl;
    
    m2 = m2.transpose();
    
    std::cout << m2 << std::endl;
    
    return 0;
}

