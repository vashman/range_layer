//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <cassert>
#include <string>
#include "../include/vector.hpp"
#include "../include/algorithm.hpp"

using std::vector;
using range_layer::fill;
using range_layer::has_readable;
using range_layer::has_writable;
using range_layer::advance;
using range_layer::reverse;
using range_layer::range;
using range_layer::execution_policy::sequenced;
using range_layer::read;
using range_layer::write;

int main (){
auto rng = range(vector<int>{10});
rng = fill(sequenced{}, std::move(rng), 99);

while (has_readable(rng)){
assert (99 == read(rng));
advance(rng);
}

reverse(rng);
assert (has_writable(rng));
write(rng, 400);

auto r_string = range(vector<std::string>{"testing"});

return 0;
}