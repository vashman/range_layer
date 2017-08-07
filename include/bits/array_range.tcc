//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ARRAY_RANGE_TCC
#define RANGE_LAYER_ARRAY_RANGE_TCC

namespace range_layer {

template <typename T>
array_range<T>::array_range (
  T * _array
, T * _end
)
: array (_array)
, pos {_array}
, end_pos {_end}
{}

template <typename T>
array_range <T>
range (
  T * _ptr
, std::size_t _size
){
return array_range<T>{_ptr, _ptr + _size};
}

template <typename T, std::size_t N>
array_range <T>
range (
  std::array<T, N> & _arr
){
return array_range<T>{_arr.data(), _arr.data() + N};
}

template <typename T, std::size_t N>
bits::extend_life
< array_range <T>
, std::array<T, N>
>
range (
  std::array<T, N> && _arr
){
auto temp = bits::extend_life
< array_range <T>
, std::array<T, N>
>{array_range<T>{_arr.data(), _arr.data() + N}, _arr};

temp.set_range(array_range<T>{_arr.data(), _arr.data() + N});
return temp;
}

} /* range layer */
#endif

