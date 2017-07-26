//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DISABLE_OUTPUT_HPP
#define RANGE_LAYER_DISABLE_OUTPUT_HPP

namespace range_layer {
namespace bits {

template <typename Range>
class disable_output {

Range range;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

disable_output (
  Range _range
)
: range {_range}
{}

disable_output (disable_output const &) = default;
disable_output (disable_output &&) = default;
disable_output & operator = (disable_output &&) = default;
disable_output & operator = (disable_output const &) = default;
~disable_output () = default;

template <typename U = Range>
disable_output &
save (
){
return disable_output(*this).range = this->range.save();
}

template <typename U = Range>
disable_output &
operator ++ (){
++this->range;
return *this;
}

template <typename U = Range>
disable_output &
operator -- (){
--this->range;
return *this;
}

template <typename T>
auto
operator * (
  T const & _var
) -> decltype(*this->range) {
return *this->range;
}

template <typename N>
disable_output &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
disable_output &
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

}; /* disable output */

} /* bits */ } /* range layer */
#endif

