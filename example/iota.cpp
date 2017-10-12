//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/range.hpp"

using range_layer::make_range;
using range_layer::iota;
//using range_layer::has_readable;
//using range_layer::read;
//using range_layer::next;
//using range_layer::prev;

int main (int argc, char** argv){
auto rng = make_range(iota<int>{0});

assert(has_readable(rng));
int temp = read(rng);
advance(rng);
assert(temp == 0);

assert(has_readable(rng));
temp = read(rng);
assert(temp == 1);
advance_n(100, rng);

assert(has_readable(rng));
temp = read(rng);
assert(temp == 101);

reverse(rng);
assert(has_readable(rng));
temp = read(rng);
assert(temp == 100);

return 0;
}
