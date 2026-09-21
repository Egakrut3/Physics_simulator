#include "Simulator_physics.hpp"

#include <iostream>

Molecule::Molecule() = default;
Molecule::Molecule(Measure_t const weight, Measure_t const x_coor,
				   Measure_t const y_coor, Measure_t const x_speed,
				   Measure_t const y_speed)
	: weight_(weight),
	  x_coor_(x_coor),
	  y_coor_(y_coor),
	  x_speed_(x_speed),
	  y_speed_(y_speed) {}
Molecule::~Molecule() = default;
void Molecule::print() const {
	std::cout << weight_ << '\n'
			  << x_coor_ << ' ' << y_coor_ << '\n'
			  << x_speed_ << ' ' << y_speed_ << '\n';
}

SimpleMolecule::SimpleMolecule() = default;
SimpleMolecule::SimpleMolecule(Measure_t const weight, Measure_t const x_coor,
							   Measure_t const y_coor, Measure_t const x_speed,
							   Measure_t const y_speed)
	: Molecule(weight, x_coor, y_coor, x_speed, y_speed) {}
SimpleMolecule::~SimpleMolecule() {
	Molecule::~Molecule();
}
void SimpleMolecule::print() const {
	std::cout << "Simple" << '\n';
	Molecule::print();
}
