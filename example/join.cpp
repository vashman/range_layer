//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/range.hpp"
#include "../include/iota_range.hpp"
#include "../include/join.hpp"

using range_layer::iota_range;
using range_layer::join;
using std::get;

int main (int arc, char** argv){
auto rng = join (iota_range<int> {65}, iota_range<int> {0});

assert(has_readable(rng));

auto temp = read(rng);
rng = next(rng);
assert(get<0>(temp) == 65);
assert(get<1>(temp) == 0);

temp = read(rng);
assert(get<0>(temp) = 66);
assert(get<1>(temp) == 1);

rng = next(100, rng);
temp = read(rng);
assert(get<0>(temp) == 166);
assert(get<1>(temp) == 101);

rng = prev (rng);
temp = read(rng);
assert(get<0>(temp) == 165);
assert(get<1>(temp) == 100);

return 0;
}
