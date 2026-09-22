#include <iostream>
#include "PhysicsSimulator.hpp"

// How to differ between Compilation end and Build end
// How to avoid scope resolution operator in cpp

int main() {
	using namespace PhysicsSimulator;

	SimpleMolecule test_mol(Vector2(1, 2), Vector2(3, 4), 5);

	return 0;
}
