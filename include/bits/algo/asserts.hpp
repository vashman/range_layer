// internal static assert messages for range layer.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ALGO_ASSERTS_HPP
#define RANGE_LAYER_BITS_ALGO_ASSERTS_HPP

namespace range_layer {
namespace bits {
namespace assert_err {

//constexpr char* const
//  assert_head = "Range Layer Error: ";
//, not_range = assert_head ;

} // assert err----------------------------------------------

/*===========================================================
  range assert
===========================================================*/
template <typename Range>
constexpr int range_assert (){
static_assert (
  range_trait::is_range<Range>::value
, "Not a range."
);

return 0;
}

/*===========================================================
  read assert
===========================================================*/
template <typename Range>
constexpr int read_assert (){
static_assert (
  range_trait::is_input<Range>::value
, "Not a input range."
);
return 0;
}

/*===========================================================
  not read assert
===========================================================*/
template <typename Range>
constexpr int not_read_assert (){
static_assert (
  ! range_trait::is_input<Range>::value
, "Cannot be a input range."
);
return 0;
}

/*===========================================================
  write assert
===========================================================*/
template <typename Range>
constexpr int write_assert (){
static_assert (
  range_trait::is_output<Range>::value
, "Not a output range."
);
return 0;
}

/*===========================================================
  not write assert
===========================================================*/
template <typename Range>
constexpr int not_write_assert (){
static_assert (
  ! range_trait::is_output<Range>::value
, "Cannot be a output range."
);
return 0;
}

/*===========================================================
  erase assert
===========================================================*/
template <typename Range>
constexpr int erase_assert (){
static_assert (
  range_trait::is_erasable<Range>::value
, "Not a erasable range."
);
return 0;
}

/*===========================================================
  reversable assert
===========================================================*/
template <typename Range>
constexpr int reversible_assert (){
static_assert (
  range_trait::is_reversable<Range>::value
, "Not a reversable range."
);
return 0;
}

/*===========================================================
  finite assert
===========================================================*/
template <typename Range>
constexpr int finite_assert (){
static_assert (
  range_trait::is_finite<Range>::value
, "Not a finite range."
);
return 0;
}

/*===========================================================
  position assert
===========================================================*/
template <typename Range>
constexpr int position_assert (){
static_assert (
  range_trait::has_position<Range>::value
, "Range elements do not have a postion."
);
return 0;
}

/*===========================================================
  shrinkable assert
===========================================================*/
template <typename Range>
constexpr int shrinkable_assert (){
static_assert (
  range_trait::is_shrinkable<Range>::value
, "Range is not shrinkable."
);
return 0;
}

/*===========================================================
  singleton assert
===========================================================*/
template <typename Range>
constexpr int singleton_assert (){
static_assert (
  range_trait::is_singleton<Range>::value
, "Range is not singleton."
);
return 0;
}

/*===========================================================
  not singleton assert
===========================================================*/
template <typename Range>
constexpr int not_singleton_assert (){
static_assert (
  ! range_trait::is_singleton<Range>::value
, "Range cannot be a singleton."
);
return 0;
}

/*===========================================================
  not decorator assert
===========================================================*/
template <typename Range>
constexpr int not_decorator_assert (){
static_assert (
  ! range_trait::is_decorator<Range>::value
, "Range cannot be a decorator."
);
return 0;
}

/*===========================================================
  decorator assert
===========================================================*/
template <typename Range>
constexpr int decorator_assert (){
static_assert (
  range_trait::is_decorator<Range>::value
, "Range must be a decorator."
);
return 0;
}

/*===========================================================
  expandable assert
===========================================================*/
template <typename Range>
constexpr int expandable_assert (){
static_assert (
  range_trait::is_expandable<Range>::value
, "Range must be expandable."
);
return 0;
}

/*===========================================================
  linear assert
===========================================================*/
template <typename Range>
constexpr int linear_assert (){
static_assert (
  range_trait::is_linear<Range>::value
, "Range must be linear."
);
return 0;
}

/*===========================================================
  predicate assert
===========================================================*/
template <typename Pred>
constexpr int predicate_assert (){
static_assert (
  std::is_copy_constructible<Pred>::value
, "Predicate must be copy constructible."
);
return 0;
}

/*===========================================================
  insert assert
===========================================================*/
template <typename Range>
constexpr int insert_assert (){
static_assert (
  range_trait::is_insertable<Range>::value
, "Range must be insertable."
);
return 0;
}

} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif
