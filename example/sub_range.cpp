//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <array>
#include "../include/sub_range.hpp"
#include "../include/array_range.hpp"
#include "../include/range.hpp"
#include "../include/algorithm.hpp"

using std::array;
using range_layer::array_range;
using range_layer::sub_range_n;

int main (){
range_layer::execution_policy::sequenced seq{};
array<int, 7> arr {{0, 1, 2, 3, 4, 5, 6}};

auto arr_rng = sub_range_n (
  next(array_range<int> {arr.data(), arr.data()+arr.size()})
, 3
);

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
