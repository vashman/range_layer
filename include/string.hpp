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

using read_type = T;
using write_type = read_type;

/*===========================================================
  ctor
===========================================================*/
string_range (
  std::basic_string<CharT, Traits, Alloc> &
);

string_range (string_range const &) = default;
string_range (string_range &&) = default;
string_range & operator = (string_range const &) = default;
string_range & operator = (string_range &&) = default;
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
  save
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
T const &
operator * (
){
return *this->con[this->pos-1];
}

/*===========================================================
  operator =
===========================================================*/
void
operator = (
  T const & _var
){
*this->con[this->pos-1] = _var;
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
  std::basic_string<CharT, Traits, Alloc> _str 
){

return *this;
}

/*===========================================================
  erase_all
===========================================================*/
string_range &
erase_all (
  std::basic_string<CharT, Traits, Alloc> _str 
){

return *this;
}

/*===========================================================
  shrink
===========================================================*/
string_range &
shrink (
  std::basic_string<CharT, Traits, Alloc> _str 
){

return *this;
}

/*===========================================================
  expand
===========================================================*/
string_range &
expand (
  std::basic_string<CharT, Traits, Alloc> _str 
){

return *this;
}

/*===========================================================
  insert
===========================================================*/
string_range &
insert (
  std::basic_string<CharT, Traits, Alloc> _str 
){
this->con->insert(_str);
return *this;
}

}; /* string range */


/*===========================================================
  string_range:: ctor
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
string_range<T, Traits, Alloc>::string_range (
  std::basic_string<CharT, Traits, Alloc> & _str 
)
: con {&_str}
, pos {1}
{}

} /* bits */

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
string_range<CharT, Traits, Alloc>
range (
  std::basic_string<CharT, Traits, Alloc> &
);

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
bits::extend_life
< vector_range<T, Alloc>
, std::vector<T, Alloc>
>
range (
  std::basic_string<CharT, Traits, Alloc> &&
);

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
string_range<CharT, Traits, Alloc>
range (
  std::basic_string<CharT, Traits, Alloc> & _str
){
return string_range<CharT, Traits, Alloc> {_str};
}

/*===========================================================
  range
===========================================================*/
template <typename CharT, typename Traits, typename Alloc>
bits::extend_life
< string_range<CharT, Traits, Alloc>
, std::basic_string<CharT, Traits, Alloc>
>
range (
  std::basic_string<CharT, Traits, Alloc> && _con
){
auto temp = bits::extend_life
< string_range<CharT, Traits, Alloc>
, std::basic_string<CharT, Traits, Alloc>
>{range(_con), _con};

temp.set_range(range(_con));

return temp;
}

} /* range layer */
#endif

