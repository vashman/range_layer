//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_VECTOR_HPP
#define RANGE_LAYER_BITS_RANGE_VECTOR_HPP

#include <vector>
#include "range.hpp"

namespace range_layer {

/*===========================================================
  vector range
===========================================================*/
template <typename T, typename Alloc>
class range <std::vector<T, Alloc> * const>
: public range <const std::vector<T, Alloc> * const>
{

public:

using write_type = T;

explicit range (std::vector<T, Alloc> * const);
         range (range const &) = delete;
         range (range &&) = default;
range &  operator = (range const &) = delete;
range &  operator = (range &&) = default;
void     write (T const &);
void     expand (std::size_t);
void     shrink (std::size_t);
void     insert (T const &);
void     erase_all ();
void     erase ();

private:

std::vector<T, Alloc> * const handle;

}; //--------------------------------------------vector range

/*===========================================================
  const vector range
===========================================================*/
template <typename T, typename Alloc>
class range <const std::vector<T, Alloc> * const> {

public:

explicit     range (const std::vector<T, Alloc> * const);
std::size_t  size () const;
std::size_t  position () const;
T const &    read () const;
void         advance();
void         reverse();
void         advance_n (std::size_t const);
void         reverse_n (std::size_t const);
bool         has_readable () const;
bool         has_writable () const;

protected:

const std::vector<T, Alloc> * const const_handle;
std::size_t pos;

}; //--------------------------------------const vector range
} //----------------------------------------------range layer
#endif
#include "vector.tcc"
