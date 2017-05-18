//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_CONSOLE_RANGE_HPP
#define RANGE_LAYER_CONSOLE_RANGE_HPP

#include "iterator_range.hpp"
#include <iostream>
#include <iterator>

namespace range_layer {

iterator_range<std::istream_iterator<char>>
input_console_range (){
return make_iterator_range (
  std::istream_iterator<char>{std::cin}
, std::istream_iterator<char>{}
);
}

iterator_range<std::ostream_iterator<char>, void>
output_console_range (){
return make_iterator_range (
  std::ostream_iterator<char>{std::cout} );
}

} /* range layer */
#endif

