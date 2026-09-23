#include "ReactorTypes.hpp"

namespace Reactor {

SimpleMolecule::SimpleMolecule(Vector2 const position, Vector2 const velocity,
							   Weight_t const weight)
	: MaterialPoint(position, velocity, weight) {}
SimpleMolecule::~SimpleMolecule() = default;

} // namespace Reactor
