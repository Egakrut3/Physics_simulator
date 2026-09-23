#ifndef REACTOR_TYPES
#define REACTOR_TYPES

#include <cstddef>

namespace Reactor {

typedef double Measure_t;

class Vector2 {
public:
	explicit Vector2();
	explicit Vector2(Measure_t const &x_coor, Measure_t const &y_coor);

	Measure_t x_coor_;
	Measure_t y_coor_;
};

typedef std::size_t Weight_t;

class MaterialPoint {
public:
	MaterialPoint() = delete;
	explicit MaterialPoint(Vector2 const &position, Vector2 const &velocity,
						   Weight_t const &weight);
	~MaterialPoint();

protected:
	Vector2 position_;
	Vector2 velocity_;

	Weight_t const weight_;
};

class Molecule {
public:
	Molecule() = delete;
	explicit Molecule(MaterialPoint const &center);
	virtual ~Molecule();

private:
	MaterialPoint center_;
};

class SimpleMolecule : virtual public Molecule {
public:
	SimpleMolecule() = delete;
	explicit SimpleMolecule(MaterialPoint const &center,
							Measure_t const &radius);
	~SimpleMolecule() override;

private:
	Measure_t const radius_;
};

} // namespace Reactor

#endif
