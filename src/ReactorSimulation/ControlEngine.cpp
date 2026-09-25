#include "ReactorSimulation/ControlEngine.hpp"

namespace ReactorSimulation {

ControlEngine::ControlEngine(
    Measure_t const &view_left_bound, Measure_t const &view_right_bound,
    Measure_t const &view_bottom_bound, Measure_t const &view_top_bound,
    Measure_t const &border_width, unsigned int window_width,
    unsigned int window_height, std::string const &window_title) :
    Reactor(view_left_bound + border_width, view_right_bound - border_width,
            view_bottom_bound + border_width, view_top_bound - border_width,
            border_width),
    GraphicEngine(window_width, window_height, window_title),
    last_update_time_(Clock_t::now()) {
    set_view(view_left_bound, view_right_bound, view_bottom_bound,
             view_top_bound);
}
ControlEngine::~ControlEngine() = default;

bool ControlEngine::one_more_iteration() {
    if (!is_open()) {
        return false;
    }

    process_events();
    GraphicEngine::clear();
    draw_everything(*this);
    display();

    Clock_t::time_point const current_time = Clock_t::now();
    auto time_delta   = std::chrono::duration_cast<std::chrono::microseconds>(
                            current_time - last_update_time_)
                            .count();
    last_update_time_ = current_time;
    advance_state(*this, static_cast<Measure_t>(time_delta));
    perform_reflections(*this);

    return true;
}

} // namespace ReactorSimulation
