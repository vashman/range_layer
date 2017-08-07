// Attempts to tie the life time of varaibles with ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_EXTEND_LIFE_RANGE_HPP
#define RANGE_LAYER_EXTEND_LIFE_RANGE_HPP

#include <tuple>

namespace range_layer {
namespace bits {

template <typename Range, typename... Ts>
class extend_life {

Range range;

public:

// variables need to be movable and copyable.
std::tuple<Ts...> variables;

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

extend_life (
  Range _range
, Ts... _ts
)
: range {_range}
, variables {_ts...}
{}

extend_life (extend_life const &) = default;
extend_life & operator = (extend_life const &) = default;
extend_life (extend_life &&) = default;
extend_life & operator = (extend_life &&) = default;
~extend_life() = default;

template <typename U = Range>
auto
operator * (
) -> decltype(*this->range) {
return *this->range;
}

template <typename U = Range>
extend_life &
operator ++ (
){
++this->range;
return *this;
}

template <typename U = Range>
extend_life
save (
){
return extend_life(*this).range = this->range.save();
}

template <typename U = Range>
extend_life &
operator -- (
){
--this->range;
return *this;
}

template <typename T>
void
operator = (
  T const & _var
){
this->range = _var;
}

template <typename N>
extend_life &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
extend_life &
operator -= (
  N _n
){
this->range -= _n;
return *this;
}

bool
operator == (
  sentinel::readable const & _sen
) const {
return this->range == _sen;
}

template <typename U = Range>
bool
operator == (
  sentinel::writable const & _sen
) const {
return this->range == _sen;
}

template <typename U = Range>
auto
size (
) const -> decltype(this->range.size()) {
return this->range.size();
}

template <typename U = Range>
auto
position (
) const -> decltype(this->range.position()) {
return this->range.position();
}

Range
disable (
) const {
return this->range;
}

/* used internally to reset the range, after the container
 * has moved or been copied to inside the range.
 */
void
set_range (
  Range _range
){
this->range = _range;
}

}; /* extend_life */

} /* bits */ } /* range layer */
#endif

