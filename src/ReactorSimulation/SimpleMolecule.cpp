#include "ReactorSimulation/GraphicEngine.hpp"
#include "ReactorSimulation/PhysicsEngine.hpp"

namespace ReactorSimulation {

SimpleMolecule::SimpleMolecule(MaterialPoint const &center,
                               Measure_t const     &radius) :
    Molecule(center), radius_(radius) {}
SimpleMolecule::~SimpleMolecule() = default;

void SimpleMolecule::draw(GraphicEngine &gr_eng) const {
    gr_eng.draw(*this);
}

void SimpleMolecule::advance(PhysicsEngine const &ph_eng,
                             Measure_t const     &time_delta) {
    ph_eng.advance(*this, time_delta);
}

bool SimpleMolecule::collide_with_vertical(PhysicsEngine const &ph_eng,
                                           Measure_t const     &x_coor) const {
    return ph_eng.collide_with_vertical(*this, x_coor);
}
bool SimpleMolecule::collide_with_horizontal(PhysicsEngine const &ph_eng,
                                             Measure_t const &y_coor) const {
    return ph_eng.collide_with_horizontal(*this, y_coor);
}

bool SimpleMolecule::collide(Molecule const      &mol,
                             PhysicsEngine const &ph_eng) const {
    return mol.collide(*this, ph_eng);
}
bool SimpleMolecule::collide(SimpleMolecule const &mol,
                             PhysicsEngine const  &ph_eng) const {
    return ph_eng.collide(mol, *this);
}
bool SimpleMolecule::collide(ComplexMolecule const &mol,
                             PhysicsEngine const   &ph_eng) const {
    return ph_eng.collide(mol, *this);
}

} // namespace ReactorSimulation
