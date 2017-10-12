//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <iostream>
#include "../include/range.hpp"

using range_layer::make_range;
using range_layer::enable_range::iterator;

int main (){
int arr[10] = {1,2,3,4,5,6,7,8,9,10};

auto rng = make_range (
  std::begin(arr)
, iterator<decltype(std::end(arr))>{std::end(arr)}
);

assert(has_writable(rng));
rng.write(12);
rng.advance();
assert(has_writable(rng));
rng.write(13);
rng.advance();

for (auto x : arr){
std::cout << "arr is: " << x << std::endl;
}

return 0;
}
