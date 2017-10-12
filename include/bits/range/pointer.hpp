//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_POINTER_FWD
#define RANGE_LAYER_BITS_RANGE_POINTER_FWD

#include "range.fwd"

namespace range_layer {

template <typename T>
class range <T * const, T * const>
: public range <const T * const, const T * const> {

public:

explicit range (T * const _f, T * const _l) : range <const T * const, const T * const>{_f, _l}, pos{_f}{}
void     write(T const & _var) {*this->pos = _var;}
void     erase();
void     erase_all();
void     shrink(std::size_t);
void     expand(std::size_t);
void     insert(T);

private:

T * const pos;

}; //---------------------------------------------------range

template <typename T>
class range <const T * const, const T * const> {

public:

explicit  range (const T * const _f, const T * const _l) : const_pos {_f}, first {_f}, last {_l}{}
T const & read() const {return *this->const_pos;}
bool      has_readable() const {return this->const_pos == this->last;}
bool      has_writable() const {return this->has_readable();}
void      advance(){++this->const_pos;}
void      reverse(){--this->const_pos;}
void      advance_n(std::size_t const _n){this->const_pos += _n;}
void      reverse_n(std::size_t const _n){this->const_pos -= _n;}

private:

const T * const_pos;
const T * const first;
const T * const last;

}; //---------------------------------------------const range
} //----------------------------------------------range layer
#endif
