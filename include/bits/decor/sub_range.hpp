//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SUB_RANGE_HPP
#define RANGE_LAYER_SUB_RANGE_HPP

namespace range_layer {
namespace bits {

template <typename Range, typename S>
class sub_range_n {

Range range;
S pos;
S count;
using trait = range_traits<Range>;

bool
is_end () const {
return (this->pos > this->count) || (this->pos == 0);
}

public:

using read_type = typename trait::read_type;
using write_type = typename trait::write_type;

static constexpr bool const
  is_io_synced = trait::is_io_synced;

static constexpr validation_type const
  validation = trait::validation;

static constexpr bool const
  is_input_temporary = trait::input::is_temporary;

static constexpr range_size const
  input_size_type = range_size::finite;

static constexpr bool const
  is_output_temporary = trait::output::is_temporary;

static constexpr range_size const
  output_size_type = range_size::finite;

sub_range_n (
  Range _range
, S _count
)
: range {_range}
, pos {1}
, count {_count}
{}

sub_range_n (sub_range_n const &) = default;
sub_range_n& operator = (sub_range_n const &) = default;
sub_range_n (sub_range_n &&) = default;
sub_range_n& operator = (sub_range_n &&) = default;
~sub_range_n() = default;

template <typename U = Range>
auto
operator * () -> decltype(*this->range){
return *this->range;
}

template <typename U = Range>
sub_range_n &
operator ++ (){
++this->pos;
++this->range;
return *this;
}

template <typename U = Range>
sub_range_n &
operator -- (){
--this->pos;
--this->range;
return *this;
}

template <typename T>
void
operator = (T const & _var){
this->range = _var;
}

template <typename N>
sub_range_n &
operator += (
  N _n
){
this->pos += _n;
this->range += _n;
return *this;
}

template <typename N>
sub_range_n &
operator -= (
  N _n
){
this->pos -= _n;
this->range -= _n;
return *this;
}

bool
operator == (
  sentinel::readable const & _sen
) const {
return this->range == _sen && !this->is_end();
}

template <typename U = Range>
bool
operator == (
  sentinel::writable const & _sen
) const {
return this->range == _sen && !this->is_end();
}

template <typename T>
bool
operator == (
  T const & _sen
) const {
return this->range == _sen && !this->is_end();
}

Range
disable (
) const {
return this->range;
} 

}; /* sub_range_n*/

} /* bits */ } /* range layer */
#endif

