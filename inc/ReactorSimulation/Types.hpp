#ifndef REACTOR_TYPES
#define REACTOR_TYPES

#include <cstddef>
#include <unordered_set>
#include <chrono>

namespace ReactorSimulation {

typedef double Measure_t;
typedef std::size_t Weight_t;
typedef std::chrono::steady_clock Clock_t;

class Vector2D {
public:
    explicit Vector2D();
    explicit Vector2D(Measure_t const &x_coor, Measure_t const &y_coor);

    Vector2D &operator+=(Vector2D const &vec);
    Vector2D &operator-=(Vector2D const &vec);
    Vector2D &operator*=(Measure_t const &mlt);
    Vector2D &operator/=(Measure_t const &div);

    Measure_t len2() const;
    Measure_t len() const;

    Measure_t x_coor_;
    Measure_t y_coor_;
};
Vector2D operator+(Vector2D const &left, Vector2D const &right);
Vector2D operator-(Vector2D const &left, Vector2D const &right);
Vector2D operator*(Vector2D const &vec, Measure_t const &mlt);
Vector2D operator*(Measure_t const &mlt, Vector2D const &vec);
Vector2D operator/(Vector2D const &vec, Measure_t const &div);

class MaterialPoint {
public:
    MaterialPoint() = delete;
    explicit MaterialPoint(Vector2D const &position, Vector2D const &velocity,
                           Weight_t const &weight);
    ~MaterialPoint();

    Vector2D position_;
    Vector2D velocity_;

    Weight_t const weight_;
};

class SimpleMolecule;
class ComplexMolecule;

class Molecule {
public:
    virtual ~Molecule();

    virtual bool collide_with(Molecule const &mol) const = 0;
    virtual bool collide_with(SimpleMolecule const &mol) const = 0;
    virtual bool collide_with(ComplexMolecule const &mol) const = 0;

    MaterialPoint center_;

protected:
    Molecule() = delete;
    explicit Molecule(MaterialPoint const &center);
};

class SimpleMolecule : public Molecule {
public:
    SimpleMolecule() = delete;
    explicit SimpleMolecule(MaterialPoint const &center,
                            Measure_t const &radius);
    ~SimpleMolecule() override;

    bool collide_with(Molecule const &mol) const override;
    bool collide_with(SimpleMolecule const &mol) const override;
    bool collide_with(ComplexMolecule const &mol) const override;

    Measure_t const radius_;
};

class ComplexMolecule : public Molecule {
public:
    ComplexMolecule() = delete;
    explicit ComplexMolecule(MaterialPoint const &center,
                             Measure_t const &side_len);
    ~ComplexMolecule() override;

    bool collide_with(Molecule const &mol) const override;
    bool collide_with(SimpleMolecule const &mol) const override;
    bool collide_with(ComplexMolecule const &mol) const override;

    Measure_t const side_len_;
};

class Reactor {
public:
    explicit Reactor() = delete;
    explicit Reactor(Measure_t const &left_bound, Measure_t const &right_bound,
                     Measure_t const &bottom_bound, Measure_t const &top_bound);
    virtual ~Reactor();

    Reactor &operator=(Reactor const &src) = delete;

    void add_molecule(Molecule *mol);

    std::unordered_set<Molecule *> molecule_arr_;

private:
    Measure_t left_bound_;
    Measure_t right_bound_;
    Measure_t bottom_bound_;
    Measure_t top_bound_;
};

} // namespace ReactorSimulation

#endif
