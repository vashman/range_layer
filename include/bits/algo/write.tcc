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
check::is_ouput<Range>{};

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
check::is_ouput<Range>{};

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
check::is_ouput<Range>{};

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
check::is_ouput<Range>{};

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
check::is_input<IRange>{};
check::is_ouput<ORange>{};

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
check::is_input<IRange>{};
check::is_ouput<ORange>{};

  while (has_writable(_output) && had_readable(_input)){
  auto temp = read(_input);
    if (_pred(temp)) write(_output, temp);
  advance(_output, _input);
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
check::is_input<IRange>{};
check::is_output<ORange>{};

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
