//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REMOVE_DECORATOR_HPP
#define RANGE_LAYER_REMOVE_DECORATOR_HPP

namespace range_layer {
namespace bits {

template <typename Range>
class remove_decorator {

Range range;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

remove_decorator (
  Range _range
)
: range {_range}
{}

remove_decorator (remove_decorator const &) = default;
remove_decorator (remove_decorator &&) = default;

remove_decorator &
operator = (
  remove_decorator &&
) = default;

remove_decorator &
operator = (
  remove_decorator const &
) = default;

template <typename U = Range>
auto
operator * () -> decltype(*this->range){
return *this->range;
}

template <typename U = Range>
remove_decorator &
operator ++ (){
++this->range;
return *this;
}

template <typename U = Range>
remove_decorator
save(){
return remove_decorator(*this).range = this->range.save();;
}

template <typename U = Range>
remove_decorator &
operator -- (){
--this->range;
return *this;
}

template <typename T>
void
operator = (T const & _var){
this->range = _var;
}

template <typename N>
remove_decorator &
operator += (
  N _n
){
this->range += _n;
return *this;
}

template <typename N>
remove_decorator &
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

template <typename T = Range>
auto
size (
) const -> decltype(this->range.size()) {
return this->range.size();
}

}; /* remove decorator */

} /* bits */ } /* range layer */
#endif
