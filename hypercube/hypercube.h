#pragma once
#include "vector.h"

/* Class holding a N-dimensional hypercube.
 * Uses the vector class internally. The vector holds
 * hypercube objects of dimension N-1.
 */
template <unsigned int N>
struct Hypercube : private Vector< Hypercube< N-1> >
{
	Hypercube(const unsigned int n = 0) : Vector< Hypercube< N-1 > >(n) {}
    
    using Vector< Hypercube< N-1 > >::operator[];
};

template <>
struct Hypercube< 1 > : private Vector< unsigned int >
{
	unsigned int u;
    Hypercube(unsigned int n = 0) : u(0), Vector< unsigned int >(n, u) {}
    
    using Vector< unsigned int >::operator[];
};
