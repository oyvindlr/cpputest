
/*
* Copyright (c) 2018, Michael Feathers, James Grenning and Bas Vodde
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of the <organization> nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockMacros.h"

TEST_GROUP(MockMacrosTest)
{
	void teardown()
	{
		mock().checkExpectations();
	}
};


void actualCallWithNoParams( void )
{
	MOCK_ACTUAL_CALL();
}

TEST( MockMacrosTest, ActualCallWithNoParams )
{
	mock( ).expectOneCall( "actualCallWithNoParams" );
	
	actualCallWithNoParams( );
}


void actualCallWithParams( int p1, int * p2 )
{
	MOCK_ACTUAL_CALL( p1, p2 );
}

TEST( MockMacrosTest, ActualCallWithParams )
{
	mock( ).expectOneCall( "actualCallWithParams" ).withIntParameter( "p1", 1 ).withPointerParameter( "p2", (int*)2 );

	actualCallWithParams(1, (int*)2);
}

int actualCallWithParamsAndReturn( int p1 )
{
	return MOCK_ACTUAL_CALL( p1 ).returnIntValue( );
}

TEST( MockMacrosTest, ActualCallWithReturn )
{
	mock( ).expectOneCall( "actualCallWithParamsAndReturn" ).withIntParameter( "p1", 1 ).andReturnValue( 2 );

	int result = actualCallWithParamsAndReturn( 1 );

	CHECK_EQUAL( 2, result );
}

#define initialName finalName

void initialName( )
{
	MOCK_ACTUAL_NAMED_CALL( "initialName" );
}

TEST( MockMacrosTest, ActualNamedCall )
{
	mock( ).expectOneCall( "initialName" );

	finalName( );
}

void realName( int a, int b, int c, int d, int e, int f )
{
	MOCK_ACTUAL_NAMED_CALL( "anotherName", a, b, c, d, e, f );
}

TEST( MockMacrosTest, ActualNamedCallWithParameters )
{
	mock( ).expectOneCall( "anotherName" ).withParameter( "a", 1 ).withParameter( "b", 2 ).withParameter( "c", 3 )
		.withParameter( "d", 4 ).withParameter( "e", 5 ).withParameter( "f", 6 );

	realName( 1, 2, 3, 4, 5, 6 );
}

MOCK_VOID_FUNCTION( voidFuncNoParams )

TEST( MockMacrosTest, MockVoidFunctionNoParams )
{
	mock( ).expectOneCall( "voidFuncNoParams" );

	voidFuncNoParams( );
}

MOCK_VOID_FUNCTION( voidFunc2Params, int, p1, void *, p2, double, p3 )

TEST( MockMacrosTest, MockVoidFunctionWith2Params )
{
	mock( ).expectOneCall( "voidFunc2Params" ).withIntParameter( "p1", 1 ).withPointerParameter( "p2", (void*)2 ).withDoubleParameter( "p3", 3.0 );

	voidFunc2Params( 1, (void*)2, 3.0 );
}

#define funcWithRedefinedName mockedFuncWithRedefinedName

MOCK_VOID_FUNCTION( funcWithRedefinedName )

TEST( MockMacrosTest, ActualCallUsesOriginalNameEvenIfRedefined )
{
	mock( ).expectNCalls(2, "funcWithRedefinedName" );

	funcWithRedefinedName( );
	mockedFuncWithRedefinedName( );
}

MOCK_VALUE_FUNCTION( char, charFunctionNoParams, returnIntValue())

TEST( MockMacrosTest, ValueFunctionNoParams )
{
	mock( ).expectOneCall( "charFunctionNoParams" ).andReturnValue( 'F' );

	char result = charFunctionNoParams( );

	CHECK_EQUAL( 'F', result );
}

MOCK_VALUE_FUNCTION( void *,pointerFunctionWithParams, returnPointerValue(), int, a, int, b, int, c, int, d, int, e, int, f)


TEST( MockMacrosTest, ValueFunctionWithParams )
{
	mock( ).expectOneCall( "pointerFunctionWithParams" ).withParameter( "a", 1 ).withParameter( "b", 2 ).withParameter( "c", 3 )
		.withParameter( "d", 4 ).withParameter( "e", 5 ).withParameter( "f", 6 ).andReturnValue( (void *)7 );

	void * result = pointerFunctionWithParams( 1, 2, 3, 4, 5, 6 );

	CHECK_EQUAL( (void*)7, result );
}
#define voidFunction2OriginalName voidFunction2FinalName

MOCK_VOID_FUNCTION2(voidFunction2OriginalName)

TEST( MockMacrosTest, voidFunction2UsesFinalName )
{
	mock( ).expectOneCall( "voidFunction2FinalName" );
	
	voidFunction2OriginalName( );
}

MOCK_VOID_FUNCTION2( voidFunction2WithParams, int, a, int, b, int, c, int, d )

TEST( MockMacrosTest, voidFunction2WithParams )
{
	mock( ).expectOneCall( "voidFunction2WithParams" ).withParameter( "a", 1 ).withParameter( "b", 2 ).withParameter( "c", 3 )
		.withParameter( "d", 4 );

	voidFunction2WithParams(1, 2,3,4 );
}