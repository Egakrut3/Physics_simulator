#ifndef REACTOR_TYPES
#define REACTOR_TYPES

#include <cstddef>

namespace ReactorSimulation {

typedef double Measure_t;
typedef std::size_t Weight_t;

class Vector2 {
public:
	explicit Vector2();
	explicit Vector2(Measure_t const &x_coor, Measure_t const &y_coor);

	Measure_t x_coor_;
	Measure_t y_coor_;
};

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
	explicit Molecule(Molecule const &mol);
	virtual ~Molecule();

protected:
	MaterialPoint center_;
};

class SimpleMolecule : virtual public Molecule {
public:
	SimpleMolecule() = delete;
	explicit SimpleMolecule(MaterialPoint const &center,
							Measure_t const &radius);
	explicit SimpleMolecule(SimpleMolecule const &src);
	~SimpleMolecule() override;

private:
	Measure_t const radius_;
};

class Reactor {
public:
	explicit Reactor() = delete;
	explicit Reactor(Measure_t const &left_bound, Measure_t const &right_bound,
					 Measure_t const &bottom_bound, Measure_t const &top_bound);
	Reactor(Reactor const &src) = delete;
	virtual ~Reactor();

	Reactor &operator=(Reactor const &src) = delete;

	void add_molecule(SimpleMolecule *mol);

private:
	Measure_t left_bound_;
	Measure_t right_bound_;
	Measure_t bottom_bound_;
	Measure_t top_bound_;

	Molecule **molecule_arr_start_;
	Molecule **molecule_arr_finish_;
	Molecule **molecule_arr_end_of_storage_;
};

} // namespace ReactorSimulation

#endif
