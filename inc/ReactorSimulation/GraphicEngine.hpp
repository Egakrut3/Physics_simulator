#ifndef GRAPHIC_ENGINE
#define GRAPHIC_ENGINE

#include "ReactorSimulation/Types.hpp"

#include <SFML/Graphics.hpp>

namespace ReactorSimulation {

class GraphicEngine {
public:
    void draw(Molecule const &mol);
    void draw(SimpleMolecule const &mol);
    void draw(ComplexMolecule const &mol);

protected:
    explicit GraphicEngine(unsigned int       window_width,
                           unsigned int       window_height,
                           std::string const &window_title);
    virtual ~GraphicEngine();

    bool is_open() const;
    void process_events();

    void set_view(Measure_t const &left_bound, Measure_t const &right_bound,
                  Measure_t const &bottom_bound, Measure_t const &top_bound);

    void draw_everything(Reactor const &reactor);
    void display();
    void clear();

private:
    void draw_molecules(Reactor const &reactor);
    void draw_borders(Reactor const &reactor);

    sf::RenderWindow window_;
};

} // namespace ReactorSimulation

#endif
