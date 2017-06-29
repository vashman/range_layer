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

Range range;
Func func;

public:

using read_type = typename range_trait::read_type<Range>::type;
using write_type = typename range_trait::write_type<Range>::type;

static constexpr bool const
  is_io_synced = range_trait::is_io_synced<Range>::value;

static constexpr validation_type const
  validation = range_trait::validation<Range>::value;

static constexpr bool const
  is_input_temporary = range_trait::input::is_temporary<Range>::value;

static constexpr range_size const
  input_size_type = range_trait::input::size_type<Range>::value;

static constexpr bool const
  is_output_temporary = range_trait::output::is_temporary<Range>::value;

static constexpr range_size const
  output_size_type = range_trait::output::size_type<Range>::value;

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
operator * (
) -> decltype(this->func(*this->range)) {
return this->func(*this->range);
}

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

