#ifndef PHYSICS_ENGINE
#define PHYSICS_ENGINE

#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

class PhysicsEngine {
public:
    explicit PhysicsEngine() = default;
    void advance_state(Reactor &reactor, Measure_t const &dt);
    void perform_reflections(Reactor &reactor);
};

} // namespace ReactorSimulation

#endif
