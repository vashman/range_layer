//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/range.hpp"

using range_layer::range;
using range_layer::has_readable;
using range_layer::read;
using range_layer::next;
using range_layer::make_generator;

struct gen {

int temp = 1;
int operator ()(){return this->temp++;}

};

int main (){

auto rng = range(make_generator(gen()));

assert (has_readable(rng));
assert (read(rng) == 1);

rng = next(2, rng);

assert (has_readable(rng));
assert (read(rng) == 3);

return 0;
}
