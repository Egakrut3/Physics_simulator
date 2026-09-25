#include "ReactorSimulation/GraphicEngine.hpp"
#include "ReactorSimulation/PhysicsEngine.hpp"
#include <chrono>

// TODO - Add overloaded functions for physic interactions, not hard-code them
// TODO - Switch to value initialization {}
// TODO - not delete Reactor()
// TODO - restirct
// TODO - C++ modules
// TODO - My macros
// TODO - How to differ between Compilation end and Build end

static void test_reactor_simulation() {
    using namespace ReactorSimulation;

    Reactor test_reactor(-127, 127, -79, 79);
    test_reactor.molecule_arr_.insert(new SimpleMolecule(
        MaterialPoint(Vector2D(0, 0), Vector2D(0.5, 0), 10), 5));
    test_reactor.molecule_arr_.insert(new SimpleMolecule(
        MaterialPoint(Vector2D(6, 8), Vector2D(0, 0.5), 10), 5));
    test_reactor.molecule_arr_.insert(new ComplexMolecule(
        MaterialPoint(Vector2D(0, -7.5), Vector2D(0.5, 0.5), 10), 5));

    GraphicEngine gr_eng(1280, 800, "Test reactor");
    gr_eng.set_view(-128, 128, -80, 80);

    PhysicsEngine                     ph_eng{};
    typedef std::chrono::steady_clock Clock_t;
    Clock_t::time_point               last_update_time = Clock_t::now();

    while (gr_eng.is_open()) {
        gr_eng.process_events();
        gr_eng.clear();
        gr_eng.draw_molecules(test_reactor);
        gr_eng.display();

        Clock_t::time_point current_time = Clock_t::now();
        auto time_delta = std::chrono::duration_cast<std::chrono::milliseconds>(
                              current_time - last_update_time)
                              .count();
        last_update_time = current_time;
        ph_eng.advance_state(test_reactor, static_cast<Measure_t>(time_delta));
        ph_eng.perform_reflections(test_reactor);
    }
}

int main() {
    test_reactor_simulation();

    return 0;
}
