//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include "../include/vector.hpp"
#include "../include/string.hpp"
#include "../include/algorithm.hpp"
#include "../include/stream.hpp"

using std::string;
using std::vector;
using range_layer::range;
using range_layer::xrange;
using range_layer::make_as_range;
using range_layer::execution_policy::sequenced;

int main (){

vector<string> vec {"test: A", " test: B", " Test: c"};

/*write (
  sequenced{}
, range(std::cout)
, xrange (
    range(vec)
  , make_as_range (
    static_cast<decltype(range(vec))(*)(vector<string>&)>
    (range_layer::range)
    )
  )
);*/

return 0;
}