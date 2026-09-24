#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

MaterialPoint::MaterialPoint(Vector2D const &position, Vector2D const &velocity,
                             Weight_t const &weight) :
    position_(position), velocity_(velocity), weight_(weight) {}
MaterialPoint::~MaterialPoint() = default;

} // namespace ReactorSimulation
