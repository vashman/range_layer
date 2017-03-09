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

static constexpr bool const is_output = false;
static constexpr bool const is_input = true;
static constexpr bool const is_input_contiguous = false;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_input_size_known = false;
static constexpr bool const is_input_position_known = false;
static constexpr bool const is_output_contiguous = false;
static constexpr bool const is_output_temporary = false;
static constexpr bool const is_output_size_known = false;
static constexpr bool const is_output_position_known= false;
static constexpr bool const is_reversable = false;
using difference_type = std::size_t;

getopt_range (
  char *const *
, std::string
, int
);

getopt_range (getopt_range const &) = default;
getopt_range (getopt_range &&) = default;
~getopt_range() = default;
getopt_range & operator = (getopt_range const &) = default;
getopt_range & operator = (getopt_range &&) = default;

friend program_option read (getopt_range);
friend bool is_readable (getopt_range const);
friend getopt_range next (getopt_range, difference_type _n);
friend getopt_iterator begin (getopt_range &);
friend getopt_iterator end (getopt_range const &);

};

} /* range layer */
#endif
