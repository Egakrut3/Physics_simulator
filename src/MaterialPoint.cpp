#include "ReactorTypes.hpp"

namespace Reactor {

MaterialPoint::MaterialPoint(Vector2 const position, Vector2 const velocity,
							 Weight_t const weight)
	: position_(position), velocity_(velocity), weight_(weight) {}
MaterialPoint::~MaterialPoint() = default;

} // namespace Reactor
