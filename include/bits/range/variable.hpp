//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_VARIABLE_HPP
#define RANGE_LAYER_BITS_RANGE_VARIABLE_HPP

namespace range_layer {
/*==============================================================================
  variable range
==============================================================================*/
template <typename T>
class range <T *, range_class::variable> 
: public range <const T *, range_class::variable>
{

public:

explicit range      (T *);
        ~range      ()              = default;
         range      (const range &) = default;
         range      (range &&)      = default;
range &  operator = (const range &) = default;
range &  operator = (range &&)      = default;

void write (const std::size_t, T);
void swap  (T &);
T    drain ();

private:

T * handle;

}; //-------------------------------------------------------------variable range

/*==============================================================================
  variable range
==============================================================================*/
template <typename T>
class range <const T *, range_class::variable> {

public:

explicit range      (const T *);
        ~range      ()              = default;
         range      (const range &) = default;
         range      (range &&)      = default;
range &  operator = (const range &) = default;
range &  operator = (range &&)      = default;

constexpr bool        has_io   () const;
constexpr std::size_t rw_size  () const;
constexpr std::size_t size     () const;
constexpr std::size_t position () const;
const T &             read     (const std::size_t) const;
void                  next     ();

private:

T * const_handle;

}; //-------------------------------------------------------const variable range
} //-----------------------------------------------------------------range layer
#endif
#include "variable.tcc"

