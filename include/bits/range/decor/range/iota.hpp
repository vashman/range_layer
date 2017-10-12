//

//          Copyright Sundeep S. Sangha 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_IOTA_RANGE_HPP
#define RANGE_LAYER_IOTA_RANGE_HPP

#include <type_traits>
#include "../../range_traits.hpp"

#include "iota.fwd"

namespace range_layer {

/*===========================================================
  iota
===========================================================*/
template <typename T>
struct iota {

T var;

}; //----------------------------------------------------iota

/*===========================================================
  iota range
===========================================================*/
template <typename T>
class range<iota<T> * const>
: public range<const iota<T> * const>
{

public:

explicit range (iota<T> * const);
         range (range const &) = delete;
         range (range &&) = default;
range &  operator = (range const &) = delete;
range &  operator = (range &&) = default;
void     advance ();
void     reverse ();
void     advance_n (T const &);
void     reverse_n (T const &);

private:

iota<T> * const handle;

}; //----------------------------------------------iota range

/*===========================================================
  const iota range
===========================================================*/
template <typename T>
class range<const iota<T> * const> {

using size_type
  = typename std
    ::remove_cv<typename std::make_unsigned<T>::type>::type;

public:

explicit  range (const iota<T> * const);
T const & read () const;
size_type size () const;
size_type position () const;
bool      has_readable () const;

protected:

const iota<T> * const const_handle;

}; //----------------------------------------const iota range
} //----------------------------------------------range layer
#endif
#include "iota.tcc"

