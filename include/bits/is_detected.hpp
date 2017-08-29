
// http://en.cppreference.com/w/cpp/experimental/is_detected

#ifndef RANGE_LAYER_BITS_ISDISABLED_HPP
#define RANGE_LAYER_BITS_ISDISABLED_HPP

#include <type_traits>

namespace range_layer {
namespace bits {

template<typename... > using void_t = void;

struct nonesuch {
nonesuch() = delete;
~nonesuch() = delete;
nonesuch(nonesuch const&) = delete;
void operator=(nonesuch const&) = delete;
};

namespace detail {

template <
  typename Default
, typename AlwaysVoid
, template<class...> class Op
, typename... Args >
struct detector {
  using value_t = std::false_type;
  using type = Default;
};
 
template <
  typename Default
, template<class...> class Op
, typename... Args >
struct detector<Default, void_t<Op<Args...>>, Op, Args...> {
  using value_t = std::true_type;
  using type = Op<Args...>;
};
 
} // detail----------------------------------------------
 
template <template<class...> class Op, class... Args>
using is_detected = typename
  detail::detector<nonesuch, void, Op, Args...>::value_t;

template <
  class Default
, template <typename...> class Op
, typename... Args >
using detected_or
  = detail::detector<Default, void, Op, Args...>;

} // bits---------------------------------------------
} // range layer--------------------------------------
#endif

