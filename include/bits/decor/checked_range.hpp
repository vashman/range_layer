//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_CHECKED_RANGE_HPP
#define RANGE_LAYER_CHECKED_RANGE_HPP

#include <stdexcept>

namespace range_layer {
namespace bits {

/*===========================================================
  checked_range

* Bounds checking
* Read / Write count checking
===========================================================*/
template <typename Range>
class checked_range {

Range range;
bool has_read;
bool has_wrote;
bool end_of_read;
bool end_of_write;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
checked_range (
  Range _range
)
: range {_range}
, has_read {false}
, has_wrote {false}
, end_of_read {false}
, end_of_write {false}
{
static_assert (
  range_trait::is_reversable<Range>::value
, "Cannot check reversable range."
);
}

checked_range (checked_range const &) = default;
checked_range & operator = (checked_range const &) = default;
checked_range (checked_range &&) = default;
checked_range & operator = (checked_range &&) = default;
~checked_range() = default;

/*===========================================================
  operator *
===========================================================*/
template <typename U = Range>
auto
operator * (
) -> decltype(*this->range) {
  if (this->has_read)
  throw std::logic_error("Multiple reads");

this->has_read = true;
return *this->range;
}

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
checked_range &
operator ++ (
){
this->has_read = false;
this->has_wrote = false;
++this->range;

  if (!(*this == sentinel::readable{})){
    if (this->end_of_read)
    throw std::out_of_range("Advacning out of read range.");

    else this->end_of_read = true;
  }

  if (!(*this == sentinel::writable{})){
    if (this->end_of_write)
    throw std::out_of_range("Advacning out of write range.");

    else this->end_of_write = true;
  }

return *this;
}

/*===========================================================
  save
===========================================================*/
template <typename U = Range>
checked_range
save (
){
return checked_range(*this).range = this->range.save();
}

/*===========================================================
  operator =
===========================================================*/
template <typename T>
void
operator = (
  T const & _var
){
  if (this->has_wrote)
  throw std::logic_error("Multiple writes");

this->has_wrote = true;
this->range = _var;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
checked_range &
operator += (
  N _n
){
while (0 != _n){
this->operator ++<Range>();
--_n;
}

return *this;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::readable const & _sen
) const {
return this->range == _sen;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::writable const & _sen
) const {
return this->range == _sen;
}

/*===========================================================
  size
===========================================================*/
template <typename U = Range>
auto
size (
) const -> decltype(this->range.size()) {
return this->range.size();
}

/*===========================================================
  position
===========================================================*/
template <typename U = Range>
auto
position (
) const -> decltype(this->range.position()) {
return this->range.position();
}

/*===========================================================
  disable
===========================================================*/
Range
disable (
) const {
return this->range;
}

}; /* checked range */

} /* bits */ } /* range layer */
#endif

