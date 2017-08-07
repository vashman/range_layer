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
#include "../include/console_range.hpp"

using std::vector;
using range_layer::make_iterator_range;
using range_layer::output_console_range;

int main (){
vector<char> vec {'0', '1', '2', '3', '4'};

auto rng = make_iterator_range(begin(vec), end(vec));
auto con = output_console_range();

range_layer::execution_policy::sequenced seq {};

write (seq, con, rng);

return 0;
}
