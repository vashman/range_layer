// Chains ranges in sequence.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_CHAIN_RANGE_HPP
#define RANGE_LAYER_CHAIN_RANGE_HPP

#include <tuple>

namespace range_layer {
namespace bits {

/*===========================================================
  chain 
===========================================================*/
template <typename Range, typename... Ranges>
class chain {

std::tuple<Range, Ranges...> range;
std::size_t pos;

public:

/* Read & write types must be the same for each range other
 * ranges read & write types.
 */
using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

chain (
  Range _range
, Ranges... _ranges
)
: range {_range, _ranges...}
, pos {0}
{}

chain (chain const &) = default;
chain & operator = (chain const &) = default;
chain (chain &&) = default;
chain & operator = (chain &&) = default;
~chain() = default;

template <typename U = Range>
read_type
operator * (
){
return *get<>this->range;
}

template <typename U = Range>
chain &
operator ++ (
){
++this->range;
return *this;
}

template <typename U = Range>
chain
save (
){
return chain(*this).range = this->range.save();
}

template <typename U = Range>
chain &
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
chain &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
chain &
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

}; /* chain */

} /* bits */ } /* range layer */
#endif

