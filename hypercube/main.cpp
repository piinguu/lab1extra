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
/*    Hypercube<2> hc2(2);
    hc2[0][0] = 5;
    std::cout << hc2[0][0] << std::endl;
  */  
    Hypercube<3> h(3);
    std::cout << "////////////////////////////////////////\n\n";
    
    Hypercube<3> n(7);
	// kub med 7*7*7 element
	Hypercube<6> m(5);
	// sex dimensioner, 5*5*...*5 element
	m[1][3][2][1][4][0] = 7;
	Hypercube<3> t(5);
	t = m[1][3][2];
	// tilldela med del av m
	//t[1][4][0] = 2;
	// ändra t, ändra inte m
	std::cout << m[1][3][2][1][4][0] << std::endl; // 7
	std::cout << t[1][4][0] << std::endl; // 2
	std::cout << t[1][3][2] << std::endl;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
		{
			std::cout << "i = " << i << ", j = " << j << ": ";
			for (int k = 0; k < 5; ++k)
				std::cout << t[i][j][k] << ',';
			std::cout << std::endl;
		}
    
    std::cout << "\nmmmmmmmmmmmmmmmmmmmmmmmmmmmmm...\n\n";
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
		{
			std::cout << "i = " << i << ", j = " << j << ": ";
			for (int k = 0; k < 5; ++k)
				std::cout << m[0][0][0][i][j][k] << ',';
			std::cout << std::endl;
		}
    return 0;
}

