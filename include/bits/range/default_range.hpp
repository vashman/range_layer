// Default spelizations of range class.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DEFAULT_RANGE_HPP
#define RANGE_LAYER_BITS_RANGE_DEFAULT_RANGE_HPP

namespace range_layer {

/*===========================================================
  default range
===========================================================*/
template <typename T>
class range<T>
: public bits::base_from_member<T>
, public range<T * const>
{
public:

explicit range(T);
range<T> save() const;

}; //-------------------------------------------default range

/*===========================================================
  default const range
===========================================================*/
template <typename T>
class range<const T>
: public bits::base_from_member<const T>
, public range<const T * const>
{
public:

explicit range(const T);
range<T> save() const;

}; //-------------------------------------default const range

/*===========================================================
  default pointer range
===========================================================*/
template <typename T>
class range<T * const> : public range<const T * const> {

public:

using write_type = typename std::remove_pointer<T>::type;

explicit range (T * const);
         range (range const &) = delete;
         range (range &&) = default;
range &  operator = (range const &) = delete;
range &  operator = (range &&) = default;
void     write (write_type const &);
bool     has_writable() const;

private:

T * const handle;

}; //-----------------------------------default pointer range

/*===========================================================
  default const pointer range
===========================================================*/
template <typename T>
class range<const T * const> {

using read_type = typename std::remove_pointer<T>::type;

public:

explicit              range (const T * const);
read_type const &     read() const;
constexpr std::size_t size() const;
constexpr std::size_t position() const;
void                  advance ();
void                  reverse ();
bool                  has_readable() const;

protected:

const T * const const_handle;
bool is_end;

}; //-----------------------------default const pointer range
} //----------------------------------------------range layer
#endif
#include "default_range.tcc"
