// std Memory ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SPEC_MEMORY_HPP
#define RANGE_LAYER_SPEC_MEMORY_HPP

#include <memory>

namespace range_layer {

template <typename T, typename Deleter>
class range<std::unique_ptr<T, Deleter>>
: public range
< std::unique_ptr<T, Deleter>
, enable_range::smart_pointer
>
{};

template <typename T, typename Deleter>
class range<std::unique_ptr<const T, Deleter>>
: public range
< std::unique_ptr<const T, Deleter>
, const enable_range::smart_pointer
>
{};

} //----------------------------------------------range layer
#endif
