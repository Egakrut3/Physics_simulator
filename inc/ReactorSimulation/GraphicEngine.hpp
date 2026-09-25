#ifndef GRAPHIC_ENGINE
#define GRAPHIC_ENGINE

#include "ReactorSimulation/Types.hpp"
#include <SFML/Graphics.hpp>

namespace ReactorSimulation {

class GraphicEngine {
public:
    explicit GraphicEngine(unsigned int width, unsigned int height, std::string const &title);
    ~GraphicEngine();

    void draw(Molecule const &mol);
    void draw(SimpleMolecule const &mol);
    void draw(ComplexMolecule const &mol);

    void draw_molecules(Reactor const &reactor);

    bool is_open() const;
    void process_events();

    void display();
    void clear();

private:
    sf::RenderWindow window_;
};

} // namespace ReactorSimulation

#endif
