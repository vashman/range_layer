//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_PROGRAM_OPTION_HPP
#define RANGE_LAYER_PROGRAM_OPTION_HPP

#include <tuple>
#include <string>

namespace range_layer {

struct program_option {

std::tuple <char, std::string> option;

bool
has_arg () const;

char &
get_option ();

std::string &
get_arg ();

program_option (
  char
);

program_option (
  char
, std::string
);

program_option (program_option const &) = default;
program_option (program_option &&) = default;

program_option &
operator = (program_option const &) = default;

program_option &
operator = (program_option &&) = default;

~program_option() = default;
program_option() = default;

}; /* program option */

} /* range layer */
#endif
