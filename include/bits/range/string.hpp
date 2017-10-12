//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_STRING_HPP
#define RANGE_LAYER_BITS_RANGE_STRING_HPP

#include <string>
#include "range.hpp"

namespace range_layer {

/*===========================================================
  string range
===========================================================*/
template <typename T, typename Traits, typename Alloc>
class range <std::basic_string<T, Traits, Alloc> * const>
: public range
  <const std::basic_string<T, Traits, Alloc> * const>
{

using string_t = std::basic_string<T, Traits, Alloc>;

public:

using write_type = T;

explicit range (string_t * const);
         range (range const &) = delete;
         range (range &&) = default;
range &  operator = (range const &) = delete;
range &  operator = (range &&) = default;
void     write (T const & _var){(*this->handle)[this->pos-1] = _var;}
void     expand (std::size_t _n){this->handle->resize(this->handle->size()+_n);}
void     shrink (std::size_t _n){this->handle->resize(this->handle->size()-_n);}
void     insert (T const & _var){this->handle->insert(this->position(), _var);}
void     erase (){this->handle->erase(this->position(), 1);}
void     erase_all (){this->handle->clear();}

private:

string_t * const handle;

}; //--------------------------------------------string range

/*===========================================================
  const string range
===========================================================*/
template <typename T, typename Traits, typename Alloc>
class range
<const std::basic_string<T, Traits, Alloc> * const>
{

using string_t = std::basic_string<T, Traits, Alloc>;

public:

explicit    range (const string_t * const);
std::size_t size () const{return this->const_handle->size();}
std::size_t position () const{return this->pos;}
const T &   read () const {return (*this->const_handle)[this->pos-1];}
void        advance(){++this->pos;}
void        reverse(){--this->pos;}
void        advance_n (std::size_t const _n){this->pos += _n;}
void        reverse_n (std::size_t const _n){this->pos -= _n;}
bool        has_readable () const {return this->pos <= this->const_handle->size();}
bool        has_writable () const {return this->has_readable();}

protected:

const string_t * const const_handle;
std::size_t pos;

}; //--------------------------------------const string range
} //----------------------------------------------range layer
#endif
#include "string.tcc"