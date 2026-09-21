#include <iostream>
#include "Simulator_physics.hpp"

// How to differ between Compilation end and Build end
// How to avoid scope resolution operator in cpp

int main() {
	SimpleMolecule test_mol(1, 2, 3, 4, 5);
	static_cast<Molecule &>(test_mol).print();

	return 0;
}
