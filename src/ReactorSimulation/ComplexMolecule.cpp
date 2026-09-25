#include "ReactorSimulation/GraphicEngine.hpp"
#include "ReactorSimulation/PhysicsEngine.hpp"

namespace ReactorSimulation {

ComplexMolecule::ComplexMolecule(MaterialPoint const &center,
                                 Measure_t const     &side_len) :
    Molecule(center), side_len_(side_len) {}
ComplexMolecule::~ComplexMolecule() = default;

void ComplexMolecule::draw(GraphicEngine &gr_eng) const {
    gr_eng.draw(*this);
}

void ComplexMolecule::advance(PhysicsEngine const &ph_eng,
                              Measure_t const     &time_delta) {
    ph_eng.advance(*this, time_delta);
}

bool ComplexMolecule::collide_with_vertical(PhysicsEngine const &ph_eng, Measure_t const &x_coor) const {
    return ph_eng.collide_with_vertical(*this, x_coor);
}
bool ComplexMolecule::collide_with_horizontal(PhysicsEngine const &ph_eng, Measure_t const &y_coor) const {
    return ph_eng.collide_with_horizontal(*this, y_coor);
}

bool ComplexMolecule::collide(Molecule const      &mol,
                              PhysicsEngine const &ph_eng) const {
    return mol.collide(*this, ph_eng);
}
bool ComplexMolecule::collide(SimpleMolecule const &mol,
                              PhysicsEngine const  &ph_eng) const {
    return ph_eng.collide(mol, *this);
}
bool ComplexMolecule::collide(ComplexMolecule const &mol,
                              PhysicsEngine const   &ph_eng) const {
    return ph_eng.collide(mol, *this);
}

} // namespace ReactorSimulation
