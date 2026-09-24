#include "ReactorSimulation/Types.hpp"

// TODO - Switch to value initialization {}
// TODO - not delete Reactor()
// TODO - restirct
// TODO - C++ modules
// TODO - My macros
// TODO - How to differ between Compilation end and Build end

static void test_reactor_simulation() {
    using namespace ReactorSimulation;

    Reactor test_reactor(-10, 10, -10, 10);

    test_reactor.add_molecule(
        new SimpleMolecule(MaterialPoint(Vector2(1, 2), Vector2(3, 4), 5), 6));
}

int main() {
    test_reactor_simulation();

    return 0;
}
