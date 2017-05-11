//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <iostream>
#include <limits>
#include "../include/range.hpp"
#include "../include/iota_range.hpp"
#include "../include/reverse_range.hpp"

using std::numeric_limits;
using range_layer::iota_range;
using range_layer::reverse_range;

int main (){

int count = numeric_limits<int>::min() + 10;
auto range = reverse_range (iota_range<int>{count});

while (has_readable(range)){
assert(read(range) == count);
std::cout << read(range);
range = next(range);
--count;
}

return 0;
}
