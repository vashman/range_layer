//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP

namespace range_layer {
namespace bits {

template <typename Func, typename Range>
class output_transform_range {

using trait = range_traits<Range>;
Range range;
Func func;

public:

static constexpr bool const is_output = true;
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

output_transform_range (
  Range _range
, Func _func
)
: range {_range}
, func (_func)
{}

output_transform_range (output_transform_range const &) = default;
output_transform_range (output_transform_range &&) = default;

output_transform_range &
operator = (output_transform_range &&) = default;

output_transform_range &
operator = (output_transform_range const &) = default;

~output_transform_range () = default;

template <typename U = Range>
auto
operator * () -> decltype(*this->range){
return *this->range;
}

output_transform_range &
operator ++ (){
++this->range;
return *this;
}

template <typename U = Range>
output_transform_range &
operator -- (){
--this->range;
return *this;
}

template <typename T>
void
operator = (T const & _var){
this->range = this->func(_var);
}

template <typename N>
output_transform_range &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
output_transform_range &
operator -= (
  N _n
){
this->range -= _n;
return *this;
}

template <typename U = Range>
bool
operator == (
  sentinel::readable const & _sen
) const {
return this->range == _sen;
}

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

}; /* output transform range */

} /* bits */ } /* range layer */
#endif

