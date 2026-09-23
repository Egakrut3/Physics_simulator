#include "ReactorSimulation/Types.hpp"

#include <cassert>

namespace ReactorSimulation {

constexpr std::size_t DEFAULT_MOLECULE_ARR_SIZE = 10;

Reactor::Reactor(Measure_t const &left_bound, Measure_t const &right_bound,
				 Measure_t const &bottom_bound, Measure_t const &top_bound) :
	left_bound_(left_bound),
	right_bound_(right_bound),
	bottom_bound_(bottom_bound),
	top_bound_(top_bound),
	molecule_arr_start_(new Molecule *[DEFAULT_MOLECULE_ARR_SIZE]),
	molecule_arr_finish_(molecule_arr_start_),
	molecule_arr_end_of_storage_(molecule_arr_start_ +
								 DEFAULT_MOLECULE_ARR_SIZE) {}
Reactor::~Reactor() {
	for (Molecule **mol = molecule_arr_start_; mol != molecule_arr_finish_;
		 ++mol) {
		delete *mol;
	}

	delete[] molecule_arr_start_;
}

void Reactor::add_molecule(SimpleMolecule *const mol) {
	assert(molecule_arr_finish_ != molecule_arr_end_of_storage_);

	*molecule_arr_finish_++ = mol;
}

} // namespace ReactorSimulation
