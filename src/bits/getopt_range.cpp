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
  char * const * _argv
, std::string _opts
, int _argc
)
: local_optind (optind)
, local_opts (":" + _opts)
, local_argc (_argc)
, option ()
, local_argv (_argv)
, rv (-1)
{}

bool
getopt_range::operator == (
  sentinel::readable const _sen
) const {
return (-1 == this->rv) && (this->local_argc > 0);
}

getopt_range &
getopt_range::operator ++ (){
/* set getopt state to local state. */
int global_optind = optind;
optind = this->local_optind;

this->rv =  getopt (
  this->local_argc
, this->local_argv
, this->local_opts.c_str()
);

  if (-1 != this->rv){
  // if a '?' character, then an error is found.
  this->option.get_option() = static_cast<char>(this->rv);
    if (
       '?' != static_cast<char>(this->rv)
    && ':' != static_cast<char>(this->rv)
    && optarg != NULL
    ){
    this->option.get_arg() = optarg;
    }
  }
  
/* restore get opt state */
this->local_optind = optind;
optind = global_optind;

return *this;
}

program_option &
getopt_range::operator * (){
return this->option;
}

} /* range layer */
#endif

