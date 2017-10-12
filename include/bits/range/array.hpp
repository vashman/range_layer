//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_ARRAY_HPP
#define RANGE_LAYER_BITS_RANGE_ARRAY_HPP

#include <array>
#include "array.fwd"

namespace range_layer {

template <typename T, std::size_t N>
class range <std::array<T, N> * const>
: public range <const std::array<T, N> * const>
{

public:

using write_type = T;

explicit range (std::array<T, N> * const _ptr) : range <const std::array<T, N> * const>{_ptr}, handle{_ptr} {}
void     write(T const & _var) {(*this->handle)[this->pos] = _var;}

private:

std::array<T, N> * const handle;

};

template <typename T, std::size_t N>
class range <const std::array<T, N> * const> {

public:

explicit  range (const std::array<T, N> * const _ptr) : const_handle {_ptr}, pos{0} {}
T const & read() const {return this->const_handle->at(this->pos);}
bool      has_readable() const {return this->pos != N;}
bool      has_writable() const {return this->has_readable();}
void      advance(){++this->pos;}
void      reverse(){--this->pos;}
void      advance_n(std::size_t const _n){this->pos += _n;}
void      reverse_n(std::size_t const _n){this->pos -= _n;}

protected:

const std::array<T, N> * const const_handle;
std::size_t pos;

};

} //----------------------------------------------range layer
#endif
