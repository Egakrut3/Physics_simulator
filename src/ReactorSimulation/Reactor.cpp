#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

Measure_t Reactor::get_left_bound() const {
    return left_bound_;
}
Measure_t Reactor::get_right_bound() const {
    return right_bound_;
}
Measure_t Reactor::get_bottom_bound() const {
    return bottom_bound_;
}
Measure_t Reactor::get_top_bound() const {
    return top_bound_;
}
Measure_t Reactor::get_border_width() const {
    return border_width_;
}

Reactor::Reactor(Measure_t const &left_bound, Measure_t const &right_bound,
                 Measure_t const &bottom_bound, Measure_t const &top_bound,
                 Measure_t const &border_width) :
    Container_t(),
    left_bound_(left_bound),
    right_bound_(right_bound),
    bottom_bound_(bottom_bound),
    top_bound_(top_bound),
    border_width_(border_width) {}
Reactor::~Reactor() {
    for (Container_t::iterator elem = begin(); elem != end(); ++elem) {
        delete *elem;
    }
}

} // namespace ReactorSimulation
