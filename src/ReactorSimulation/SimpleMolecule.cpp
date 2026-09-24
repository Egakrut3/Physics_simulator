#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

SimpleMolecule::SimpleMolecule(MaterialPoint const &center,
                               Measure_t const &radius) :
    Molecule(center), radius_(radius) {}
SimpleMolecule::SimpleMolecule(SimpleMolecule const &src) :
    Molecule(src), radius_(src.radius_) {}
SimpleMolecule::~SimpleMolecule() = default;

} // namespace ReactorSimulation
