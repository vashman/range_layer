//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GETOPT_RANGE_CPP
#define RANGE_LAYER_GETOPT_RANGE_CPP

#include <unistd.h>

namespace range_layer {

getopt_range::getopt_range (
  char *const * _argv
, std::string _opts
, int _argc
)
: local_optind (optind)
, local_opts (":" + _opts)
, local_argc (_argc)
, option ()
, local_argv (_argv)
// is_readable will not detect an error on first read.
, rv (-2)
{}

getopt_iterator
begin (
  getopt_range & _range
){
return getopt_iterator (
  _range.local_optind
, _range.local_argv
, _range.local_opts
, _range.local_argc
, _range.rv
);
}

getopt_iterator
end (
  getopt_range const & _range
){
return getopt_iterator();
}

bool
is_readable (
  getopt_range const _range
){
return (-1 == _range.rv) && (_range.local_argc > 0);
}

getopt_range
next (
  getopt_range _range
, typename range_traits<getopt_range>::difference_type _n
){
/* set getopt state to local state. */
int global_optind = optind;
optind = _range.local_optind;

  do {
    _range.rv =  getopt (
    _range.local_argc
  , _range.local_argv
  , _range.local_opts.c_str() );
  --_n;
  } while (0 != _n);

  if (-1 != _range.rv){
  // if a '?' character, then an error is found.
  _range.option.get_option() = static_cast<char>(_range.rv);
    if (
       '?' != static_cast<char>(_range.rv)
    && ':' != static_cast<char>(_range.rv)
    && optarg != NULL
    ){
    _range.option.get_arg() = optarg;
    }
  }
  
/* restore get opt state */
_range.local_optind = optind;
optind = global_optind;

return _range;
}

program_option
read (
  getopt_range _range
){
next(_range);
return _range.option;
}

} /* range layer */
#endif

