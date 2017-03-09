//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GETOPT_FWD_HPP
#define RANGE_LAYER_GETOPT_FWD_HPP

#include <cstddef>

namespace range_layer {

struct program_option;
class getopt_iterator;
class getopt_range;

program_option
read (
  getopt_range _range
);

getopt_range
next (
  getopt_range _range
, std::size_t _n = 1
);

bool
is_readable (
  getopt_range const _range
);

getopt_iterator
end (
  getopt_range const & _range
);

getopt_iterator
begin (
  getopt_range & _range
);

} /* range layer */
#endif