//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <array>
#include "../include/array_range.hpp"

using std::array;
using range_layer::array_range;

int main (){
array<int, 5> arr {{0, 1, 2, 3, 4}};
array_range<int> rng {arr.data(), arr.data()+arr.size()};

int temp;

assert(has_readable(rng));
temp = read(rng);
rng = next(rng);
assert(temp == 0);

temp = read(rng);
rng = prev (rng);
assert(temp == 1);

assert(has_writable(rng));
write (rng, 9);
temp = read(rng);
assert(temp == 9);

assert(has_readable(rng));
temp = read(next(rng, 2));
assert(temp == 2);

return 0;
}
