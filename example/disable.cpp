//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <array>
#include "../include/array_range.hpp"
#include "../include/console_range.hpp"
#include "../include/range.hpp"
#include "../include/algorithm.hpp"

using std::array;
using range_layer::array_range;
using range_layer::output_console_range;

int main (){
array<char, 5> arr {{'a', 'e', 'i', 'o', 'u'}};
array_range<char> rng {arr.data(), arr.data()+arr.size()};

write (
  range_layer::execution_policy::sequenced {}
, output_console_range()
, disable_decorator (
    sub_range_n(sub_range_n(rng, 4), 2)
  )
);

write (
  range_layer::execution_policy::sequenced {}
, output_console_range()
, disable_decorator ( remove_decorator (
    sub_range_n(sub_range_n(rng, 4), 2)
  ))
);

return 0;
}
