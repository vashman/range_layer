//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <iostream>
#include <tuple>
#include "../include/generate_range.hpp"
#include "../include/range.hpp"

using range_layer::make_generate_range;
using range_layer::typelist;
using std::tuple;
using std::get;
using range_layer::range_trait::input::is_heterogeneous;

struct gen {

tuple<int, char> temp = std::make_tuple(1, 'a');

tuple<int, char> operator ()(){
get<0>(this->temp) += 1;
get<1>(this->temp) += 1;
return this->temp;
}

};

int main (){

auto rng = make_generate_range (gen());

assert (has_readable(rng));
auto var = read(rng);

static_assert (
  std::is_same<decltype(var), tuple<int, char>>::value
, "Not same type"
);

static_assert (
  range_layer
  ::range_trait
  ::input
  ::is_heterogeneous<decltype(rng)>::value
, "Must return multiple types as tuple."
);

assert (get<0>(var) == 2);
assert (get<1>(var) == 'b');

rng = next(2, rng);

assert (has_readable(rng));
var = read(rng);

assert (get<0>(var) == 4);
assert (get<1>(var) == 'd');

return 0;
}