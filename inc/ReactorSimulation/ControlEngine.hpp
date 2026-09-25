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
    explicit ControlEngine(Measure_t const   &left_bound,
                           Measure_t const   &right_bound,
                           Measure_t const   &bottom_bound,
                           Measure_t const   &top_bound,
                           unsigned int       window_width,
                           unsigned int       window_height,
                           std::string const &window_title);
    ~ControlEngine() override;

    bool one_more_iteration();

private:
    typedef std::chrono::steady_clock Clock_t;

    Clock_t::time_point last_update_time_;
};

} // namespace ReactorSimulation

#endif
