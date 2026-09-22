#include "PhysicsSimulator.hpp"

namespace PhysicsSimulator {

SimpleMolecule::SimpleMolecule(Vector2 const position, Vector2 const velocity,
							   Weight_t const weight)
	: Molecule(position, velocity, weight) {}
SimpleMolecule::~SimpleMolecule() = default;

} // namespace PhysicsSimulator
