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

#ifndef MOCKMACROS_H
#define	MOCKMACROS_H

/** *******************************************************************************************************************
*  @file     MockMacros.h
*  @date     12/11/2018 2:25:08 PM
*  @brief    Macros for automatically creating CppUTest mocks/fakes.
*  @details  
*  For functions returning void, use 
*		MOCK_VOID_FUNCTION(functionName,param1Type,param1Name,param2Type,param2Name, ... )
*  for example MOCK_VOID_FUNCTION(closeFile,file_t,file)
*  For functions returning a value, use 
*		MOCK_VALUE_FUNCTION(returnType, functionName,returnStatement, param1Type,param1Name,param2Type,param2Name, ... )
*  where returnStatement is something like returnIntValue(), returnDoubleValueOrDefault(3.0) etc (see cpputest mock)
*  for example
*       MOCK_VALUE_FUNCTION(float32_t, sqrtf, returnDoubleValueOrDefault(0.0), float32_t, value)
* 
*  You can also just generate the call to the mock:
*  void putData(uint32_t data, const char * name)
*  {
*      MOCK_ACTUAL_CALL(data, name);
*  }
*
*  And return values from the actual call:
*  uint32_t getData(void)
*  {
*      return MOCK_ACTUAL_CALL().returnUnsignedIntValue();
*  }
**********************************************************************************************************************/


/**********************************************************************************************************************/
/* HELPER MACROS                                                                                                   */
/**********************************************************************************************************************/

#define MOCK_VALUE_FUNCTION_ARG0(returnType, funcname,funcnamequoted,mockReturnFunction) \
returnType funcname( void ) \
{\
	return (returnType)mock().actualCall(funcnamequoted).mockReturnFunction; \
}


#define MOCK_VALUE_FUNCTION_ARG1(returnType, funcname,funcnamequoted,mockReturnFunction,param1type,param1name) \
returnType funcname( param1type param1name ) \
{\
	return (returnType)mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).mockReturnFunction; \
}

#define MOCK_VALUE_FUNCTION_ARG2(returnType, funcname,funcnamequoted,mockReturnFunction,param1type,param1name,param2type,param2name) \
returnType funcname( param1type param1name, param2type param2name ) \
{\
	return (returnType)mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name).mockReturnFunction; \
}

#define MOCK_VALUE_FUNCTION_ARG3(returnType, funcname,funcnamequoted,mockReturnFunction,param1type,param1name,param2type,param2name,param3type,param3name) \
returnType funcname( param1type param1name, param2type param2name, param3type param3name ) \
{\
	return (returnType)mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name).withParameter(#param3name, param3name).mockReturnFunction; \
}

#define MOCK_VALUE_FUNCTION_ARG4(returnType, funcname,funcnamequoted,mockReturnFunction,param1type,param1name,param2type,param2name,param3type,param3name,param4type,param4name) \
returnType funcname( param1type param1name, param2type param2name, param3type param3name, param4type param4name ) \
{\
	return (returnType)mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name).withParameter(#param3name, param3name).withParameter(#param4name, param4name).mockReturnFunction; \
}

#define MOCK_VALUE_FUNCTION_ARG5(returnType, funcname,funcnamequoted,mockReturnFunction,param1type,param1name,param2type,param2name,param3type,param3name,param4type,param4name,param5type,param5name) \
returnType funcname( param1type param1name, param2type param2name, param3type param3name, param4type param4name, param5type param5name ) \
{\
	return (returnType)mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name).withParameter(#param3name, param3name).withParameter(#param4name, param4name).withParameter(#param5name, param5name).mockReturnFunction; \
}

#define MOCK_VALUE_FUNCTION_ARG6(returnType, funcname,funcnamequoted,mockReturnFunction,param1type,param1name,param2type,param2name,param3type,param3name,param4type,param4name,param5type,param5name,param6type,param6name) \
returnType funcname( param1type param1name, param2type param2name, param3type param3name, param4type param4name, param5type param5name, param6type param6name ) \
{\
	return (returnType)mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name).withParameter(#param3name, param3name).withParameter(#param4name, param4name).withParameter(#param5name, param5name).withParameter(#param6name, param6name).mockReturnFunction; \
}

#define MOCK_VOID_FUNCTION_ARG0(funcname,funcnamequoted) \
void funcname( void ) \
{\
	mock().actualCall(funcnamequoted); \
}

#define MOCK_VOID_FUNCTION_ARG1(funcname,funcnamequoted, param1type, param1name) \
void funcname( param1type param1name ) \
{\
	mock().actualCall(funcnamequoted).withParameter(#param1name, param1name); \
}

#define MOCK_VOID_FUNCTION_ARG2(funcname,funcnamequoted,param1type, param1name, param2type, param2name) \
void funcname( param1type param1name, param2type param2name ) \
{\
	mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name); \
}

#define MOCK_VOID_FUNCTION_ARG3(funcname, funcnamequoted, param1type, param1name, param2type, param2name, param3type, param3name) \
void funcname( param1type param1name, param2type param2name, param3type param3name ) \
{\
	mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name)\
		.withParameter(#param3name, param3name); \
}

#define MOCK_VOID_FUNCTION_ARG4(funcname, funcnamequoted, param1type, param1name, param2type, param2name, param3type, param3name, param4type, param4name) \
void funcname( param1type param1name, param2type param2name, param3type param3name, param4type param4name ) \
{\
	mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name)\
		.withParameter(#param3name, param3name).withParameter(#param4name, param4name); \
}

#define MOCK_VOID_FUNCTION_ARG5(funcname, funcnamequoted, param1type, param1name, param2type, param2name, param3type, param3name, param4type, param4name, param5type, param5name) \
void funcname( param1type param1name, param2type param2name, param3type param3name, param4type param4name, param5type param5name ) \
{\
	mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name)\
		.withParameter(#param3name, param3name).withParameter(#param4name, param4name)\
		.withParameter(#param5name, param5name); \
}

#define MOCK_VOID_FUNCTION_ARG6(funcname, funcnamequoted, param1type, param1name, param2type, param2name, param3type, param3name, param4type, param4name, param5type, param5name, param6type, param6name) \
void funcname( param1type param1name, param2type param2name, param3type param3name, param4type param4name, param5type param4name, param5type param6name ) \
{\
	mock().actualCall(funcnamequoted).withParameter(#param1name, param1name).withParameter(#param2name, param2name)\
		.withParameter(#param3name, param3name).withParameter(#param4name, param4name)\
		.withParameter(#param5name, param5name).withParameter(#param6name, param6name); \
}

#define MOCK_ACTUAL_CALL_ARG0(funcName) mock().actualCall(funcName)
#define MOCK_ACTUAL_CALL_ARG1(funcName,param1) mock().actualCall(funcName).withParameter(#param1,param1)
#define MOCK_ACTUAL_CALL_ARG2(funcName,param1,param2) mock().actualCall(funcName).withParameter(#param1,param1).withParameter(#param2,param2)
#define MOCK_ACTUAL_CALL_ARG3(funcName,param1,param2,param3) mock().actualCall(funcName).withParameter(#param1,param1).withParameter(#param2,param2)\
.withParameter(#param3,param3)
#define MOCK_ACTUAL_CALL_ARG4(funcName,param1,param2,param3,param4) mock().actualCall(funcName).withParameter(#param1,param1).withParameter(#param2,param2)\
.withParameter(#param3,param3).withParameter(#param4,param4)
#define MOCK_ACTUAL_CALL_ARG5(funcName,param1,param2,param3,param4,param5) mock().actualCall(funcName).withParameter(#param1,param1)\
.withParameter(#param2,param2).withParameter(#param3,param3).withParameter(#param4,param4).withParameter(#param5,param5)
#define MOCK_ACTUAL_CALL_ARG6(funcName,param1,param2,param3,param4,param5,param6) mock().actualCall(funcName).withParameter(#param1,param1)\
.withParameter(#param2,param2).withParameter(#param3,param3).withParameter(#param4,param4).withParameter(#param5,param5)\
.withParameter(#param6,param6)

#define EX(x) x
#define W_ wrong_number_of_arguments
#define NARG_MINUS1_DIV2(...) EX(NARG_MINUS1_DIV2_(__VA_ARGS__,6,EX(W_),5,EX(W_),4,EX(W_),3,EX(W_),2,EX(W_),1,EX(W_),0,EX(W_)))
#define NARG_MINUS1_DIV2_(dummy,a,aa,b,bb,c,cc,d,dd,e,ee,f,ff,N,...) N
#define NARG_MINUS_1(...) EX(NARG_MINUS_1_(__VA_ARGS__, 6,5,4,3,2,1,0))
#define NARG_MINUS_1_(dummy,a,b,c,d,e,f,N,...) N


#ifdef _MSC_VER
/* Thanks to "ceztko" for providing argument count that works with zero arguments in MSVC */
#define __NARGS(_1, _2, _3, _4, _5, _6, _7, VAL, ...) VAL
#define NARGS_1(...) EX(__NARGS(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0))

#define AUGMENTER(...) unused, __VA_ARGS__
#define NARGS(...) NARGS_1(AUGMENTER(__VA_ARGS__))
#endif

#define VOID_FUNC_(funcnamequoted,func_name,N,...) VOID_FUNC_N(funcnamequoted,func_name, N,__VA_ARGS__)
#define VOID_FUNC_N(funcnamequoted,func_name,N,...) EX(MOCK_VOID_FUNCTION_ARG ## N(func_name,funcnamequoted, __VA_ARGS__ ))

#define VALUE_FUNC_(funcNameQuoted,funcName,returnType,N,...) VALUE_FUNC_N(returnType,funcName,funcNameQuoted,N,__VA_ARGS__)
#define VALUE_FUNC_N(returnType,funcName,funcNameQuoted,N,...) EX(MOCK_VALUE_FUNCTION_ARG ## N(returnType,funcName,funcNameQuoted,__VA_ARGS__ ))

#define ACTUAL_CALL_(N,...) ACTUAL_CALL_N(N,__VA_ARGS__)
#define ACTUAL_CALL_N(N,funcName,...) EX(MOCK_ACTUAL_CALL_ARG ## N(funcName,__VA_ARGS__))

#define MOCK_VOID_FUNC_INDIRECT(N, funcName, ...) VOID_FUNC_N(#funcName,funcName,N,__VA_ARGS__)


/**********************************************************************************************************************/
/* MAIN MACROS                                                                                                        */
/**********************************************************************************************************************/


/* GCC, clang and intel all support the symbol ##__VA_ARGS__, which is empty when no arguments are given.
* MSVC allows it, but does not give it a special meaning. But MSVC has other quirks we can exploit. */
#if defined _MSC_VER || defined __GNUC__ || defined __clang__ 

#ifdef _MSC_VER
#define MOCK_ACTUAL_CALL(...) ACTUAL_CALL_(EX(NARGS(__VA_ARGS__)),__FUNCTION__,__VA_ARGS__)
#else
#define MOCK_ACTUAL_CALL(...) MOCK_ACTUAL_NAMED_CALL(__FUNCTION__,##__VA_ARGS__)
#endif

/* By placing #func_name first, we stop the preprocessor from expanding it further, thus, if the
 * preprocesor is used to rename the function (for fake injection), the name seen by the mock will still be 
 * the original name.*/
#define MOCK_VOID_FUNCTION(func_name, ...) VOID_FUNC_(#func_name,func_name,NARG_MINUS1_DIV2(dummy,##__VA_ARGS__),__VA_ARGS__)

#else 

/* These ones will unfortunately fail if given zero function parameters. You can use MOCK_ACTUAL_CALL_NOPARAMS/MOCK_VOID_FUNCTION_NOPARAMS instead*/
#define MOCK_VOID_FUNCTION(func_name, ...) VOID_FUNC_(#func_name,func_name,NARG_MINUS1_DIV2(dummy,__VA_ARGS__),__VA_ARGS__)
#define MOCK_ACTUAL_CALL(...) MOCK_ACTUAL_NAMED_CALL(__FUNCTION__,__VA_ARGS__)
#endif

#define MOCK_VALUE_FUNCTION(returnType, funcName, ...) VALUE_FUNC_(#funcName,funcName,returnType,EX(NARG_MINUS1_DIV2(__VA_ARGS__)),__VA_ARGS__)

/** Use this with a function name in quotes as the first argument if you want to use a different name than what 
* __FUNCTION__ will expand to.
*/
#define MOCK_ACTUAL_NAMED_CALL(...) ACTUAL_CALL_(EX(NARG_MINUS_1(__VA_ARGS__)),__VA_ARGS__)

/** These are here for platform independence. */
#define MOCK_ACTUAL_CALL_NOPARAMS() ACTUAL_CALL_N(0,__FUNCTION__)
#define MOCK_VOID_FUNCTION_NOPARAMS(func_name) VOID_FUNC_(#func_name,func_name,0)

/* Unlike MOCK_VOID_FUNCTION, this one will input the final name of the function to the mock if the name has been changed by the preprocessor.
 * also, it works on all platforms even for zero function parameters. */
#define MOCK_VOID_FUNCTION2(...) EX(MOCK_VOID_FUNC_INDIRECT(NARG_MINUS1_DIV2(__VA_ARGS__),__VA_ARGS__))

#endif	/* End include guard */
