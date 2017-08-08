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

template <typename CharT, typename Traits, typename Alloc>
struct string_range;

template <typename CharT, typename Traits, typename Alloc>
struct string_range {

private:

std::basic_string<CharT, Traits, Alloc> * con;
std::size_t pos;

public:

using read_type = T;
using write_type = read_type;

string_range (
  std::basic_string<CharT, Traits, Alloc> &
);

string_range (string_range const &) = default;
string_range (string_range &&) = default;
string_range & operator = (string_range const &) = default;
string_range & operator = (string_range &&) = default;
~string_range() = default;

string_range &
save (
){
return *this;
}

std::size_t
size (
) const {
return this->con->size();
}

std::size_t
position (
) const {
return this->pos;
}

T const &
operator * (
){
return *this->con[this->pos-1];
}

void
operator = (
  T const & _var
){
*this->con[this->pos-1] = _var;
}

string_range &
operator ++ (
){
++this->pos;
return *this;
}

string_range &
operator -- (
){
--this->pos;
return *this;
}

string_range &
operator += (
  std::size_t const _n
){
this->pos += _n;
return *this;
}

string_range &
operator -= (
  std::size_t const _n
){
this->pos -= _n;
return *this;
}

bool
operator == (
  sentinel::readable const _sen
) const {
return this->pos <= this->con->size();
}

bool
operator == (
  sentinel::writable const _sen
) const {
return *this == sentinel::readable{};
}

}; /* string range */

template <typename CharT, typename Traits, typename Alloc>
vector_range<T, Alloc>::vector_range (
  std::vector<T, Alloc> & _vec
)
: vec {&_vec}
, pos {1}
{}

} /* bits */

template <typename CharT, typename Traits, typename Alloc>
string_range<CharT, Traits, Alloc>
range (
  std::basic_string<CharT, Traits, Alloc> &
);

template <typename CharT, typename Traits, typename Alloc>
bits::extend_life
< vector_range<T, Alloc>
, std::vector<T, Alloc>
>
range (
  std::basic_string<CharT, Traits, Alloc> &&
);

template <typename CharT, typename Traits, typename Alloc>
string_range<CharT, Traits, Alloc>
range (
  std::basic_string<CharT, Traits, Alloc> & _str
){
return string_range<CharT, Traits, Alloc> {_str};
}

template <typename CharT, typename Traits, typename Alloc>
bits::extend_life
< vector_range<T, Alloc>
, std::vector<T, Alloc>
>
range (
  std::vector<T, Alloc> && _vec
){
auto temp = bits::extend_life
< vector_range<T, Alloc>
, std::vector<T, Alloc>
>{vector_range<T, Alloc> {_vec}, _vec};

temp.set_range(vector_range<T, Alloc> {_vec});

return temp;
}

} /* range layer */
#endif

