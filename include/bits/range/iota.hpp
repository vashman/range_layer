//

//          Copyright Sundeep S. Sangha 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_IOTA_RANGE_HPP
#define RANGE_LAYER_IOTA_RANGE_HPP

//#include <type_traits>
//#include "../../range_traits.hpp"

namespace range_layer {

/*===============================================================
  iota range

# ```T darin ()```
* To leave the range in a valid state, T will always be copied.
================================================================*/
template <typename T>
class range<T *, range_class::iota> {

public:

explicit range      (T *);
        ~range      ()              = default;
         range      (const range &) = default;
         range      (range &&)      = default;
range &  operator = (const range &) = default;
range &  operator = (range &&)      = default;

void           write    (const T, T);
void           swap     ();
T              drain    ();
T const &      read     (const T) const;
T              size     () const;
T              position () const;
constexpr bool has_io   () const;
constexpr int  rw_size  () const;
void           next     ();
void           prev     ();

private:

T * handle;

}; //-----------------------------------------------------------------iota range

/*==============================================================================
  const iota range
==============================================================================*/
template <typename T>
class range<const T *, range_class::iota>
: public range<const T *, range_class::variable>
{

public:

explicit range      (const T *);
        ~range      ()              = default;
         range      (const range &) = default;
         range      (range &&)      = default;
range &  operator = (const range &) = default;
range &  operator = (range &&)      = default;

}; //-----------------------------------------------------------const iota range
} //-----------------------------------------------------------------range layer
#endif
#include "iota.tcc"

