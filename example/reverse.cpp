//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <limits>
#include "../include/range.hpp"

using std::numeric_limits;
using range_layer::iota;
using range_layer::xrange;
using range_layer::has_readable;
using range_layer::backward;
using range_layer::advance;
using range_layer::read;

int main (){

int count = numeric_limits<int>::min() + 10;
auto rng = xrange (
  range (iota<int>{count})
, backward {}
);

while (has_readable(rng)){
assert(read(rng) == count);
advance(rng);
--count;
}

return 0;
}
