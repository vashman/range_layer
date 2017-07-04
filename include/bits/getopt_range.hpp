//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GETOPT_RANGE_HPP
#define RANGE_LAYER_GETOPT_RANGE_HPP

#include <string>

namespace range_layer {

class getopt_range {

int local_optind;
std::string local_opts;
int local_argc;
program_option option;
char *const * local_argv;
int rv;

public:

using read_type = char;
static constexpr std::size_t max_size
  = std::numeric_limits<std::size_t>::max();

getopt_range (
  char * const *
, std::string
, int
);

getopt_range (getopt_range const &) = default;
getopt_range (getopt_range &&) = default;
~getopt_range() = default;
getopt_range & operator = (getopt_range const &) = default;
getopt_range & operator = (getopt_range &&) = default;

program_option & operator * ();
getopt_range & operator ++ ();
bool operator == (sentinel::readable const) const;

};

} /* range layer */
#endif
