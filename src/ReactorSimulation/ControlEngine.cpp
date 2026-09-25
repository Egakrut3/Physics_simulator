#include "ReactorSimulation/ControlEngine.hpp"

namespace ReactorSimulation {

ControlEngine::ControlEngine(Measure_t const   &left_bound,
                             Measure_t const   &right_bound,
                             Measure_t const   &bottom_bound,
                             Measure_t const   &top_bound,
                             unsigned int       window_width,
                             unsigned int       window_height,
                             std::string const &window_title) :
    Reactor(left_bound, right_bound, bottom_bound, top_bound),
    GraphicEngine(window_width, window_height, window_title),
    last_update_time_(Clock_t::now()) {}
ControlEngine::~ControlEngine() = default;

bool ControlEngine::one_more_iteration() {
    if (!is_open()) {
        return false;
    }

    process_events();
    GraphicEngine::clear();
    draw_molecules(*this);
    display();

    Clock_t::time_point const current_time = Clock_t::now();
    auto time_delta   = std::chrono::duration_cast<std::chrono::milliseconds>(
                            current_time - last_update_time_)
                            .count();
    last_update_time_ = current_time;
    advance_state(*this, static_cast<Measure_t>(time_delta));
    perform_reflections(*this);

    return true;
}

} // namespace ReactorSimulation
