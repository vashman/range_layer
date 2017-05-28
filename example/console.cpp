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
using range_layer::input_console_range;
using range_layer::output_console_range;

int main (){

range_layer::execution_policy::sequenced seq{};
char arr[] = "Press a button and press enter to continue.";
array_range<char> rng {arr, arr + 43};

auto out = output_console_range();
write(seq, rng, out);
auto in = input_console_range();
write(out, read(in));

return 0;
}
