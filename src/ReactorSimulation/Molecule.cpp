#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

Molecule::Molecule(MaterialPoint const &center) : center_(center) {}
Molecule::Molecule(Molecule const &mol) : center_(mol.center_) {}
Molecule::~Molecule() = default;

} // namespace ReactorSimulation
