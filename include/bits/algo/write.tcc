//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_WRITE_TCC
#define RANGE_LAYER_ALGO_WRITE_TCC

namespace range_layer {

/*
  fill
*/
template <typename Range, typename T>
Range
fill (
  execution_policy::sequenced
, Range _range
, T const & _var
){
static_assert (range_traits<Range>::is_output, "Not output range.");

  while (has_writeable(_range)){
  write(_range, _var);
  advance(_range);
  }
return _range;
}

/*
  fill n
*/
template <typename Range, typename T, typename N>
Range
fill (
  execution_policy::sequenced
, Range _range
, T const & _var
, N _n
){
static_assert (range_traits<Range>::is_output, "Not output range.");

  while (has_writeable(_range) && (0 != _n)){
  write(_range, _var);
  advance(_range);
  --_n;
  }
return _range;
}

/* generate */
template<typename Range, typename Generator>
Range
generate (
  execution_policy::sequenced
, Range _range
, Generator _gen
){
static_assert (range_traits<Range>::is_output, "Not output range.");

  while (has_writable(_range)){
  write(_range, _gen());
  advance(_range);
  }
return _range;
}

/* generate n */
template<typename Range, typename Generator, typename N>
Range
generate_n (
  execution_policy::sequenced
, Range _range
, N _n
, Generator _gen
){
static_assert (range_traits<Range>::is_output, "Not output range.");

  while (has_writable(_range) && (0 != _n)){
  write(_range, _gen());
  advance(_range);
  --_n;
  }
return _range;
}

/*
  copy
*/
template <typename IRange, typename ORange>
ORange
copy (
  execution_policy::sequenced
, IRange _input
, ORange _output
){
static_assert (range_traits<IRange>::is_input, "Not input range.");
static_assert (range_traits<ORange>::is_output, "Not output range.");

  while (has_writable(_output) && has_readable(_input)){
  write(_output, read(_input));
  advance(_output, _input);
  }
return _output;
}

/*
  copy if
*/
template <typename IRange, typename ORange, typename Pred>
ORange
copy_if (
  execution_policy::sequenced
, IRange _input
, ORange _output
, Pred _pred
){
static_assert (range_traits<IRange>::is_input, "Not input range.");
static_assert (range_traits<ORange>::is_output, "Not output range.");

  while (has_writable(_output) && had_readable(_input)){
  auto temp = read(_input);
    if (_pred(temp)) write(_output, temp);
  advance(_output, _input);
  }
return _output;
}

/*
  copy
*/
template <typename IRange, typename ORange>
ORange
write (
  execution_policy::sequenced
, IRange _input
, ORange _output
){
static_assert (range_traits<IRange>::is_input, "Not input range.");
static_assert (range_traits<ORange>::is_output, "Not output range.");

using range_layer::advance;

  while (has_writable(_output) && has_readable(_input)){
  write(_output, read(_input));
  range_layer::advance(_output, _input);
  }
return _output;
}

/*
  copy n
*/
template <typename IRange, typename ORange, typename N>
ORange
copy_n (
  execution_policy::sequenced
, IRange _input
, ORange _output
, N _n
){
static_assert (range_traits<IRange>::is_input, "Not input range.");
static_assert (range_traits<ORange>::is_output, "Not output range.");

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

} /* range layer */
#endif
