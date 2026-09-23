#include "ReactorTypes.hpp"

namespace Reactor {

Vector2::Vector2() : x_coor_(), y_coor_() {}
Vector2::Vector2(Measure_t const &x_coor, Measure_t const &y_coor) :
	x_coor_(x_coor), y_coor_(y_coor) {}

} // namespace Reactor
