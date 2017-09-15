//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <functional>
#include "../include/vector_range.hpp"
#include "../include/string.hpp"
#include "../include/algorithm.hpp"
#include "../include/stream.hpp"

using std::string;
using std::vector;
using std::function;
using range_layer::range;
using range_layer::as_range;
using range_layer::execution_policy::sequenced;

int main (){

vector<string> vec{"test: A", "test: B", "Test: c"};

function<decltype(range(vec))(vector<string>&)> func
  = static_cast<decltype(range(vec))(vector<string>&)>(range_layer::range);
auto output = range(std::cout);
auto input = as_range(range(vec), func);

//write (sequenced{}, ,);

return 0;
}