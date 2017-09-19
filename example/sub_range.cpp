//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/array.hpp"
#include "../include/range.hpp"
#include "../include/algorithm.hpp"

#include <iostream>

using std::array;
using range_layer::range;
using range_layer::make_sub_range_n;
using range_layer::make_sub_range;
using range_layer::has_readable;
using range_layer::has_writable;
using range_layer::read;
using range_layer::write;
using range_layer::prev;
using range_layer::next;
using range_layer::advance;
using range_layer::for_each;

int main (){
range_layer::execution_policy::sequenced seq{};
array<int, 7> arr {{0, 1, 2, 3, 4, 9, 10}};

/*auto rng = xrange (range(arr), make_sub_range(4));

for (int i = 0; has_readable(rng); ++i){
assert (read(rng) == i);
advance(rng);
}*/

auto arr_rng = xrange(next(range(arr)), make_sub_range_n(4));

assert(has_readable(arr_rng));
assert(read(arr_rng) == 1);
advance(arr_rng);
assert(read(arr_rng) == 2);

arr_rng = prev (arr_rng);

assert(has_writable(arr_rng));
write (arr_rng, 9);
assert(read(arr_rng) == 9);
advance(arr_rng);

int temp = 2;
for_each (
  seq
, arr_rng
, [&](int _var){assert(_var == temp++);}
);

return 0;
}
