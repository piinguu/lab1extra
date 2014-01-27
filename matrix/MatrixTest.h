#ifndef MATRIX_TEST_H_INCLUDED
#define MATRIX_TEST_H_INCLUDED

#include "EgenMatrix.h"
#include "/info/cprog09/cxxtest/cxxtest/TestSuite.h"
#include <fstream>
#include <sstream>
#include <iostream>

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
    
	void identical( const Matrix & m1, const Matrix & m2)
	{
		correct_rows_columns(m1, m2);
    	for (int i = 0; i < m1.rows(); ++i)
    		for (int j = 0; j < m1.cols(); ++j)
    			TS_ASSERT(m1[i][j] == m2[i][j]);

	}
	
	void identical (const Matrix & m1, const std::string & m2)
	{
		return identical (m1, matrix_by_string(m2));
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
    	//Arrange - create from stringstream
    	const Matrix m = matrix_by_string("[ 4 -3 0 ; 15 -01 6 ]");
    
    	//Assert
    	TS_ASSERT( m[ 0 ][ 0 ] == 4 );
        TS_ASSERT( m[ 0 ][ 1 ] == -3 );
        TS_ASSERT( m[ 0 ][ 2 ] == 0 );
        TS_ASSERT( m[ 1 ][ 0 ] == 15 );
        TS_ASSERT( m[ 1 ][ 1 ] == -1 );
        TS_ASSERT( m[ 1 ][ 2 ] == 6 );
        
        //Arrange - create with index operator
        Matrix m2(1, 2);
        m2[0][0] = 10;
        m2[0][1] = -2;
        
        //Assert
        TS_ASSERT( m2[0][0] == 10);
        TS_ASSERT( m2[0][1] == -2);
    }
    
	void testAssignment ( )
	{
		//Arrange
		Matrix m1(2);
		Matrix m2 = matrix_by_string("[ 4 2 0 ; 9 4 2 ; 30 3 -1 ]");
		Matrix m3 = matrix_by_string("[ 1 3 5 ; 0 2 0 ]");
		Matrix m4;
		
		//Act
		m1 = m2;
		m4 = m3;
		
		//Assert
		identical (m1, m2);
		identical (m4, m3);
	}
	
    void testAddition ( )
    {
    	// Test av kvadratiska matriser
    	//Arrange
    	const Matrix km1 = matrix_by_string(" [ 2 4 ; -1 -3 ] ");
    	const Matrix km2 = matrix_by_string(" [ -1 9 ; 15 2 ] " );
    	
    	//Act and assert
    	identical (km2 + km1, "[ 1 13 ; 14 -1 ]");

    	// Test av icke kvadratiska matriser
    	//Arrange
    	const Matrix m1 = matrix_by_string("[ 2 4 3 ; -1 -3 -10]" );
    	const Matrix m2 = matrix_by_string("[ -1 9 15 ; 15 2 2]" );
    	
    	//Act and assert
    	identical(m2 + m1, "[ 1 13 18 ; 14 -1 -8 ]");
    }
    
    void testMoreAddition ( )
    {
    	//Arrange
    	Matrix m1(2,1);
        m1 = a_matrix_3by2();
        Matrix m2(2,1);
        m2 = a_matrix_3by2();
        
        //Pre-assert
        std::cout << "\nPre-assert...";
        correct_rows_columns(m1, 2, 3);
        std::cout << "_";
        correct_rows_columns(m2, 2, 3);
        std::cout << "done.\n";
        
        //Act
        Matrix m3 = m1 + m2;
        
        //Assert
        identical (m3, "[ 2 6 10 ; 0 4 0 ]");
    }
    
    void testMultiplication ( )
    {
    	//Arrange
    	const Matrix m1 = matrix_by_string("[ 1 0 ; 0 1 ]");
    	const Matrix n1 = matrix_by_string("[ 3 5 8 ; 1 4 -7 ]");
    	const Matrix n2 = matrix_by_string("[ 7 1 ; -3 13 ; 2 0 ]");
		
		//Act
    	const Matrix m2 = m1 * m1;
    	const Matrix n3 = n1 * n2;
		
		//Assert
		identical(m2, "[ 1 0 ; 0 1 ]");
		identical(n3, "[ 22 68 ; -19 53 ]");
    }
    
    void testScalarMultiplication ( )
    {
    	//Arrange
    	const Matrix m1 = matrix_by_string("[ 1 3 5 ; 0 2 0 ]");
    	const Matrix m11 = matrix_by_string("[ -2 5 0 ; 0 1 2323 ]");
    	
		//Act
    	Matrix m2 = m1 * 3;
    	Matrix m12 = -8 * m11;
    	
    	//Assert
    	identical( m2, "[ 3 9 15 ; 0 6 0 ]");
    	identical( m12, "[ 16 -40 0 ; 0 -8 -18584 ]");
    }
    
    void testSubtraction ( ) 
    {
    	//Arrange
    	const Matrix m1 = matrix_by_string("[ 4 2 -1 ; 0 1 0; -8 -2 16 ; 1 1 1 ]");
    	const Matrix m2 = matrix_by_string("[ 7 -8 1 ; 102 90 91 ; -1 -2 -8 ; 7 3 0 ]");
    	
    	//Act
    	const Matrix m00 = m1 - m1;
    	const Matrix m12 = m1 - m2;
    	
    	//Assert
    	identical( m00, "[ 0 0 0 ; 0 0 0 ; 0 0 0 ; 0 0 0 ]");
    	identical( m12, "[ -3 10 -2 ; -102 -89 -91 ; -7 0 24 ; -6 -2 1 ]");
    }
    
    void testNegate ( )
    {
    	//Arrange
    	const Matrix m1 = matrix_by_string("[ 1 1 ]");
    	const Matrix m2 = matrix_by_string("[ 8 9 10 ; 11 12 17 ; -8 -2 -1 ]");
    	
    	//Assert
    	identical( -m1, "[ -1 -1 ]");
    	identical( -m2, "[ -8 -9 -10 ; -11 -12 -17 ; 8 2 1 ]");
    }
    
    void testOutput ( )
    {
    	//Arrange
    	Matrix m1 = matrix_by_string("[ 2 1 8 ; 1 3 3 ]");
    	
    	//Act
    	std::cout << m1 << std::endl;
    	
    	//Assert
    	identical( m1, "[ 2 1 8 ; 1 3 3 ]");
    }
};

#endif
