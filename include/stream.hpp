//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_STREAM_RANGE_HPP
#define RANGE_LAYER_STREAM_RANGE_HPP

#include "iterator_range.hpp"
#include "bits/decor/extend_life.hpp"
#include <iostream>
#include <iterator>

namespace range_layer {

template <typename CharT, typename Traits>
iterator_range<std::istream_iterator<CharT, Traits>>
range (
  std::basic_istream<CharT, Traits> &
);

template <typename CharT, typename Traits>
iterator_range<std::ostream_iterator<CharT, Traits>, void>
range (
  std::basic_ostream<CharT, Traits> &
);

template <typename CharT, typename Traits>
iterator_range<std::istream_iterator<CharT, Traits>>
range (
  std::basic_istream<CharT, Traits> &&
);

template <typename CharT, typename Traits>
iterator_range<std::ostream_iterator<CharT, Traits>, void>
range (
  std::basic_ostream<CharT, Traits> &&
);

template <typename CharT, typename Traits>
iterator_range<std::istream_iterator<CharT, Traits>>
range (
  std::basic_istream<CharT, Traits> & _stream
){
return make_iterator_range (
  std::istream_iterator<CharT, Traits>{_stream}
, std::istream_iterator<CharT, Traits>{}
);
}

template <typename CharT, typename Traits>
iterator_range<std::ostream_iterator<CharT, Traits>, void>
range (
  std::basic_ostream<CharT, Traits> & _stream
){
return make_iterator_range (
  std::ostream_iterator<CharT, Traits>{_stream}
);
}

template <typename CharT, typename Traits>
iterator_range<std::istream_iterator<CharT, Traits>>
range (
  std::basic_istream<CharT, Traits> && _stream
){
using std::get;

auto temp = bits::extend_life
< iterator_range<std::istream_iterator<CharT, Traits>>
, std::basic_istream<CharT, Traits>
> { make_iterator_range (
  std::istream_iterator<CharT, Traits>{_stream}
, std::istream_iterator<CharT, Traits>{}
)
, _stream
};

temp.set_range ( make_iterator_range (
  std::istream_iterator<CharT, Traits>{get<0>(temp.varables)}
, std::istream_iterator<CharT, Traits>{}
));
return temp;
}

template <typename CharT, typename Traits>
iterator_range<std::ostream_iterator<CharT, Traits>, void>
range (
  std::basic_ostream<CharT, Traits> && _stream
){
using std::get;

auto temp = bits::extend_life
< iterator_range<std::ostream_iterator<CharT, Traits>>
, std::basic_ostream<CharT, Traits>
> {
  make_iterator_range
  (std::ostream_iterator<CharT, Traits>{_stream})
, _stream
};

temp.set_range ( make_iterator_range (
  std::ostream_iterator<CharT, Traits>{get<0>(temp.varables)}
));
return temp;
}

} /* range layer */
#endif

