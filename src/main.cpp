#include "ReactorSimulation/ControlEngine.hpp"
#include "ReactorSimulation/Types.hpp"

// TODO - Make Reactor's getters return reference
// TODO - Switch to value initialization {}
// TODO - restirct
// TODO - My macros
// TODO - C++ modules
// TODO - How to differ between Compilation end and Build end

static void test_reactor_simulation() {
    using namespace ReactorSimulation;
    ControlEngine reactor_controller(-127, 127, -79, 79, 1280, 800,
                                     "My reactor");

    reactor_controller.insert(new SimpleMolecule(
        MaterialPoint(Vector2D(0, 0), Vector2D(1e-4, 0), 10), 5));
    reactor_controller.insert(new SimpleMolecule(
        MaterialPoint(Vector2D(6, 8), Vector2D(0, 1e-4), 10), 5));
    reactor_controller.insert(new ComplexMolecule(
        MaterialPoint(Vector2D(0, -7.5), Vector2D(1e-4, 1e-4), 10), 5));

    reactor_controller.set_view(-128, 128, -80, 80);

    while (reactor_controller.one_more_iteration()) {}
}

int main() {
    test_reactor_simulation();

    return 0;
}
