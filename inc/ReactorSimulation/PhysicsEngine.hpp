#ifndef PHYSICS_ENGINE
#define PHYSICS_ENGINE

#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

class PhysicsEngine {
public:
    void advance(Molecule &mol, Measure_t const &time_delta) const;
    void advance(SimpleMolecule &mol, Measure_t const &time_delta) const;
    void advance(ComplexMolecule &mol, Measure_t const &time_delta) const;

    bool collide_with_vertical(Molecule const  &mol,
                               Measure_t const &x_coor) const;
    bool collide_with_vertical(SimpleMolecule const &mol,
                               Measure_t const      &x_coor) const;
    bool collide_with_vertical(ComplexMolecule const &mol,
                               Measure_t const       &x_coor) const;

    bool collide_with_horizontal(Molecule const  &mol,
                                 Measure_t const &y_coor) const;
    bool collide_with_horizontal(SimpleMolecule const &mol,
                                 Measure_t const      &y_coor) const;
    bool collide_with_horizontal(ComplexMolecule const &mol,
                                 Measure_t const       &y_coor) const;

    bool collide(Molecule const &mol1, Molecule const &mol2) const;
    bool collide(SimpleMolecule const &mol1, SimpleMolecule const &mol2) const;
    bool collide(SimpleMolecule const &mol1, ComplexMolecule const &mol2) const;
    bool collide(ComplexMolecule const &mol1, SimpleMolecule const &mol2) const;
    bool collide(ComplexMolecule const &mol1,
                 ComplexMolecule const &mol2) const;

protected:
    explicit PhysicsEngine();
    virtual ~PhysicsEngine();

    void advance_state(Reactor &reactor, Measure_t const &time_delta) const;
    void perform_reflections(Reactor &reactor) const;

private:
    void perform_border_reflections(Reactor &reactor) const;
    void perform_between_molecule_reflections(Reactor &reactor) const;
};

} // namespace ReactorSimulation

#endif
