#ifndef HyperCube_hypercube_h
#define HyperCube_hypercube_h

#include "vector.h"

// Class holding a N-dimensional hypercube.
// Uses the vector class internally. The vector holds
// hypercube objects of dimension N-1.
//
// TODO: the vector needs to be able to take a hybercube and
//       initialize it to empty Hypercubes of the correct dimension.
//
template <unsigned int N>
class Hypercube : private Vector< Hypercube< N-1> >
{
public:
    Hypercube(const unsigned int n) : Vector< Hypercube< N-1 > >::Vector(n)//, Hypercube<N-1>(n))
    {
        std::cout << "N > 1\n";
    }
    
    using Vector< Hypercube< N-1 > >::operator[];
};

// Base case.
// The internal vector holds unsigned ints.
template <>
class Hypercube< 1u > : private Vector< unsigned int >
{
public:
    Hypercube(unsigned int n) : Vector< unsigned int >::Vector(n)
    {
        std::cout << "N = 1\n";
    }
    
    using Vector< unsigned int >::operator[];
};

#endif
