//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_INPUT_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_INPUT_TRANSFORM_RANGE_HPP

namespace range_layer {
namespace bits {

template <typename Func, typename Range>
class input_transform_range {

using trait = range_traits<Range>;
Range range;
Func func;

public:

using read_type = typename trait::read_type;
using write_type = typename trait::write_type;

static constexpr bool const
  is_io_synced = trait::is_io_synced;

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

input_transform_range (
  Range _range
, Func _func
)
: range {_range}
, func (_func)
{}

input_transform_range (input_transform_range const &) = default;
input_transform_range (input_transform_range &&) = default;

input_transform_range &
operator = (input_transform_range &&) = default;

input_transform_range &
operator = (input_transform_range const &) = default;

~input_transform_range () = default;

auto
operator * () -> decltype(this->func(*this->range)) {
return this->func(*this->range);
}

input_transform_range &
operator ++ (){
++this->range;
return *this;
}

template <typename U = Range>
input_transform_range &
operator -- (){
--this->range;
return *this;
}

template <typename T>
void
operator = (T const &);

template <typename N>
input_transform_range &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
input_transform_range &
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

}; /* input transform range */

} /* bits */ } /* range layer */
#endif

