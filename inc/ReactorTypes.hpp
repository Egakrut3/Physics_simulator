#ifndef REACTOR_TYPES
#define REACTOR_TYPES

#include <cstddef>

namespace Reactor {

typedef double Measure_t;

class Vector2 {
public:
	explicit Vector2();
	explicit Vector2(Measure_t x_coor, Measure_t y_coor);

	Measure_t x_coor_;
	Measure_t y_coor_;
};

typedef std::size_t Weight_t;

class MaterialPoint {
public:
	MaterialPoint() = delete;
	explicit MaterialPoint(Vector2 position, Vector2 velocity, Weight_t weight);
	virtual ~MaterialPoint();

protected:
	Vector2 position_;
	Vector2 velocity_;

	Weight_t weight_;
};

class SimpleMolecule : public MaterialPoint {
public:
	SimpleMolecule() = delete;
	explicit SimpleMolecule(Vector2 position, Vector2 velocity,
							Weight_t weight);
	~SimpleMolecule() override;
};

} // namespace Reactor

#endif
