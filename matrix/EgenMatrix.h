#ifndef DD2387_labb1__Matrix
#define DD2387_labb1__Matrix

#include "vector.h"

class Matrix
{
public:
    typedef unsigned int index;
    
    /*
     * Class that represents a row in the matrix
     */
    class matrix_row : private Vector< int >
    {
    public:
        /*
         * Create a new row of given size (default size is 0).
         */
        matrix_row( std::size_t s = 0) :
        Vector<int>(s)
        {}
        
        using Vector<int>::operator [];
        
    private:
        friend std::istream& operator>>( std::istream&, Matrix& );
    };
    
    /********************************************************
     * constructors
     *******************************************************/
    
    Matrix();
    
    /* Create a x*y matrix initialized to 0.*/
    Matrix( std::size_t, std::size_t ); // (size_t x, size_t y)
    
    Matrix( const Matrix& );
    
    /* Create an indentity matrix of size 'size' */
    explicit Matrix(std::size_t size);
    
    ~Matrix( );
    
    /********************************************************
     * operators
     *******************************************************/
    Matrix & operator= ( const Matrix & );		// tilldelning
    Matrix operator+ ( const Matrix & ) const;	// addition
    Matrix operator* ( const Matrix & ) const;	// Multiplikation med matris
    Matrix operator* ( int ) const;				// Multiplikation med skalär
    Matrix operator-( const Matrix & ) const;	// subtraktion
    Matrix operator-( ) const;
    
    Matrix & transpose( );						// transponat
    
    matrix_row & operator[]( index i );
    const matrix_row& operator[]( index i ) const;
    
    std::size_t rows() const;
    std::size_t cols() const;
    
    void swap( Matrix & other );
    
protected:
private:
    Vector< matrix_row >        m_vectors; // vector containing one matrix_row per row in matrix.
    std::size_t                 m_rows; // number of rows
    std::size_t                 m_cols; // number of columns
    
    void add_row( );            // Non mandatory help function
    
    friend std::istream& operator>> ( std::istream&, Matrix& );
};


/********************************************************
 * input/output streams
 *******************************************************/
std::istream& operator>> ( std::istream&, Matrix& );
std::ostream& operator<< ( std::ostream&, Matrix& );


Matrix operator* ( int, const Matrix& ); // skalärprodukt??


#endif /* defined(DD2387_labb1__Matrix) */
