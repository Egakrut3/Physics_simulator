#include "PhysicsSimulator.hpp"

namespace PhysicsSimulator {

Molecule::Molecule(Vector2 const position, Vector2 const velocity,
				   Weight_t const weight)
	: position_(position), velocity_(velocity), weight_(weight) {}
Molecule::~Molecule() = default;

} // namespace PhysicsSimulator
