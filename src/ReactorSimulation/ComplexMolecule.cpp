#include "ReactorSimulation/Types.hpp"
#include <cmath>
#include <iostream>

namespace ReactorSimulation {

ComplexMolecule::ComplexMolecule(MaterialPoint const &center,
                                 Measure_t const &side_len) :
    Molecule(center), side_len_(side_len) {}
ComplexMolecule::~ComplexMolecule() = default;

bool ComplexMolecule::collide_with(Molecule const &mol) const {
    std::cout << "Called from Complex" << std::endl;

    return mol.collide_with(*this);
}

bool ComplexMolecule::collide_with(SimpleMolecule const &mol) const {
    std::cout << "Complex and Simple" << std::endl;
    Measure_t const half_side_len = side_len_ / 2;
    return (Vector2D(std::clamp(mol.center_.position_.x_coor_,
                                center_.position_.x_coor_ - half_side_len,
                                center_.position_.x_coor_ + half_side_len),
                     std::clamp(mol.center_.position_.y_coor_,
                                center_.position_.y_coor_ - half_side_len,
                                center_.position_.y_coor_ + half_side_len)) -
            mol.center_.position_)
               .len2() <= mol.radius_ * mol.radius_;
}

bool ComplexMolecule::collide_with(ComplexMolecule const &mol) const {
    std::cout << "Complex and Complex" << std::endl;
    return std::max(std::abs(center_.position_.x_coor_ -
                             mol.center_.position_.x_coor_),
                    std::abs(center_.position_.y_coor_ -
                             mol.center_.position_.y_coor_)) <=
           (side_len_ + mol.side_len_) / 2;
}

} // namespace ReactorSimulation
