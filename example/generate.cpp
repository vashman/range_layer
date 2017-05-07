//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/generate_range.hpp"
#include "../include/range.hpp"

using range_layer::make_generate_range;

struct gen {

int temp = 1;
int operator ()(){return this->temp++;}

};

int main (){

auto rng = make_generate_range (gen());

assert (read(rng) == 1);
rng = next(rng);
assert (read(rng) == 2);

return 0;
}