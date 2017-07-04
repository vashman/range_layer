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
static constexpr std::size_t max_size
  = std::numeric_limits<std::size_t>::max();

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

generate_range &
operator = (generate_range const &) = default;

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
static_assert (
     std::is_move_constructible<Gen>::value
  && std::is_move_assignable<Gen>::value
, "Error the Generator is not move constructible or"
  " assignable."
);

return generate_range<Gen>(_gen);
}

} /* range layer */
#endif
