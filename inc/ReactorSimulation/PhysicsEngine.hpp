#ifndef PHYSICS_ENGINE
#define PHYSICS_ENGINE

#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

class PhysicsEngine {
public:
    explicit PhysicsEngine() = default;

    void advance(Molecule &mol, Measure_t const &dt) const;
    void advance(SimpleMolecule &mol, Measure_t const &dt) const;
    void advance(ComplexMolecule &mol, Measure_t const &dt) const;

    bool collide(Molecule const &mol1, Molecule const &mol2) const;
    bool collide(SimpleMolecule const &mol1, SimpleMolecule const &mol2) const;
    bool collide(SimpleMolecule const &mol1, ComplexMolecule const &mol2) const;
    bool collide(ComplexMolecule const &mol1, SimpleMolecule const &mol2) const;
    bool collide(ComplexMolecule const &mol1, ComplexMolecule const &mol2) const;

    void advance_state(Reactor &reactor, Measure_t const &dt) const;
    void perform_reflections(Reactor &reactor) const;
};

} // namespace ReactorSimulation

#endif
