//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <vector>

namespace range_layer {

template <typename T>
struct vector_range {

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_io_synced = true;
static constexpr bool const is_reversable = true;
static constexpr bool const is_erasable = true;
static constexpr bool const is_insertable = true;
static constexpr bool const is_input_temporary = false;
static constexpr bool const is_output_temporary = false;

static constexpr validation_type const
  validation = validation_type::unsynced;

static constexpr range_size const
  input_size_type = range_size::finite;

static constexpr range_size const
  output_size_type = range_size::finite;

vector_range (
  vector<T> &
);

vector_range (vector_range const &) = default;
vector_range (vector_range &&) = default;
vector_range & operator = (vector_range const &) = default;
vector_range & operator = (vector_range &&) = default;
~vector_range() = default;

private:

std::vector<T> * vec;
std::size_t pos;

const T& operator * (
){
return *this->vec[this->pos-1];
}

void
operator = (
  T const & _var
){
*this->vec[this->pos-1] = _var;
}

vector_range&
operator ++ (
){
++this->pos;
}

vector_range&
operator -- (
){
--this->pos;
}

vector_range&
operator += (
  std::size_t const _n
){
this->pos += _n;
}

vector_range&
operator -= (
  std::size_t const _n
){
this->pos -= _n;
}

bool
operator == (
  sentinal::readable const _sen
){
return this->pos <= this->vec->size();
}

bool
operator == (
  vector_range const & _lhs
){
return this->pos = _lhs.pos;
}

}; /* vector range */

template <typename T>
vector_range<T>::vector_range (
  vector<T> & _vec
)
: vec {&_vec}
, pos {1}
{}

} /* range layer */
#endif

