//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <string>
#include "../include/string.hpp"
#include "../include/algorithm.hpp"

using std::string;
using range_layer::fill;
using range_layer::range;
using range_layer::execution_policy::sequenced;

int main (){
string var {"Here is a string."};
fill(sequenced{}, range(var), 'A');

return 0;
}