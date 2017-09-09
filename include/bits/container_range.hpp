// Range for single typed c++ containers.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_CONTAINER_HPP
#define RANGE_LAYER_CONTAINER_HPP

#include "range_traits.hpp"
#include "bits/decorator.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  vector_range
===========================================================*/
template <typename T, typename Alloc>
struct container;

/*===========================================================
  vector_range
===========================================================*/
template <typename Con>
class container {

Con * con;
std::size_t pos;

public:

using read_type = T;
using write_type = read_type;

/*===========================================================
  ctor
===========================================================*/
container (
  Con &
);

/*===========================================================
  copy ctor
===========================================================*/
container (container const &) = default;

/*===========================================================
  move ctor
===========================================================*/
container (container &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
container & operator = (container const &) = default;

/*===========================================================
  move assignment operator
===========================================================*/
container & operator = (container &&) = default;

/*===========================================================
  dtor
===========================================================*/
~container() = default;

/*===========================================================
  save
===========================================================*/
container &
save (
){
return *this;
}

/*===========================================================
  size
===========================================================*/
std::size_t
size (
) const {
return this->vec->size();
}

/*===========================================================
  position
===========================================================*/
std::size_t
position (
) const {
return this->pos;
}

/*===========================================================
  operator *
===========================================================*/
T const &
operator * (){
return *this->vec[this->pos-1];
}

/*===========================================================
  operator =
===========================================================*/
void
operator = (
  T const & _var
){
(*(this->vec))[this->pos-1] = _var;
}

/*===========================================================
  operator ++
===========================================================*/
container &
operator ++ (
){
++this->pos;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
container &
operator -- (
){
--this->pos;
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
container &
operator += (
  std::size_t const _n
){
this->pos += _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
container &
operator -= (
  std::size_t const _n
){
this->pos -= _n;
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const _sen
) const {
return this->pos <= this->vec->size();
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::writable const _sen
) const {
return *this == sentinel::readable{};
}

/*===========================================================
  expand
===========================================================*/
container
expand (
  std::size_t _n
){
_n += this->vec->size();
this->vec->resize(_n);
return *this;
}

/*===========================================================
  shrink
===========================================================*/
container &
shrink (
  std::size_t _n
){
_n = this->con->size() - _n;
this->con->resize(_n);
return *this;
}

/*===========================================================
  insert
===========================================================*/
container &
insert (
  write_type_t<Range> const & _var
);

/*===========================================================
  erase_all
===========================================================*/
container &
erase_all ();

/*===========================================================
  erase
===========================================================*/
container &
erase ();

}; //container-----------------------------------------------

/*===========================================================
  container:: ctor
===========================================================*/
template <typename Con>
container<Con>::container (
  Con & _con
)
: con {&_con}
, pos {1}
{}

/*===========================================================
  container:: erase
===========================================================*/
template <typename Con>
container &
container<Con>::erase (
){
this->con->erase(this->con->begin() + this->pos);
return *this;
}

/*===========================================================
  container:: erase_all
===========================================================*/
container &
erase_all (
){
this->con->clear();
return *this;
}

/*===========================================================
  container:: insert
===========================================================*/
container &
insert (
  write_type const & _var
){
this->con->insert(this->con->begin() + this->pos, _var);
return *this;
}

} //bits-----------------------------------------------------
} //range layer----------------------------------------------
#endif

