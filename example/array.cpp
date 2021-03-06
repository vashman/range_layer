//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/array.hpp"
#include "../include/range.hpp"

using std::array;
using range_layer::make_range;

int main (int argc, char** argv){

auto rng = make_range(array<int, 5> {{0, 1, 2, 3, 4}});

int temp;

assert(has_readable(rng));
temp = read(rng);
advance (rng);
assert(temp == 0);

assert(has_readable(rng));
temp = read(rng);
reverse (rng);
assert(temp == 1);

assert(has_writable(rng));
write (rng, 9);
temp = read(rng);
assert(temp == 9);

assert(has_readable(rng));
advance_n(2, rng);
temp = read(rng);
assert(temp == 2);

return 0;
}
