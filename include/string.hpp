//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_STRING_RANGE_HPP
#define RANGE_LAYER_STRING_RANGE_HPP

#include <string>
#include "range_traits.hpp"
#include "bits/decor/extend_life.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  string_range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
class string_range;

template <typename CharT, typename Traits, typename Alloc>
class string_range {

std::basic_string<CharT, Traits, Alloc> * con;
std::size_t pos;

public:

using read_type = CharT;
using write_type = read_type;

/*===========================================================
  ctor
===========================================================*/
string_range (
  std::basic_string<CharT, Traits, Alloc> &
);

/*===========================================================
  copy ctor
===========================================================*/
string_range (string_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
string_range (string_range &&) = default;

/*===========================================================
  copy assignemnt operator
===========================================================*/
string_range & operator = (string_range const &) = default;

/*===========================================================
  move assignemnt operator
===========================================================*/
string_range & operator = (string_range &&) = default;

/*===========================================================
  dtor
===========================================================*/
~string_range() = default;

/*===========================================================
  save
===========================================================*/
string_range &
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
return this->con->size();
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
CharT const &
operator * (
){
return (*this->con)[this->pos-1];
}

/*===========================================================
  operator =
===========================================================*/
void
operator = (
  CharT const & _var
){
(*this->con)[this->pos-1] = _var;
}

/*===========================================================
  operator ++
===========================================================*/
string_range &
operator ++ (
){
++this->pos;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
string_range &
operator -- (
){
--this->pos;
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
string_range &
operator += (
  std::size_t const _n
){
this->pos += _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
string_range &
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
return this->pos <= this->con->size();
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
  erase
===========================================================*/
string_range &
erase (
){
this->con->erase(this->position(), 1);
return *this;
}

/*===========================================================
  erase_all
===========================================================*/
string_range &
erase_all (
){
this->con->clear();
return *this;
}

/*===========================================================
  shrink
===========================================================*/
string_range &
shrink (
  std::size_t _n
){
this->con->resize(this->size()-_n);
return *this;
}

/*===========================================================
  expand
===========================================================*/
string_range &
expand (
  std::size_t _n 
){
this->con->resize(this->size()+_n);
return *this;
}

/*===========================================================
  insert
===========================================================*/
string_range &
insert (
  CharT _char
){
this->con->insert(this->position(), _char);
return *this;
}

}; //--------------------------------------------string range

/*===========================================================
  string_range:: ctor
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
string_range<CharT, Traits, Alloc>::string_range (
  std::basic_string<CharT, Traits, Alloc> & _str 
)
: con {&_str}
, pos {1}
{}

}
//-------------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
bits::string_range<CharT, Traits, Alloc>
range (
  std::basic_string<CharT, Traits, Alloc> &
);

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
bits::extend_life
< bits::string_range<CharT, Traits, Alloc>
, std::basic_string<CharT, Traits, Alloc>
>
range (
  std::basic_string<CharT, Traits, Alloc> &&
);

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
bits::string_range<CharT, Traits, Alloc>
range (
  std::basic_string<CharT, Traits, Alloc> & _str
){
return bits::string_range<CharT, Traits, Alloc> {_str};
}

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
bits::extend_life
< bits::string_range<CharT, Traits, Alloc>
, std::basic_string<CharT, Traits, Alloc>
>
range (
  std::basic_string<CharT, Traits, Alloc> && _con
){
auto temp = bits::extend_life
< bits::string_range<CharT, Traits, Alloc>
, std::basic_string<CharT, Traits, Alloc>
>{range(_con), _con};

temp.set_range(range(_con));

return temp;
}

}
//------------------------------------------------range layer
#endif

