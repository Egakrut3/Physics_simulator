#include "ReactorSimulation/PhysicsEngine.hpp"
#include <iostream>

namespace ReactorSimulation {

void PhysicsEngine::advance_state(Reactor &reactor, Measure_t const &dt) {
    for (std::unordered_set<Molecule *>::iterator elem = reactor.molecule_arr_.begin();
         elem != reactor.molecule_arr_.end(); ++elem) {
        (*elem)->center_.position_ += (*elem)->center_.velocity_ * dt;
    }
}

static Vector2D calculate_new_velocity(MaterialPoint const &pnt1, MaterialPoint &pnt2) {
    return (pnt1.velocity_ * static_cast<Measure_t>(pnt1.weight_ - pnt2.weight_) +
            pnt2.velocity_ * static_cast<Measure_t>(2 * pnt2.weight_)) /
           static_cast<Measure_t>(pnt1.weight_ + pnt2.weight_);
}

static void perform_simple_reflection(MaterialPoint &pnt1, MaterialPoint &pnt2) {
    Vector2D new_velocity1 = calculate_new_velocity(pnt1, pnt2);
    Vector2D new_velocity2 = calculate_new_velocity(pnt2, pnt1);

    pnt1.velocity_ = new_velocity1;
    pnt2.velocity_ = new_velocity2;

    std::cout << "Reflection !!!" << std::endl;

    return;
}

void PhysicsEngine::perform_reflections(Reactor &reactor) {
    for (std::unordered_set<Molecule *>::iterator elem1 = reactor.molecule_arr_.begin();
         elem1 != reactor.molecule_arr_.end(); ++elem1) {
        for (std::unordered_set<Molecule *>::iterator elem2 = std::next(elem1);
             elem2 != reactor.molecule_arr_.end(); ++elem2) {
            perform_simple_reflection((*elem1)->center_, (*elem2)->center_);
        }
    }
}

} // namespace ReactorSimulation
