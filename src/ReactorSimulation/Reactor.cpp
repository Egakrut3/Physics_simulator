#include "ReactorSimulation/Types.hpp"

namespace ReactorSimulation {

Reactor::Reactor(Measure_t const &left_bound, Measure_t const &right_bound,
                 Measure_t const &bottom_bound, Measure_t const &top_bound) :
    molecule_arr_(),
    left_bound_(left_bound),
    right_bound_(right_bound),
    bottom_bound_(bottom_bound),
    top_bound_(top_bound) {}
Reactor::~Reactor() {
    for (std::vector<Molecule *>::iterator elem = molecule_arr_.begin();
         elem != molecule_arr_.end(); ++elem) {
        delete *elem;
    }
}

void Reactor::add_molecule(Molecule *const mol) {
    molecule_arr_.push_back(mol);
}

} // namespace ReactorSimulation
