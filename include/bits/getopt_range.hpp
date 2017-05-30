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
static constexpr bool const is_linear = true;
static constexpr bool const is_erasable = false;
static constexpr bool const is_insertable = false;
static constexpr bool const is_reversable = false;
static constexpr bool const is_io_synced = false;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_output_temporary = false;

static constexpr validation_type const
  validation = validation_type::single;

static constexpr range_size const
  input_size_type = range_size::countable;

static constexpr range_size const
  output_size_type = range_size::countable;

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
