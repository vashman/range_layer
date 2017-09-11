//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/array_range.hpp"
#include "../include/stream.hpp"
#include "../include/range.hpp"
#include "../include/algorithm.hpp"

using range_layer::range;

int main (){

range_layer::execution_policy::sequenced seq{};
char arr[]
  = "Press the a button and press enter to continue.";

auto r_output = range(std::cout);
write(seq, r_output, range(arr, 47));

auto r_input = range(std::cin);
write(r_output, read(r_input));

return 0;
}
