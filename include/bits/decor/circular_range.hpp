//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_CIRCULAR_RANGE_HPP
#define RANGE_LAYER_CIRCULAR_RANGE_HPP

namespace range_layer {
namespace bits {

template <typename Range>
class circular_range {

Range range;

bool
is_end (
) const {
// Return true if either end is reached.
return (
   ! (this->range == sentinel::writable)
|| ! (this->range == sentinel::readable)
);
}

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

static constexpr auto max_size
  = range_trait::max_size<Range>::value;

circular_range (
  Range _range
, Pred _pred
)
: range {_range}
{}

circular_range (circular_range const &) = default;
circular_range (circular_range &&) = default;
circular_range & operator = (circular_range &&) = default;
circular_range & operator = (circular_range const &) = default;
~circular_range () = default;

auto
operator * (
) -> decltype(*this->range) {
return *this->range;
}

template <typename U = Range>
circular_range &
save(){
return circular_range(*this).range = this->range.save();
}

template <typename U = Range>
circular_range &
operator ++ (){
++this->range;
  if (this->is_end()) // Reset postion to start.
return *this;
}

template <typename U = Range>
circular_range &
operator -- (){
--this->range;
  if (this->is_end()) // reset postion to end.
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
circular_range &
operator += (
  N _n
){
this->range += _n;
  if (this->is_end()) // Reset postion to start.
return *this;
}

template <typename N>
circular_range &
operator -= (
  N _n
){
this->range -= _n;
  if (this->is_end()) // reset postion to end.
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

template <typename T>
bool
operator == (
  T const & _sen
) const {
return this->range == _sen;
}

Range
disable (
) const {
return this->range;
}

}; /* circular range */

} /* bits */ } /* range layer */
#endif

