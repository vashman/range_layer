//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_WRITE_TCC
#define RANGE_LAYER_ALGO_WRITE_TCC

namespace range_layer {

/*===========================================================
  fill
===========================================================*/
template <typename Range, typename T>
Range
fill (
  execution_policy::sequenced
, Range _range
, T const & _var
){
bits::write_assert<Range>();

static_assert (
  range_trait::is_finite<Range>::value
, "Cannot fill an infinite range."
);

  while (has_writable(_range)){
  write(_range, _var);
  range_layer::advance(_range);
  }
return _range;
}

/*===========================================================
  fill n
===========================================================*/
template <typename Range, typename T, typename N>
Range
fill (
  execution_policy::sequenced
, Range _range
, T const & _var
, N _n
){
bits::write_assert<Range>();

  while (has_writable(_range) && (0 != _n)){
  write(_range, _var);
  range_layer::advance(_range);
  --_n;
  }
return _range;
}

/*===========================================================
  copy
===========================================================*/
template <typename IRange, typename ORange>
ORange
copy (
  execution_policy::sequenced
, IRange _input
, ORange _output
){
bits::read_assert<IRange>();
bits::write_assert<ORange>();

static_assert (
   range_trait::is_finite<IRange>::value
== range_trait::is_finite<ORange>::value
, "Both ranges must have a finite size."
);

  while (has_writable(_output) && has_readable(_input)){
  write(_output, read(_input));
  range_layer::advance(_output, _input);
  }
return _output;
}

/*===========================================================
  copy if
===========================================================*/
template <typename IRange, typename ORange, typename Pred>
ORange
copy_if (
  execution_policy::sequenced
, IRange _input
, ORange _output
, Pred _pred
){
bits::read_assert<IRange>();
bits::write_assert<ORange>();

  while (has_writable(_output) && had_readable(_input)){
  auto temp = read(_input);
    if (_pred(temp)) write(_output, temp);
  range_layer::advance(_output, _input);
  }
return _output;
}

/*===========================================================
  write
===========================================================*/
namespace bits {
template
< typename ORange
, typename IRange
, typename std::enable_if
  <range_trait::is_range<IRange>::value, int>::type = 0
>
void *
write (
  execution_policy::sequenced
, ORange & _output // Modify the output range.
, IRange & _input
){
bits::read_assert<IRange>();
bits::write_assert<ORange>();

  while (
     range_layer::has_writable(_output)
  && range_layer::has_readable(_input)){
  range_layer::write(_output, read(_input));
  range_layer::advance(_output, _input);
  }
return static_cast<void*>(0);
}

/*===========================================================
  write
===========================================================*/
template
< typename ORange
, typename T
, typename std::enable_if
  <! range_trait::is_range<T>::value, int>::type = 0
>
void *
write (
  execution_policy::sequenced
, ORange & _output // Modify the output range.
, T & _variable
){
  if (range_layer::has_writable(_output)){
  range_layer::write(_output, _variable);
  range_layer::advance(_output);
  }
return static_cast<void*>(0);
}
} //-----------------------------------------------------bits

/*===========================================================
  write
===========================================================*/
template <typename ORange, typename T, typename... Ts>
ORange
write (
  execution_policy::sequenced _policy
, ORange _output
, T _var
, Ts &&... _ts
){
bits::write_assert<ORange>();

bits::write(_policy, _output, _var);
void* list[] = {0, bits::write(_policy, _output, _ts)...};
return _output;
}

/*===========================================================
  copy n
===========================================================*/
template <typename IRange, typename ORange, typename N>
ORange
copy_n (
  execution_policy::sequenced
, IRange _input
, ORange _output
, N _n
){
bits::read_assert<IRange>();
bits::write_assert<ORange>();

  while (
     has_writable(_output)
  && had_readable(_input)
  && (_n > 0)
  ){
  write(_output, read(_input));
  advance(_output, _input);
  --_n;
  }
return _output;
}

}
//range layer------------------------------------------------
#endif
