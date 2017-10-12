//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_POINTER_HPP
#define RANGE_LAYER_BITS_RANGE_POINTER_HPP

namespace range_layer {

/*===========================================================
  pointer range
===========================================================*/
template <typename T>
class range <T *> : public range<T * const> {

public:

explicit range(T * _ptr) : range<T * const> {_ptr}{}

}; //-------------------------------------------pointer range

/*===========================================================
  const pointer range
===========================================================*/
template <typename T>
class range <const T *> : public range<const T * const> {

public:

explicit range(const T * _ptr) : range<const T * const> {_ptr}{}

}; //-------------------------------------const pointer range

/*===========================================================
  pointer const range
===========================================================*/
template <typename T>
class range <T * const> : range<const T * const> {

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

}; //-------------------------------------pointer const range

/*===========================================================
  const pointer const range
===========================================================*/
template <typename T>
class range <T * const> {

using read_type = typename std::remove_pointer<T>::type;

public:

explicit              range (const T * const);
read_type const &     read() const;
constexpr std::size_t size() const;
constexpr std::size_t position() const;
void                  advance ();
void                  reverse ();
bool                  has_readable() const;

private:

const T * const c_handle;
bool is_end;

}; //-------------------------------------pointer const range
} //----------------------------------------------range layer
#endif
#include "pointer.tcc"
