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

template <typename T>
class iota_range {

T count;

public:

using read_type = T;
using size_type
  = typename std
    ::remove_cv<typename std::make_unsigned<T>::type>::type;

static constexpr size_type max_size
  = std::numeric_limits<size_type>::max();

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

};

template <typename T>
iota_range<T> &
iota_range<T>::save(){
return *this;
}

template <typename T>
bool
iota_range<T>::operator == (
  sentinel::readable const & _sentinel
) const {
return !(
  (std::numeric_limits<T>::max() == this->count)
|| (std::numeric_limits<T>::min() == this->count)
);
}

template <typename T>
bool
iota_range<T>::operator == (
  T const & _sentinel
) const {
return this->count == _sentinel;
}

template <typename T>
bool
operator != (
  iota_range<T> const & _range
, T const & _sentinel
){
return !(_range == _sentinel);
}

template <typename T>
iota_range<T> &
iota_range<T>::operator ++ (
){
++this->count;
return *this;
}

template <typename T>
iota_range<T> &
iota_range<T>::operator -- (
){
--this->count;
return *this;
}

template <typename T>
T const &
iota_range<T>::operator * (
){
return this->count;
}

template <typename T>
iota_range<T>&
iota_range<T>::operator += (
  T const & _n
){
this->count += _n;
return *this;
}

template <typename T>
iota_range<T>&
iota_range<T>::operator -= (
  T const & _n
){
this->count -= _n;
return *this;
}

} /* range layer */
#endif

