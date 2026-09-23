#include "ReactorTypes.hpp"

namespace Reactor {

SimpleMolecule::SimpleMolecule(MaterialPoint const &center,
							   Measure_t const &radius) :
	Molecule(center), radius_(radius) {}
SimpleMolecule::~SimpleMolecule() = default;

} // namespace Reactor
