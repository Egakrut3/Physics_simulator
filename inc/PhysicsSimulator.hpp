#ifndef PHYSYCS_SIMULATOR
#define PHYSYCS_SIMULATOR

#include <cstddef>

namespace PhysicsSimulator {

typedef double Measure_t;

class Vector2 {
public:
	explicit Vector2();
	explicit Vector2(Measure_t x_coor, Measure_t y_coor);

	Measure_t x_coor_;
	Measure_t y_coor_;
};

typedef std::size_t Weight_t;

class Molecule {
public:
	Molecule() = delete;
	explicit Molecule(Vector2 position, Vector2 velocity, Weight_t weight);
	virtual ~Molecule();

protected:
	Vector2 position_;
	Vector2 velocity_;

	Weight_t weight_;
};

class SimpleMolecule : virtual public Molecule {
public:
	SimpleMolecule() = delete;
	explicit SimpleMolecule(Vector2 position, Vector2 velocity, Weight_t weight);
	~SimpleMolecule() override;
};

} // PhysicsSimulator

#endif
