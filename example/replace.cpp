//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/iota_range.hpp"
#include "../include/array_range.hpp"
#include "../include/replace_range.hpp"
#include "../include/range.hpp"

using range_layer::iota_range;
using range_layer::array_range;
using range_layer::make_input_replace_range;
using range_layer::make_output_replace_range;

int main (){

auto rng = make_input_replace_range (
  iota_range<int> {2}
, 4
, 999
);

assert (read(rng) == 2);
advance(rng);
assert (read(rng) == 3);
advance(rng);
assert (read(rng) == 999);

int arr [5] = {10, 11, 12, 13, 14};

auto rng2 = make_output_replace_range (
  array_range<int> {arr, arr+5}
, 888
, 999
);

assert (read(rng2) == 10);
advance(rng2);
assert (read(rng2) == 11);
advance_prev(rng2);
write (rng2, 888);
assert (read(rng2) == 999);

return 0;
}
