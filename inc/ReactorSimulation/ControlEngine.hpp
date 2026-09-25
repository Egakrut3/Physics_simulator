#ifndef CONTROL_ENGINE
#define CONTROL_ENGINE

#include "ReactorSimulation/GraphicEngine.hpp"
#include "ReactorSimulation/PhysicsEngine.hpp"

#include <chrono>

namespace ReactorSimulation {

class ControlEngine : public Reactor,
                      public GraphicEngine,
                      public PhysicsEngine {
public:
    ControlEngine() = delete;
    explicit ControlEngine(
        Measure_t const &view_left_bound, Measure_t const &view_right_bound,
        Measure_t const &view_bottom_bound, Measure_t const &view_top_bound,
        Measure_t const &border_width, unsigned int window_width,
        unsigned int window_height, std::string const &window_title);
    ~ControlEngine() override;

    bool one_more_iteration();

private:
    typedef std::chrono::steady_clock Clock_t;

    Clock_t::time_point last_update_time_;
};

} // namespace ReactorSimulation

#endif
