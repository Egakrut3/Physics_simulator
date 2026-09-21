#ifndef SIMULATOR_PHYSYCS
#define SIMULATOR_PHYSYCS

typedef double Measure_t;

class Molecule {
   public:
	explicit Molecule();
	explicit Molecule(Measure_t weight, Measure_t x_coor, Measure_t y_coor,
					  Measure_t x_speed, Measure_t y_speed);
	virtual ~Molecule();

	virtual void print() const;

   private:
	Measure_t weight_;
	Measure_t x_coor_, y_coor_;
	Measure_t x_speed_, y_speed_;
};

class SimpleMolecule : virtual public Molecule {
   public:
	explicit SimpleMolecule();
	explicit SimpleMolecule(Measure_t weight, Measure_t x_coor,
							Measure_t y_coor, Measure_t x_speed,
							Measure_t y_speed);
	~SimpleMolecule() override;

	void print() const override;
};

#endif
