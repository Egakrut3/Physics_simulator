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

    constexpr Measure_t VIEW_LEFT_BOUND   = -128;
    constexpr Measure_t VIEW_RIGHT_BOUND  = 128;
    constexpr Measure_t VIEW_BOTTOM_BOUND = -80;
    constexpr Measure_t VIEW_TOP_BOUND    = 80;
    constexpr Measure_t BORDER_WIDTH      = 1;

    constexpr unsigned int WINDOW_WIDTH  = 1280;
    constexpr unsigned int WINDOW_HEIGHT = 800;

    ControlEngine reactor_controller(
        VIEW_LEFT_BOUND, VIEW_RIGHT_BOUND, VIEW_BOTTOM_BOUND, VIEW_TOP_BOUND,
        BORDER_WIDTH, WINDOW_WIDTH, WINDOW_HEIGHT, "My reactor");

    reactor_controller.insert(new SimpleMolecule(
        MaterialPoint(Vector2D(0, 0), Vector2D(1e-4, 0), 10), 5));
    reactor_controller.insert(new SimpleMolecule(
        MaterialPoint(Vector2D(6, 8), Vector2D(0, 1e-4), 10), 5));
    reactor_controller.insert(new ComplexMolecule(
        MaterialPoint(Vector2D(0, -7.5), Vector2D(1e-4, 1e-4), 10), 5));

    while (reactor_controller.one_more_iteration()) {}
}

int main() {
    test_reactor_simulation();

    return 0;
}
