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

Range range;
Func func;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

static constexpr auto max_size
  = range_trait::max_size<Range>::value;

input_transform_range (
  Range _range
, Func _func
)
: range {_range}
, func (_func)
{}

input_transform_range (
  input_transform_range const &
) = default;

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

template <typename U = Range>
input_transform_range
save(){
input_transform_range temp = *this;
temp.range = this->range.save();
return temp;
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

