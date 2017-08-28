//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/range.hpp"
#include "../include/iota_range.hpp"

using range_layer::iota_range;

int main (int arc, char** argv){
iota_range<int> rng {65};

assert(has_readable(rng));
int temp = read(rng);
rng = next(rng);
assert(temp == 65);

temp = read(rng);
assert(temp == 66);

rng = next(100, rng);
assert(has_readable(rng));
temp = read(rng);
assert(temp == 166);

rng = prev (rng);
assert(has_readable(rng));
temp = read(rng);
assert(temp == 165);

return 0;
}
