//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_BITS_TRANSFORM_RANGE_HPP

namespace range_layer {
namespace bits {

template <typename Func, typename Range>
class transform_range {

using trait = range_traits<Range>;
Range range;
Func func;

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

transform_range (
  Range _range
, Func _func
)
: range {_range}
, func (_func)
{}

transform_range (transform_range const &) = default;
transform_range (transform_range &&) = default;

transform_range &
operator = (transform_range &&) = default;

transform_range &
operator = (transform_range const &) = default;

~transform_range () = default;

auto
operator * () -> decltype(this->func(*this->range));

transform_range &
operator ++ (){
++this->range;
return *this;
}

template <typename U = Range>
transform_range &
operator -- (){
--this->range;
return *this;
}

template <typename T>
void
operator = (T const &);

template <typename N>
transform_range &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
transform_range &
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

}; /* transform range */

} /* bits */ } /* range layer */
#endif

