#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

Molecule::Molecule(MaterialPoint const &center) : center_(center) {}
Molecule::~Molecule() = default;

} // namespace ReactorSimulation
