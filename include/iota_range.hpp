//

//          Copyright Sundeep S. Sangha 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_IOTA_RANGE_HPP
#define RANGE_LAYER_IOTA_RANGE_HPP

#include <limits>
#include <type_traits>
#include "range_traits.hpp"

namespace range_layer {

template
<
  typename T
, typename Size
    = typename std
    ::remove_cv<typename std::make_unsigned<T>::type>::type
>
class iota_range {

T count;

public:

using read_type = T;

using size_type
  = typename std
    ::remove_cv<typename std::make_unsigned<T>::type>::type;

iota_range (
  T const & _var
)
: count {_var}
{}

iota_range (iota_range const &) = default;
iota_range (iota_range &&) = default;
iota_range & operator = (iota_range const &) = default;
iota_range & operator = (iota_range &&) = default;
~iota_range() = default;

T const & operator * ();
iota_range & operator ++ ();
iota_range & operator -- ();
iota_range & operator += (T const &);
iota_range & operator -= (T const &);
bool operator == (sentinel::readable const &) const;
bool operator == (T const &) const;
iota_range & save();

size_type
size (
) const {
return std::numeric_limits<size_type>::max();
}

size_type
position (
) const {
return this->count;
}

}; /* iota range */

template <typename T, typename Size>
iota_range<T, Size> &
iota_range<T, Size>::save(){
return *this;
}

template <typename T, typename Size>
bool
iota_range<T, Size>::operator == (
  sentinel::readable const & _sentinel
) const {
return !(
  (std::numeric_limits<T>::max() == this->count)
|| (std::numeric_limits<T>::min() == this->count)
);
}

template <typename T, typename Size>
bool
iota_range<T, Size>::operator == (
  T const & _sentinel
) const {
return this->count == _sentinel;
}

template <typename T, typename Size>
bool
operator != (
  iota_range<T, Size> const & _range
, T const & _sentinel
){
return !(_range == _sentinel);
}

template <typename T, typename Size>
iota_range<T, Size> &
iota_range<T, Size>::operator ++ (
){
++this->count;
return *this;
}

template <typename T, typename Size>
iota_range<T, Size> &
iota_range<T, Size>::operator -- (
){
--this->count;
return *this;
}

template <typename T, typename Size>
T const &
iota_range<T, Size>::operator * (
){
return this->count;
}

template <typename T, typename Size>
iota_range<T, Size> &
iota_range<T, Size>::operator += (
  T const & _n
){
this->count += _n;
return *this;
}

template <typename T, typename Size>
iota_range<T, Size> &
iota_range<T, Size>::operator -= (
  T const & _n
){
this->count -= _n;
return *this;
}

} /* range layer */
#endif

