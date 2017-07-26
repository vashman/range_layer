//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DISABLE_INPUT_HPP
#define RANGE_LAYER_DISABLE_INPUT_HPP

namespace range_layer {
namespace bits {

template <typename Range>
class disable_input {

Range range;

public:

using write_type
  = typename range_trait::write_type<Range>::type;

disable_input (
  Range _range
)
: range {_range}
{}

disable_input (disable_input const &) = default;
disable_input (disable_input &&) = default;
disable_input & operator = (disable_input &&) = default;
disable_input & operator = (disable_input const &) = default;
~disable_input () = default;

template <typename U = Range>
disable_input &
save(){
return disable_input(*this).range = this->range.save();
}

template <typename U = Range>
disable_input &
operator ++ (){
++this->range;
return *this;
}

template <typename U = Range>
disable_input &
operator -- (){
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
disable_input &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
disable_input &
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

auto
size (
) const -> decltype(size(this->range)) {
return size(this->range);
}

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

}; /* disable input */

} /* bits */ } /* range layer */
#endif

