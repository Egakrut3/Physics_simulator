#include "ReactorTypes.hpp"

namespace Reactor {

Molecule::Molecule(MaterialPoint const &center) : center_(center) {}
Molecule::~Molecule() = default;

} // namespace Reactor
