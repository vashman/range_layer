// 

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DECOR_ITERATOR_HPP
#define RANGE_LAYER_BITS_RANGE_DECOR_ITERATOR_HPP

#include <iterator>
#include "iterator.fwd"

namespace range_layer {

namespace enable_range {

/*===========================================================
  iterator
===========================================================*/
template <typename Sentinal>
struct iterator {

Sentinal sentinal;

}; //------------------------------------------------iterator
} //---------------------------------------------enable range

/*===========================================================
  range
===========================================================*/
template <typename Iterator, typename Sentinal>
class range <Iterator, enable_range::iterator<Sentinal>> {

public:

using write_type
  = typename std::iterator_traits<Iterator>::value_type;

     range (Iterator _iter, enable_range::iterator<Sentinal> _sen) : iter{_iter}, sentinal{_sen.sentinal}{}
void advance(){++this->iter;}
void write(write_type const & _var){*(this->iter) = _var;}
bool has_writable() const {return this->iter != this->sentinal;}

private:

Iterator iter;
Sentinal sentinal;

}; //---------------------------------------------------range
} //----------------------------------------------range layer
#endif
#include "iterator.tcc"
