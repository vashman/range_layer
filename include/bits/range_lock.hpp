// Size and lock type for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_LOCK_HPP
#define RANGE_LAYER_RANGE_LOCK_HPP

namespace range_layer {

template <typename Lock = void>
class range_lock {

Lock lock;

public:

std::size_t count;

range_lock (
  Lock
, std::size_t
);

range_lock (range_lock const &) = default;
range_lock (range_lock &&) = default;
range_lock & operator = (range_lock const &) = default;
range_lock & operator = (range_lock &&) = default;
~range_lock () = default;

};

template <>
class range_lock<void> {
public:

std::size_t count;

range_lock (
  std::size_t
);

range_lock (range_lock const &) = default;
range_lock (range_lock &&) = default;
range_lock & operator = (range_lock const &) = default;
range_lock & operator = (range_lock &&) = default;
~range_lock () = default;

};

template <typename Lock>
range_lock<Lock>::range_lock (
  Lock _lock
, std::size_t _count
)
: lock (_lock)
, count (_count)
{}

template <>
range_lock<void>::range_lock (
  std::size_t _count
)
: count (_count)
{}

} /* range layer */
#endif

