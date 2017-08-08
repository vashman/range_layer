//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <array>
#include "../include/array_range.hpp"
#include "../include/range.hpp"
#include "../include/algorithm.hpp"

using std::array;
using range_layer::range;
using range_layer::has_writable;

int main (){
auto rng = range(array<int, 5> {{0, 1, 2, 3, 4}});

assert (has_writable(rng));
write (rng, 99);
advance (rng);
write (
  range_layer::execution_policy::sequenced{}
, rng
, 400
, range(array<int, 5> {{0, 1, 2, 3, 4}})
, range(array<int, 5> {{0, 1, 2, 3, 4}})
, range(array<int, 5> {{0, 1, 2, 3, 4}})
);

reverse (rng);
assert (read(rng) == 99);
advance (rng);
assert (read(rng) == 400);
advance (rng);
assert (read(rng) == 0);

return 0;
}
