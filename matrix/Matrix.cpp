#include "Matrix.h"
#include <stdexcept>
#include <vector>
#include <stdlib.h>

/********************************************************
 * constructors
 *******************************************************/

/*
 * Default constructor
 */
Matrix::Matrix() :
    m_rows(0),
    m_cols(0),
    m_vectors(0)
{}

/*
 * Create a matrix with given amount of rows and columns.
 */
Matrix::Matrix( std::size_t rows, std::size_t cols ) :
    m_rows(rows),
    m_cols(cols),
    // hur funkar matrix_rows(size) ???
    m_vectors(rows, matrix_row(cols))
{
    for (int i=0; i<rows; ++i)
        for (int j=0; j<cols; ++j)
            m_vectors[i][j] = 4;
}

/*
 * Copy constructor
 */
Matrix::Matrix( const Matrix & other ) :
    m_rows(other.rows()),
    m_cols(other.cols()),
    m_vectors(other.rows(), matrix_row(other.cols()))
{
    for (int i=0; i<m_rows; ++i)
        for (int j=0; j<m_cols; ++j)
            m_vectors[i][j] = other[i][j];
}

/*
 * Create a identity matrix of given size
 */
Matrix::Matrix( int size ) :
    m_rows(size),
    m_cols(size),
    m_vectors(size, matrix_row(size))
{
    for (int i=0; i<size; ++i)
        m_vectors[i][i] = 1;
}

/********************************************************
 * destructor
 *******************************************************/

/*
 * Destructor
 */
Matrix::~Matrix()
{
    // TODO: behöver jag göra något här eller tar vector.cpp hand om det?
}


/********************************************************
 * operators
 *******************************************************/
/*
 * Assignment operator
 */
Matrix & Matrix::operator=( const Matrix & other )
{
    if (this != &other) {
        m_rows = other.rows();
        m_cols = other.cols();
        m_vectors = other.m_vectors;
    }
    
    return *this;
}

/*
 * Addition.
 */
Matrix Matrix::operator+( const Matrix & other ) const
{
    // If matrices are of different sizes.
    if (other.rows() != m_rows || other.cols() != m_cols)
        throw std::out_of_range("operator+: Matrix dimension does not correspond");
    
    // Create a temporary matrix in which to do the calculations
    Matrix add(m_rows, m_cols);
    
    for (std::size_t i=0; i<m_rows; ++i)
        for (std::size_t j=0; j<m_cols; ++j)
            add[i][j] = (*this)[i][j] + other.m_vectors[i][j];
    
    return add;
}

/*
 * Matrix multiplication
 * this * other (or the other way around?)
 */
Matrix Matrix::operator*( const Matrix & other ) const
{
    // If matrices are of unsupported sizes.
    // Matrix multiplication requires that m_cols == other.rows()
    if (m_cols != other.rows())
        throw std::out_of_range("operator* (const Matrix & other): Matrix dimension does not correspond to the requirement");
    
    // Create a temporary matrix in which to do the calculations
    Matrix mult(m_rows, other.cols());
    // for every row in resulting matrix
    for (std::size_t i=0; i < m_rows; ++i)
    {
        // for all columns in resulting matrix (that is columns in 'other')
        for (std::size_t j=0; j < other.cols(); ++j)
        {
            // calculate the sum of (*this)[i][k] * other[k][j] for all k
            // where k corresponds to every columne in 'this' and
            // every row in 'other'
            for (std::size_t k=0; k < m_cols; ++k)
            {
                mult[i][j] += (*this)[i][k] * other[k][j];
            }
        }
        
    }
    
    return mult;
}

/*
 * Multiplication with a scalar
 */
Matrix Matrix::operator*( int s ) const
{
    // Create a temporary matrix in which to do the calculations
    Matrix scalar(m_rows, m_cols);
    for (std::size_t i=0; i < m_rows; ++i)
        for (std::size_t j=0; j < m_cols; ++j)
            scalar[i][j] = s * (*this)[i][j];
    
    return scalar;
}

/*
 * Subtraction
 */
Matrix Matrix::operator-( const Matrix & other ) const
{
    // If matrices are of different sizes.
    if (other.rows() != m_rows || other.cols() != m_cols)
        throw std::out_of_range("operator-(const Matrix & other): Matrix dimension does not correspond");
    
    // Create a temporary matrix in which to do the calculations
    Matrix sub(m_rows, m_cols);
    for (std::size_t i=0; i < m_rows; ++i)
        for (std::size_t j=0; j < m_cols; ++j)
            sub[i][j] = (*this)[i][j] - other[i][j];
    
    return sub;
}

/*
 * Make all elements negative? (*this)[i][j] = -(*this)[i][j]?
 */
Matrix Matrix::operator-( ) const
{
    // Create a temporary matrix in which to do the calculations
    Matrix neg(m_rows, m_cols);
    for (std::size_t i=0; i < m_rows; ++i)
        for (std::size_t j=0; j < m_cols; ++j)
            neg[i][j] = -(*this)[i][j];
    
    return neg;
}

/*
 * Transpose the matrix
 */
Matrix & Matrix::transpose( )
{
    //TODO:
    Matrix m(m_cols, m_rows);
    for (int i=0; i<m_rows; ++i)
        for (int j=0; j<m_cols; ++j)
            m[j][i] = (*this)[i][j];
    
    *this = m;
    return *this;
}

/*
 * Subscript operator
 */
Matrix::matrix_row & Matrix::operator[]( index i )
{
    return m_vectors[i];
    // Index out of range is handled by vector
}

/*
 * Constant subscript operator
 */
const Matrix::matrix_row & Matrix::operator[]( index i ) const
{
    return m_vectors[i];
    // Index out of range is handled by vector
}

/*
 * Global operator *
 */
Matrix operator*(int a, const Matrix & other)
{
    // Use operator * from Matrix
    return other*a;
}

/********************************************************
 * other stuff
 *******************************************************/

/*
 * Return number of rows in matrix.
 */
std::size_t Matrix::rows() const {
    return m_rows;
}

/*
 * Return number of columns in matrix.
 */
std::size_t Matrix::cols() const {
    return m_cols;
}


/********************************************************
 * output/input operators
 *******************************************************/


/*
 * Output operator (<<)
 * Output should be printed like:
 *      [ 1 2 -3        empty matrix: []
 *      ; 5 6 7 ]
 */
std::ostream & operator<<(std::ostream & os, Matrix & other)
{
    os << "[ ";
    // For every row in matrix
    for(std::size_t i=0; i<other.rows(); ++i)
    {
        // each row is represented with a semicolon and space (except the first row)
        // followed by space separated values for each column followed by a newline.
        
        // Print the semicolon and space if this is not the first row
        if (0 != i)
            os << "; ";
        
        // Print all values separated with a space
        for(std::size_t j=0; j<other.cols(); j++)
            os << other[i][j] << ' ';
        
        // Print the newline character
        if (i != (other.rows()-1))
            os << std::endl;
    }
    
    // Print the closing bracket and a newline.
    os << "]" << std::endl;
    
    return os;
}

/*
 * Input operator (>>).
 * Input should be formatted like following:
 *      [ 1 2 -3 ; 5 6 7 ], each row is followed by "space ; space" and all elements are separated by space
 *
 * WARNING: no error handling of incorrect input. This function assumes the input is
 * correctly formatted.
 */
std::istream & operator>>(std::istream & is, Matrix & other)
{
    std::string str;
    std::vector< std::string > vec;
    
    while (is >> str) // reads one "word" and stores in 'vec'
        vec.push_back(str);
    // 'vec' now contains all "words" (that is: all numbers, brackets and semicolons.

    // Find size of matrix
    int num_rows = 1;
    int num_cols = 0;
    bool nr_columns = false;
    
    std::vector< int > ivec;
    // for each 'word' in vec. Try to parse to int and count the number of rows and columns we should have.
    for (std::string s : vec)
    {
        if (s == "[" || s == "]")
            continue; // We are not interested in the brackets.
        
        if (s == ";")
        {
            nr_columns = true;
            num_rows++; // We have another row
            continue;
        }
        
        // else we have a integer value
        // if this is the first row, we still don't know how many columns we have, add 1
        if (!nr_columns)
            num_cols++;

        // convert std::string to integer and add to ivec
        ivec.push_back(stoi(s));
    }
    
    // now we know the number of rows and columns, create a matrix
    Matrix m(num_rows, num_cols);
    int index = 0; // the index of the next integer to write in the matrix
    for (int i=0; i<num_rows; ++i)
        for (int j=0; j<num_cols; ++j)
        {
            m[i][j] = ivec[index];
            ++index;
        }
    
    // assign the new matrix to the input parameter
    other = m;
    
    return is;
}