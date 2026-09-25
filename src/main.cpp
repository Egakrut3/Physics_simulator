#include "ReactorSimulation/GraphicEngine.hpp"
#include "ReactorSimulation/PhysicsEngine.hpp"

// TODO - Add overloaded functions for physic interactions, not hard-code them
// TODO - Switch to value initialization {}
// TODO - not delete Reactor()
// TODO - restirct
// TODO - C++ modules
// TODO - My macros
// TODO - How to differ between Compilation end and Build end

static void test_reactor_simulation() {
    using namespace ReactorSimulation;

    SimpleMolecule s_mol1(MaterialPoint(Vector2D(0, 0), Vector2D(0, 0), 10), 5);
    SimpleMolecule s_mol2(MaterialPoint(Vector2D(6, 8), Vector2D(0, 0), 10), 5);
    ComplexMolecule c_mol(MaterialPoint(Vector2D(0, -7.5), Vector2D(0, 0), 10),
                          5);

    Reactor test_reactor(-10, 10, -10, 10);
    test_reactor.molecule_arr_.insert(new SimpleMolecule(MaterialPoint(Vector2D(0, 0), Vector2D(0, 0), 10), 5));
    test_reactor.molecule_arr_.insert(new SimpleMolecule(MaterialPoint(Vector2D(6, 8), Vector2D(0, 0), 10), 5));
    test_reactor.molecule_arr_.insert(new ComplexMolecule(MaterialPoint(Vector2D(0, -7.5), Vector2D(0, 0), 10), 5));

    GraphicEngine gr_eng(1000, 800, "Test reactor");
    while (gr_eng.is_open()) {
        gr_eng.process_events();
        gr_eng.clear();
        gr_eng.draw_molecules(test_reactor);
        gr_eng.display();
    }
}

int main() {
    test_reactor_simulation();

    return 0;
}
