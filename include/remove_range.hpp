//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REMOVE_RANGE_HPP
#define RANGE_LAYER_REMOVE_RANGE_HPP

#include "range.hpp"

namespace range_layer {
namespace bits {

template <typename Range, typename Pred>
class remove_range {

Range range;
Pred pred;
decltype (*range) temp;
using trait = range_traits<Range>;

template <typename N>
void
sync_fwd (N _n){
}

public:

static constexpr bool const is_output = trait::is_output;
static constexpr bool const is_input = trait::is_input;
static constexpr bool const is_linear = trait::is_linear;
static constexpr bool const is_erasable = trait::is_erasable;

static constexpr bool const
  is_insertable = trait::is_insertable;

static constexpr bool const
  is_io_synced = trait::is_io_synced;

static constexpr bool const
  is_reversable = trait::is_reversable;

static constexpr validation_type const
  validation = trait::validation;

static constexpr bool const
  is_input_temporary = trait::input::is_temporary;

static constexpr range_size const
  input_size_type = trait::input::size_type;

static constexpr bool const
  is_output_temporary = trait::output::is_temporary;

static constexpr range_size const
  output_size_type = trait::output::size_type;

remove_range (
  Range _range
, Pred _pred
)
: range {_range}
, pred {_pred}
, temp {}
{}

remove_range (remove_range const &) = default;
remove_range (remove_range &&) = default;

remove_range &
operator = (remove_range &&) = default;

remove_range &
operator = (remove_range const &) = default;

~remove_range () = default;

auto
operator * () -> decltype(*this->range){
return *this->temp;
}

template <typename U = Range>
remove_range &
operator ++ (){
  while (this->range == sentinel::readable{}){
  this->temp = *this->range;
    if (! this->pred(this->temp)) break;
  ++this->range;
  }
return *this;
}

template <typename U = Range>
remove_range &
operator -- (){
  while (this->range == sentinel::readable{}){
  this->temp = *this->range;
    if (! this->pred(this->temp)) break;
  --this->range;
  }
return *this;
}

template <typename T>
void
operator = (T const & _var){
this->range = _var;
}

template <typename N>
remove_range &
operator += (
  N _n
){
  while ((0 != _n) && (this->range == sentinel::readable{})){
  this->temp = *this->range;
    if (! this->pred(this->temp)) --n;
  ++this->range;
  }
return *this;
}

template <typename N>
remove_range &
operator -= (
  N _n
){
  while ((0 != _n) && (this->range == sentinel::readable{})){
  this->temp = *this->range;
    if (! this->pred(this->temp)) --n;
  --this->range;
  }
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

};

template <typename T>
struct remove_pred {

T value;

template <typename U>
bool
operator () (
  U _lhs
) const {
return this->value == _lhs;
}

};

} /* bits */

template <typename Range, typename Pred>
bits::remove_range<Range, Pred>
remove_if_range (
  Range _range
, Pred _pred
){
return bits::remove_range<Range, Pred>{_range, _pred};
}

template <typename Range, typename T>
bits::remove_range<Range, bits::remove_pred<T>>
remove_range (
  Range _range
, T _value
){
return bits::remove_range<Range, bits::remove_pred<T>>
{_range, bits::remove_pred<T>{_value}};
}

} /* range layer */
#endif

