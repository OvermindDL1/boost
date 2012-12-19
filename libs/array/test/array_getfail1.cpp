/* tests using std::get on boost:array
 * (C) Copyright Marshall Clow 2012
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <string>
#include <iostream>
#include <algorithm>
#ifndef BOOST_NO_CXX11_HDR_ARRAY
#include <array>
#endif

#include <boost/array.hpp>
#include <boost/static_assert.hpp>


#include <boost/test/included/test_exec_monitor.hpp>

namespace {

    #ifndef BOOST_NO_CXX11_HDR_ARRAY
    template< class T >
    void    RunStdTests()
    {
        typedef boost::array< T, 5 >    test_type;
        typedef T arr[5];
        test_type           test_case; //   =   { 1, 1, 2, 3, 5 };
    
        T &aRef = std::get<5> ( test_case );	// should fail to compile
        BOOST_CHECK ( &*test_case.begin () == &aRef );
    }
    #endif

}

int test_main( int , char* [] )
{

#ifndef BOOST_NO_CXX11_HDR_ARRAY
    RunStdTests< bool >();
    RunStdTests< void * >();
    RunStdTests< long double >();
    RunStdTests< std::string >();
#else
	BOOST_STATIC_ASSERT ( false );	// fail on C++03 systems.
#endif
    return 0;
}
