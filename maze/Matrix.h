
#ifndef DD2387_labb1__Matrix
#define DD2387_labb1__Matrix

#include "vector.h"

class Matrix
{
public:
    typedef unsigned int index;
    
    class matrix_row : private Vector< char >
    {
    public:
        matrix_row( std::size_t s = 0) :
        Vector<char>(s)
        {}
        
        using Vector<char>::operator [];
        
    private:
        friend std::istream& operator>>( std::istream&, Matrix& );
    };
    
    /********************************************************
     * constructors
     *******************************************************/
    Matrix();
    Matrix( std::size_t, std::size_t );
    Matrix( const Matrix& );
    explicit Matrix(std::size_t size);
    ~Matrix( );
    
    /********************************************************
     * operators
     *******************************************************/
    Matrix & operator= ( const Matrix & );
    Matrix operator+ ( const Matrix & ) const;
    Matrix operator* ( const Matrix & ) const;
    Matrix operator* ( int ) const;
    Matrix operator-( const Matrix & ) const;
    Matrix operator-( ) const;
    
    Matrix & transpose( );
    
    matrix_row & operator[]( index i );
    const matrix_row& operator[]( index i ) const;
    
    std::size_t rows() const;
    std::size_t cols() const;
    
    void swap( Matrix & other );
    
protected:
private:
    Vector< matrix_row >        m_vectors;
    std::size_t                 m_rows;
    std::size_t                 m_cols;
    
    friend std::istream& operator>> ( std::istream&, Matrix& );
    
    
    /********************************************************
     * functions used for the maze solver
     *******************************************************/
public:
    Matrix & read(const char ** data);
    bool solve();
    
private:
    void mark_doors();
    bool DFS(int start_row, int start_col);
};


/********************************************************
 * input/output streams
 *******************************************************/
std::istream& operator>> ( std::istream&, Matrix& );
std::ostream& operator<< ( std::ostream&, Matrix& );


Matrix operator* ( int, const Matrix& ); // skalärprodukt??


#endif /* defined(DD2387_labb1__Matrix) */
