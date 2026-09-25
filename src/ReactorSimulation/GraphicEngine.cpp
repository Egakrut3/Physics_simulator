#include "ReactorSimulation/GraphicEngine.hpp"

namespace ReactorSimulation {

GraphicEngine::GraphicEngine(unsigned int width, unsigned int height,
                             std::string const &title) :
    window_(sf::VideoMode(sf::Vector2u(width, height)), sf::String(title),
            sf::State::Windowed) {}
GraphicEngine::~GraphicEngine() = default;

void GraphicEngine::draw(Molecule const &mol) {
    mol.draw(*this);
}
void GraphicEngine::draw(SimpleMolecule const &mol) {
    float           float_radius = static_cast<float>(mol.radius_);
    sf::CircleShape circle(float_radius);
    circle.setOrigin(sf::Vector2f(float_radius, float_radius));
    circle.setPosition(
        sf::Vector2f(static_cast<float>(mol.center_.position_.x_coor_),
                     static_cast<float>(mol.center_.position_.y_coor_)));
    circle.setFillColor(sf::Color::Green);
    window_.draw(circle);
}
void GraphicEngine::draw(ComplexMolecule const &mol) {
    float              float_side_len = static_cast<float>(mol.side_len_);
    sf::Vector2f       square_size(float_side_len, float_side_len);
    sf::RectangleShape square(square_size);
    square.setOrigin(square_size / 2.F);
    square.setPosition(
        sf::Vector2f(static_cast<float>(mol.center_.position_.x_coor_),
                     static_cast<float>(mol.center_.position_.y_coor_)));
    square.setFillColor(sf::Color::Red);
    window_.draw(square);
}

void GraphicEngine::draw_molecules(Reactor const &reactor) {
    for (std::unordered_set<Molecule *>::const_iterator elem =
             reactor.molecule_arr_.begin();
         elem != reactor.molecule_arr_.end(); ++elem) {
        draw(**elem);
    }
}

bool GraphicEngine::is_open() const {
    return window_.isOpen();
}
void GraphicEngine::process_events() {
    while (std::optional<sf::Event> const event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }
}

void GraphicEngine::set_view(Measure_t const &left_bound,
                             Measure_t const &right_bound,
                             Measure_t const &bottom_bound,
                             Measure_t const &top_bound) {
    window_.setView(sf::View(sf::FloatRect(
        sf::Vector2f(static_cast<float>(left_bound),
                     static_cast<float>(bottom_bound)),
        sf::Vector2f(static_cast<float>(right_bound - left_bound),
                     static_cast<float>(top_bound - bottom_bound)))));
}

void GraphicEngine::display() {
    window_.display();
}
void GraphicEngine::clear() {
    window_.clear();
}

} // namespace ReactorSimulation
