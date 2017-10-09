//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_VECTOR_RANGE_TCC
#define RANGE_LAYER_BITS_RANGE_VECTOR_RANGE_TCC

namespace range_layer {

/*===========================================================
  ctor
===========================================================*/
template <typename T, typename Alloc>
range <std::vector<T, Alloc> * const>::range (
  std::vector<T, Alloc> * const _ptr
)
: range<const std::vector<T, Alloc> * const> {_ptr}
, handle {_ptr}
{}


/*===========================================================
  ctor
===========================================================*/
template <typename T, typename Alloc>
range <const std::vector<T, Alloc> * const>::range (
  const std::vector<T, Alloc> * const _ptr
)
: const_handle {_ptr}
, pos {1}
{}

/*===========================================================
  size
===========================================================*/
template <typename T, typename Alloc>
std::size_t
range <const std::vector<T, Alloc> * const>::size (
) const {
return this->const_handle->size();
}

/*===========================================================
  position
===========================================================*/
template <typename T, typename Alloc>
std::size_t
range <const std::vector<T, Alloc> * const>::position (
) const {
return this->pos;
}

/*===========================================================
  read
===========================================================*/
template <typename T, typename Alloc>
T const &
range <const std::vector<T, Alloc> * const>::read (
) const {
return (*this->const_handle)[this->pos-1];
}

/*===========================================================
  advance
===========================================================*/
template <typename T, typename Alloc>
void
range <const std::vector<T, Alloc> * const>::advance (
){
++this->pos;
}

/*===========================================================
  reverse
===========================================================*/
template <typename T, typename Alloc>
void
range <const std::vector<T, Alloc> * const>::reverse (
){
--this->pos;
}

/*===========================================================
  advance_n
===========================================================*/
template <typename T, typename Alloc>
void
range <const std::vector<T, Alloc> * const>::advance_n (
  std::size_t const _n
){
this->pos += _n;
}

/*===========================================================
  reverse_n
===========================================================*/
template <typename T, typename Alloc>
void
range <const std::vector<T, Alloc> * const>::reverse_n (
  std::size_t const _n
){
this->pos -= _n;
}

/*===========================================================
  has_readable
===========================================================*/
template <typename T, typename Alloc>
bool
range <const std::vector<T, Alloc> * const>::has_readable (
) const {
return this->pos <= this->const_handle->size();
}

/*===========================================================
  has_writable
===========================================================*/
template <typename T, typename Alloc>
bool
range <const std::vector<T, Alloc> * const>::has_writable (
) const {
return this->has_readable();
}

/*===========================================================
  write
===========================================================*/
template <typename T, typename Alloc>
void
range<std::vector<T, Alloc> * const>::write (
  T const & _var
){
(*(this->handle))[this->pos-1] = _var;
}

/*===========================================================
  expand
===========================================================*/
template <typename T, typename Alloc>
void
range<std::vector<T, Alloc> * const>::expand (
  std::size_t _n
){
_n += this->handle->size();
this->handle->resize(_n);
}

/*===========================================================
  shrink
===========================================================*/
template <typename T, typename Alloc>
void
range<std::vector<T, Alloc> * const>::shrink (
  std::size_t _n
){
_n = this->handle->size() - _n;
this->handle->resize(_n);
}

/*===========================================================
  insert
===========================================================*/
template <typename T, typename Alloc>
void
range<std::vector<T, Alloc> * const>::insert (
  write_type const & _var
){
this->handle->insert
  (this->handle->begin() + this->pos, _var);
}

/*===========================================================
  erase_all
===========================================================*/
template <typename T, typename Alloc>
void
range<std::vector<T, Alloc> * const>::erase_all (
){
this->handle->clear();
}

/*===========================================================
  erase
===========================================================*/
template <typename T, typename Alloc>
void
range<std::vector<T, Alloc> * const>::erase (
) {
this->handle->erase(this->handle->begin() + this->pos);
}

} //----------------------------------------------range layer
#endif
