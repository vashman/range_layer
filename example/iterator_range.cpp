//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <vector>
#include <iostream>
#include "../include/algorithm.hpp"
#include "../include/iterator_range.hpp"
#include "../include/stream.hpp"

using std::vector;
using range_layer::make_iterator_range;
using range_layer::range;

int main (){
vector<char> vec {'0', '1', '2', '3', '4'};

write (
  range_layer::execution_policy::sequenced {}
, range(std::cout)
, make_iterator_range(begin(vec), end(vec))
);

return 0;
}
