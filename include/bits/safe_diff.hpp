
namespace range_layer {

template <typename T>
struct safe_diff {

T count;

safe_diff &
operator ++ (){

return *this;
}

};

} /* range layer */
#endif

