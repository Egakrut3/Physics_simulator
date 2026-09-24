#include "ReactorSimulation/Types.hpp"
#include <iostream>

namespace ReactorSimulation {

SimpleMolecule::SimpleMolecule(MaterialPoint const &center,
                               Measure_t const &radius) :
    Molecule(center), radius_(radius) {}
SimpleMolecule::~SimpleMolecule() = default;

bool SimpleMolecule::collide_with(Molecule const &mol) const {
    std::cout << "Called from Simple" << std::endl;

    return mol.collide_with(*this);
}

bool SimpleMolecule::collide_with(SimpleMolecule const &mol) const {
    std::cout << "Simple and Simple" << std::endl;
    return (center_.position_ - mol.center_.position_).len2() <=
           (radius_ + mol.radius_) * (radius_ + mol.radius_);
}

bool SimpleMolecule::collide_with(ComplexMolecule const &mol) const {
    std::cout << "Simple and Complex" << std::endl;

    return mol.collide_with(*this);
}

} // namespace ReactorSimulation
