#ifndef PHYSICS_ENGINE
#define PHYSICS_ENGINE

#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

class PhysicsEngine {
public:
	void advance_state(Reactor &reactor, Measure_t const &dt);
};

} // namespace ReactorSimulation

#endif
