//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#include <cassert>
#include "../include/vector.hpp"
#include "../include/algorithm.hpp"

using std::vector;
using range_layer::fill;
using range_layer::has_readable;
using range_layer::has_writable;
using range_layer::advance;
using range_layer::reverse;
using range_layer::make_range;
using range_layer::execution_policy::sequenced;
using range_layer::read;
using range_layer::write;

template <typename Range>
void write_test (Range &&);

template <typename Range>
void read_test (Range &&);

int main (){

auto srng = make_range(std::make_shared<vector<int>>());
auto urng = make_range(std::make_unique<vector<int>>());

vector<int> type;
auto rng2 = make_range(type);

auto rng = make_range(vector<int>{10});

read_test(srng);
write_test(move(urng));
read_test(move(rng2));
write_test(move(rng));

return 0;
}

template <typename Range>
void
write_test (
  Range && _range
){
fill(sequenced{}, _range, 99);

while (has_readable(_range)){
assert (99 == read(_range));
advance(_range);
}
  if (has_writable(_range)){
  reverse(_range);
  assert (has_writable(_range));
  write(_range, 400);
  }
}

template <typename Range>
void
read_test (
  Range && _range
){
while (has_readable(_range)){
assert (99 == read(_range));
advance(_range);
}
}