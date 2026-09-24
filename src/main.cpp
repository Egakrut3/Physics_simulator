#include "ReactorSimulation/Types.hpp"
#include <iostream>

// TODO - Switch to value initialization {}
// TODO - not delete Reactor()
// TODO - restirct
// TODO - C++ modules
// TODO - My macros
// TODO - How to differ between Compilation end and Build end

static void test_reactor_simulation() {
    using namespace ReactorSimulation;

    Reactor test_reactor(-10, 10, -10, 10);

    test_reactor.add_molecule(new SimpleMolecule(
        MaterialPoint(Vector2D(1, 2), Vector2D(3, 4), 5), 6));

    SimpleMolecule s_mol1(MaterialPoint(Vector2D(0, 0), Vector2D(0, 0), 10), 5);
    SimpleMolecule s_mol2(MaterialPoint(Vector2D(6, 8), Vector2D(0, 0), 10), 5);
    ComplexMolecule c_mol(MaterialPoint(Vector2D(0, -5), Vector2D(0, 0), 10),
                          5);

    Molecule &r1 = s_mol1;
    Molecule &r2 = s_mol2;
    Molecule &r3 = c_mol;

    std::cout << r1.collide_with(r2) << std::endl << std::endl;
    std::cout << r2.collide_with(r3) << std::endl << std::endl;
    std::cout << r3.collide_with(r1) << std::endl << std::endl;
}

int main() {
    test_reactor_simulation();

    return 0;
}
