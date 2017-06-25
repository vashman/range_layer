//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GENERATE_RANGE_TCC
#define RANGE_LAYER_GENERATE_RANGE_TCC

#include "range_traits.hpp"

namespace range_layer {

template <typename Gen>
class generate_range {

Gen gen;
bool flag;

public:

using read_type = decltype(gen());
using write_type = void;

static constexpr bool const is_io_synced = true;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_output_temporary = true;

static constexpr validation_type const
  validation = validation_type::single;

static constexpr range_size const
  input_size_type = range_size::uncountable;

static constexpr range_size const
  output_size_type = range_size::uncountable;

generate_range (
  Gen _gen
)
: gen (_gen)
, flag (false)
{}

generate_range (generate_range const &) = default;
generate_range (generate_range &&) = default;
~generate_range () = default;
generate_range & operator = (generate_range &&) = default;
generate_range & operator = (generate_range const &) = default;

read_type
operator * (
){
this->flag = false;
return this->gen();
}

generate_range<Gen> &
operator ++ (
){
  if (this->flag) this->gen();
  else this->flag = true;
return *this;
}

bool operator == (sentinel::readable const &) const;
bool operator == (read_type const &) const {
return true;
}

}; /* generate range */

template <typename Gen>
bool
generate_range<Gen>::operator == (
  sentinel::readable const &
) const {
return true;
}

template <typename Gen>
generate_range<Gen>
make_generate_range (
  Gen _gen
);

template <typename Gen>
generate_range<Gen>
make_generate_range (
  Gen _gen
){
return generate_range<Gen>(_gen);
}

} /* range layer */
#endif
