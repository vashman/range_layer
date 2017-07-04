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

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

static constexpr auto max_size
  = range_trait::max_size<Range>::value;

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

template <typename U = Range>
reverse_range &
save(){
return *this;
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

Range
disable (
) const {
return this->range;
}

};

} /* bits */ } /* range layer */
#endif

