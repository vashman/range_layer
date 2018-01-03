//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_VARIABLE_HPP
#define RANGE_LAYER_BITS_RANGE_VARIABLE_HPP

namespace range_layer {
namespace range_class {
/*==============================================================================
  variable range
==============================================================================*/
template <typename H, typename S>
class  variable : public variable<const H, S> {

public:

using value_type = H;
using size_type  = std::size_t;

explicit    variable   (S);
           ~variable   ()                 = default;
            variable   (const variable &) = default;
            variable   (variable &&)      = default;
variable &  operator = (const variable &) = default;
variable &  operator = (variable &&)      = default;

void write (const std::size_t, H);
void swap  (H &);
H    drain ();

}; //-------------------------------------------------------------variable range

/*==============================================================================
  variable range
==============================================================================*/
template <typename H, typename S>
class variable <const H, S> {

public:

using value_type = H;
using size_type  = std::size_t;

explicit    variable   (S);
           ~variable   ()                 = default;
            variable   (const variable &) = default;
            variable   (variable &&)      = default;
variable &  operator = (const variable &) = default;
variable &  operator = (variable &&)      = default;

constexpr bool        has_io   () const;
constexpr std::size_t rw_size  () const;
constexpr std::size_t size     () const;
constexpr std::size_t position () const;
const H &             read     (const std::size_t) const;
void                  next     ();

private:

S    handle;
bool last;

}; //-------------------------------------------------------const variable range
} //-----------------------------------------------------------------range class
} //-----------------------------------------------------------------range layer
#endif
#include "variable.tcc"

