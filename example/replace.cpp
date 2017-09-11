//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/iota_range.hpp"
#include "../include/array_range.hpp"
#include "../include/range.hpp"

using range_layer::iota_range;
using range_layer::range;
using range_layer::input_replace;
using range_layer::input_replace_if;
using range_layer::output_replace;
using range_layer::output_replace_if;
using range_layer::advance;
using range_layer::reverse;

int main (){

auto rng = input_replace (iota_range<int> {2}, 4, 999);

assert (has_readable(rng));
assert (read(rng) == 2);
advance(rng);

assert (has_readable(rng));
assert (read(rng) == 3);
advance(rng);

assert (has_readable(rng));
assert (read(rng) == 999);

int arr [5] = {10, 11, 12, 13, 14};

auto rng2 = output_replace (range(arr, 5), 888, 999);

assert (has_readable(rng2));
assert (read(rng2) == 10);
advance(rng2);

assert (has_readable(rng2));
assert (read(rng2) == 11);
reverse(rng2);

assert (has_writable(rng2));
write (rng2, 888);

assert (has_readable(rng2));
assert (read(rng2) == 999);

/*auto rng3 = output_replace_if (
  array_range<int> {arr, arr+5}
, [](int _value){return (_value%2)==0;}
, 999
);

write (rng3, 43);
assert (read(rng3) == 43);
advance(rng3);
write (rng3, 2);
assert (read(rng3) == 999);*/

return 0;
}
