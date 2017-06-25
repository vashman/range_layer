//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REVERSE_RANGE_HPP
#define RANGE_LAYER_REVERSE_RANGE_HPP

namespace range_layer {
namespace bits {

template <typename Range>
class reverse_range {

Range range;
using trait = range_traits<Range>;

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
static_assert(trait::is_reversable, "Cannot reverse range");

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

reverse_range (
  Range _range
)
: range {_range}
{}

reverse_range (reverse_range const &) = default;
reverse_range (reverse_range &&) = default;

reverse_range &
operator = (reverse_range &&) = default;

reverse_range &
operator = (reverse_range const &) = default;

~reverse_range () = default;

auto
operator * () -> decltype(*this->range){
return *this->range;
}

reverse_range &
operator ++ (){
--this->range;
return *this;
}

template <typename U = Range>
reverse_range &
operator -- (){
++this->range;
return *this;
}

template <typename T>
void
operator = (T const & _var){
this->range = _var;
}

template <typename N>
reverse_range &
operator += (
  N _n
){
this->range -= _n;
return *this;
}

template <typename N>
reverse_range &
operator -= (
  N _n
){
this->range += _n;
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
} /* bits */ } /* range layer */
#endif

