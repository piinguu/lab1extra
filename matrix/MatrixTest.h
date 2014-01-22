#ifndef MATRIX_TEST_H_INCLUDED
#define MATRIX_TEST_H_INCLUDED

#include "Matrix.h"
#include "/info/cprog09/cxxtest/cxxtest/TestSuite.h"
#include <fstream>
#include <sstream>

class MatrixTestSuite : public CxxTest::TestSuite
{
	void correct_rows_columns ( Matrix m, int rows, int cols )
	{
		if (m.rows() != rows)
			std::cout << "Fel antal rader i matrisen. Borde vara " << rows << ", är " << m.rows();
		if (m.cols() != cols)
			std::cout << "Fel antal kolumner i matrisen. Borde vara " << cols << ", är " << m.cols();
			
		TS_ASSERT( m.rows() == rows );
		TS_ASSERT( m.cols() == cols );
	}
	
	void correct_rows_columns ( const Matrix & m1, const Matrix & m2)
	{
		correct_rows_columns ( m1, m2.rows(), m2.cols());
	}
	
	Matrix a_matrix_3by2() {    // [ 1 3 5 ]
        Matrix m;               // [ 0 2 0 ]
        std::stringstream s("  [ 1 3 5 ; 0 2 0 ]");
        s >> m;
        return m;
    }
    
    Matrix matrix_by_string(const std::string & s)
    {
        Matrix m;
        std::stringstream ss(s);
        ss >> m;
        return m;
    }
    
    // Tagen från example_test.h
    void init_matrix( Matrix& m, const char* file )
    {
        std::stringstream stream( file );   
        stream >> m;
    }
	
	
public:
	/*
	 * Testa alla konstruktorer
	 */
	void testDefaultConstructor ( )
	{
		Matrix m1;
		TS_ASSERT( m1.rows() == 0);
		TS_ASSERT(m1.cols() == 0);
	}
	
	void testIntIntConstructor ( )
	{
		Matrix m1( 2, 2 );
		correct_rows_columns(m1, 2, 2);
		
		Matrix m2( 4, 2 );
		correct_rows_columns(m2, 4, 2);
	}
	
	void testCopyConstructor ( )
	{
		Matrix m1 = a_matrix_3by2();
		Matrix m2(m1);
		
		correct_rows_columns(m2, m1);
		
		for (int i = 0; i < m1.rows(); ++i)
			for (int j = 0; j < m1.cols(); ++j)
				TS_ASSERT(m1[i][j] == m2[i][j]);
	}
	
	void testIntConstructor ( )
	{
		// Bör skapa enhetsmatrisen av given storlek
		Matrix m( 2 );
		correct_rows_columns(m, 2, 2); 
		
		TS_ASSERT( m[ 0 ][ 0 ] == 1 );
		TS_ASSERT( m[ 0 ][ 1 ] == 0 );
		TS_ASSERT( m[ 1 ][ 0 ] == 0 );
		TS_ASSERT( m[ 1 ][ 1 ] == 1 );
	}
	

	/*
	 * Testa I/O
	 */
	void testInputOperator ( )
	{
		Matrix m;
		std::stringstream s("  [ 1 3 5 ; 0 2 0 ]");
        s >> m;
		
		//std::cout << "Antal rader: " << m.rows() << " ; Antal kolumner: " << m.cols() << std::endl;
		correct_rows_columns(m, 2, 3);
		
		TS_ASSERT( m[ 0 ][ 0 ] == 1 );
		TS_ASSERT( m[ 0 ][ 1 ] == 3 );
		TS_ASSERT( m[ 0 ][ 2 ] == 5 );
		TS_ASSERT( m[ 1 ][ 0 ] == 0 );
		TS_ASSERT( m[ 1 ][ 1 ] == 2 );
		TS_ASSERT( m[ 1 ][ 2 ] == 0 );
	}
	
	
	
	/*
	 * Testa alla operatorer
	 */
	// Tagen från example_test.h
	void testIndexOperator ( )
    {
	    // TODO: utöka och testa lite mer?	
    
        Matrix m( 2, 2 );
        TS_ASSERT( m[ 0 ][ 1 ] == 0 );

        m = a_matrix_3by2();
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );
        TS_ASSERT( m[ 0 ][ 2 ] == 5 );

        init_matrix(m, "  [ 1 3 5 ; 0 2 1 ]");
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );

        std::stringstream ss;
        ss << m;
        ss >> m;
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );
    }
    
	void testAssignment ( )
	{
		// TODO
	}
	
    void testAddition ( )
    {
    	// Test av kvadratiska matriser
    	Matrix km1( 2, 2 );
    	init_matrix( km1, " [ 2 4 ; -1 -3 ] " );
    	Matrix km2( 2, 2 );
    	init_matrix( km2, " [ -1 9 ; 15 2 ] " );
    	
    	Matrix km3 = km2 + km1;
    	correct_rows_columns ( km3, km1.rows(), km1.cols() );
    	
    	TS_ASSERT( km3[ 0 ][ 0 ] == 1 );
    	TS_ASSERT( km3[ 0 ][ 1 ] == 13 );
    	TS_ASSERT( km3[ 1 ][ 0 ] == 14 );
    	TS_ASSERT( km3[ 1 ][ 1 ] == -1 );
    	
    	// Test av icke kvadratiska matriser
    	Matrix m1( 2, 3 );
    	init_matrix( m1, " [ 2 4 3 ; -1 -3 -10] " );
    	Matrix m2( 2, 3 );
    	init_matrix( m2, " [ -1 9 15 ; 15 2 2] " );
    	
    	Matrix m3 = m2 + m1;
    	correct_rows_columns ( m3, m1.rows(), m1.cols() );
    	
    	TS_ASSERT( m3[ 0 ][ 0 ] == 1 );
    	TS_ASSERT( m3[ 0 ][ 1 ] == 13 );
    	TS_ASSERT( m3[ 0 ][ 2 ] == 18 );
    	TS_ASSERT( m3[ 1 ][ 0 ] == 14 );
    	TS_ASSERT( m3[ 1 ][ 1 ] == -1 );
    	TS_ASSERT( m3[ 1 ][ 2 ] == -8 );
    }
    
    void testMultiplication ( )
    {
    	const Matrix m1 = matrix_by_string("[ 1 0 ; 0 1 ]");
    }
    
    void testScalarMultiplication ( )
    {
    	const Matrix m1 = a_matrix_3by2();
    	Matrix m2 = m1 * 3;
    	correct_rows_columns(m2, m1);
    	for (int i = 0; i < m1.rows(); ++i)
    		for (int j = 0; j < m1.cols(); ++j)
    			TS_ASSERT(m2[i][j] == m1[i][j]*3);
    }
    
    void testSubtraction ( ) 
    {
    	// TODO
    }
    
    void testNegate ( )
    {
    	// TODO
    }
};

#endif
