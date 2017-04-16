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

//private:

std::vector<T> * vec;
std::size_t pos;

};

template <typename T>
vector_range<T>::vector_range (
  vector<T> & _vec
)
: vec {&_vec}
, pos {1}
{}

template <typename T>
T&
read (
  vector_range<T> const & _range
){
return *_range.vec[_range.pos-1];
}

template <typename T>
void
write (
  vector_range<T> & _range
, T const & _var
){
*_range.vec[_range.pos-1] = _var;
}

template <typename T>
vector_range<T>
next (
  vector_range<T> _range
, std::size_t const _n = 1
){
_range.pos += _n;
return _range;
}

template <typename T>
vector_range<T>
prev (
  vector_range<T> _range
, std::size_t const _n = 1
){
_range.pos -= _n;
return _range;
}

template <typename T>
void
advance (
  vector_range<T> & _range
, std::size_t const _n = 1
){
_range.pos += _n;
return _range;
}

template <typename T>
void
prev_advance (
  vector_range<T> & _range
, std::size_t const _n = 1
){
_range.pos -= _n;
return _range;
}

template <typename T>
bool
has_writeable (
  vector_range<T> const & _range
){
return _range.pos <= _range.vec->size();
}

template <typename T>
bool
has_readable (
  vector_range<T> const & _range
){
return has_writeable(_range);
}

template <typename T>
vector_range<T>
erase (
  vector_range<T> _range
){
_range.vec->erase(_range.vec->begin() + (_range.pos-1));
return _range;
}

template <typename T>
vector_range<T>
insert (
  vector_range<T> _range
, T const & _var
){
_range.vec->insert(
  (_range.vec->begin() + _range.pos-1), _var );
return _range;
}

template <typename T>
vector_range<T>
expand (
  vector_range<T> _range
, std::size_t const _n
){
_range.vec->resize(_range.vec->size() + _n);
return _range;
}

template <typename T>
vector_range<T>
shrink (
  vector_range<T> _range
, std::size_t const _n
){
_range.vec->resize(_range.vec->size() - _n);
return _range;
}

} /* range layer */
#endif

