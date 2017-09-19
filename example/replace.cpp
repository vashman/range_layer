//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/array.hpp"
#include "../include/range.hpp"

using range_layer::iota;
using range_layer::range;
using range_layer::xrange;
using range_layer::make_replace_read;
using range_layer::make_replace_if_read;
using range_layer::make_replace_write;
using range_layer::make_replace_if_write;
using range_layer::advance;
using range_layer::reverse;
using range_layer::has_readable;
using range_layer::has_writable;
using range_layer::read;
using range_layer::write;

int main (){

auto rng = xrange (
  range(iota<int> {2})
, make_replace_read (4, 999)
);

assert (has_readable(rng));
assert (read(rng) == 2);
advance(rng);

assert (has_readable(rng));
assert (read(rng) == 3);
advance(rng);

assert (has_readable(rng));
assert (read(rng) == 999);

int arr [5] = {10, 11, 12, 13, 14};

auto rng2 = xrange (
  range(arr, 5)
, make_replace_write (888, 999)
);

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
