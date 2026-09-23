#include <iostream>
#include "ReactorTypes.hpp"

// How to differ between Compilation end and Build end

int main() {
	using namespace Reactor;

	SimpleMolecule test_mol(MaterialPoint(Vector2(1, 2), Vector2(3, 4), 5), 6);

	return 0;
}
