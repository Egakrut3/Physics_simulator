#include "ReactorSimulation/PhysicsEngine.hpp"
#include <cmath>

namespace ReactorSimulation {

PhysicsEngine::PhysicsEngine()  = default;
PhysicsEngine::~PhysicsEngine() = default;



void PhysicsEngine::advance(Molecule &mol, Measure_t const &time_delta) const {
    mol.advance(*this, time_delta);
}
void PhysicsEngine::advance(SimpleMolecule  &mol,
                            Measure_t const &time_delta) const {
    mol.center_.position_ += mol.center_.velocity_ * time_delta;
}
void PhysicsEngine::advance(ComplexMolecule &mol,
                            Measure_t const &time_delta) const {
    mol.center_.position_ += mol.center_.velocity_ * time_delta;
}



bool PhysicsEngine::collide_with_vertical(Molecule const &mol, Measure_t const &x_coor) const {
    return mol.collide_with_vertical(*this, x_coor);
}
bool PhysicsEngine::collide_with_vertical(SimpleMolecule const &mol,
                            Measure_t const &x_coor) const {
    return std::abs(x_coor - mol.center_.position_.x_coor_) <= mol.radius_;
}
bool PhysicsEngine::collide_with_vertical(ComplexMolecule const &mol,
                            Measure_t const &x_coor) const {
    return std::abs(x_coor - mol.center_.position_.x_coor_) <= mol.side_len_ / 2;
}



bool PhysicsEngine::collide_with_horizontal(Molecule const &mol, Measure_t const &y_coor) const {
    return mol.collide_with_horizontal(*this, y_coor);
}
bool PhysicsEngine::collide_with_horizontal(SimpleMolecule const &mol,
                            Measure_t const &y_coor) const {
    return std::abs(y_coor - mol.center_.position_.y_coor_) <= mol.radius_;
}
bool PhysicsEngine::collide_with_horizontal(ComplexMolecule const &mol,
                            Measure_t const &y_coor) const {
    return std::abs(y_coor - mol.center_.position_.y_coor_) <= mol.side_len_ / 2;
}



bool PhysicsEngine::collide(Molecule const &mol1, Molecule const &mol2) const {
    return mol1.collide(mol2, *this);
}
bool PhysicsEngine::collide(SimpleMolecule const &mol1,
                            SimpleMolecule const &mol2) const {
    return (mol1.center_.position_ - mol2.center_.position_).len2() <=
           (mol1.radius_ + mol2.radius_) * (mol1.radius_ + mol2.radius_);
}
bool PhysicsEngine::collide(SimpleMolecule const  &mol1,
                            ComplexMolecule const &mol2) const {
    Measure_t const half_side_len = mol2.side_len_ / 2;
    return (Vector2D(
                std::clamp(mol1.center_.position_.x_coor_,
                           mol2.center_.position_.x_coor_ - half_side_len,
                           mol2.center_.position_.x_coor_ + half_side_len),
                std::clamp(mol1.center_.position_.y_coor_,
                           mol2.center_.position_.y_coor_ - half_side_len,
                           mol2.center_.position_.y_coor_ + half_side_len)) -
            mol1.center_.position_)
               .len2() <= mol1.radius_ * mol1.radius_;
}
bool PhysicsEngine::collide(ComplexMolecule const &mol1,
                            SimpleMolecule const  &mol2) const {
    return collide(mol2, mol1);
}
bool PhysicsEngine::collide(ComplexMolecule const &mol1,
                            ComplexMolecule const &mol2) const {
    return std::max(std::abs(mol1.center_.position_.x_coor_ -
                             mol2.center_.position_.x_coor_),
                    std::abs(mol1.center_.position_.y_coor_ -
                             mol2.center_.position_.y_coor_)) <=
           (mol1.side_len_ + mol2.side_len_) / 2;
}



void PhysicsEngine::advance_state(Reactor         &reactor,
                                  Measure_t const &time_delta) const {
    for (std::unordered_set<Molecule *>::iterator elem =
             reactor.molecule_arr_.begin();
         elem != reactor.molecule_arr_.end(); ++elem) {
        advance(**elem, time_delta);
    }
}



static Vector2D calculate_new_velocity(MaterialPoint const &pnt1,
                                       MaterialPoint       &pnt2) {
    return (pnt1.velocity_ *
                static_cast<Measure_t>(pnt1.weight_ - pnt2.weight_) +
            pnt2.velocity_ * static_cast<Measure_t>(2 * pnt2.weight_)) /
           static_cast<Measure_t>(pnt1.weight_ + pnt2.weight_);
}

static void perform_simple_reflection(MaterialPoint &pnt1,
                                      MaterialPoint &pnt2) {
    Vector2D new_velocity1 = calculate_new_velocity(pnt1, pnt2);
    Vector2D new_velocity2 = calculate_new_velocity(pnt2, pnt1);

    pnt1.velocity_ = new_velocity1;
    pnt2.velocity_ = new_velocity2;
}

static void perform_horizontal_reflection(MaterialPoint &pnt, Measure_t const &x_coor) {
    if ((pnt.position_.x_coor_ < x_coor) == (pnt.velocity_.x_coor_ > 0)) {
        pnt.velocity_.x_coor_ = -pnt.velocity_.x_coor_;
    }
}
static void perform_vertical_reflection(MaterialPoint &pnt, Measure_t const &y_coor) {
    if ((pnt.position_.y_coor_ < y_coor) == (pnt.velocity_.y_coor_ > 0)) {
        pnt.velocity_.y_coor_ = -pnt.velocity_.y_coor_;
    }
}

void PhysicsEngine::perform_reflections(Reactor &reactor) const {
    for (std::unordered_set<Molecule *>::iterator elem =
             reactor.molecule_arr_.begin();
         elem != reactor.molecule_arr_.end(); ++elem) {
        if (collide_with_vertical(**elem, reactor.left_bound_)) {
            perform_horizontal_reflection((*elem)->center_, reactor.left_bound_);
        }
        if (collide_with_vertical(**elem, reactor.right_bound_)) {
            perform_horizontal_reflection((*elem)->center_, reactor.right_bound_);
        }

        if (collide_with_horizontal(**elem, reactor.bottom_bound_)) {
            perform_vertical_reflection((*elem)->center_, reactor.bottom_bound_);
        }
        if (collide_with_horizontal(**elem, reactor.top_bound_)) {
            perform_vertical_reflection((*elem)->center_, reactor.top_bound_);
        }
    }

    for (std::unordered_set<Molecule *>::iterator elem1 =
             reactor.molecule_arr_.begin();
         elem1 != reactor.molecule_arr_.end(); ++elem1) {
        for (std::unordered_set<Molecule *>::iterator elem2 = std::next(elem1);
             elem2 != reactor.molecule_arr_.end(); ++elem2) {
            if (collide(**elem1, **elem2)) {
                perform_simple_reflection((*elem1)->center_, (*elem2)->center_);
            }
        }
    }
}

} // namespace ReactorSimulation
