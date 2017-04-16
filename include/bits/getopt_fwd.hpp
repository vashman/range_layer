//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GETOPT_FWD_HPP
#define RANGE_LAYER_GETOPT_FWD_HPP

namespace range_layer {

struct program_option;
class getopt_range;

program_option
read (
  getopt_range
);

getopt_range
next (
  getopt_range
, int _n = 1
);

bool
has_readable (
  getopt_range const
);

} /* range layer */
#endif
