#include "ReactorSimulation/Types.hpp"
#include <cmath>

namespace ReactorSimulation {

Vector2D::Vector2D() : x_coor_(), y_coor_() {}
Vector2D::Vector2D(Measure_t const &x_coor, Measure_t const &y_coor) :
    x_coor_(x_coor), y_coor_(y_coor) {}
Vector2D::~Vector2D() = default;

Vector2D &Vector2D::operator+=(Vector2D const &vec) {
    this->x_coor_ += vec.x_coor_;
    this->y_coor_ += vec.y_coor_;

    return *this;
}
Vector2D &Vector2D::operator-=(Vector2D const &vec) {
    this->x_coor_ -= vec.x_coor_;
    this->y_coor_ -= vec.y_coor_;

    return *this;
}
Vector2D &Vector2D::operator*=(Measure_t const &mlt) {
    this->x_coor_ *= mlt;
    this->y_coor_ *= mlt;

    return *this;
}
Vector2D &Vector2D::operator/=(Measure_t const &div) {
    this->x_coor_ /= div;
    this->y_coor_ /= div;

    return *this;
}

Vector2D operator+(Vector2D const &left, Vector2D const &right) {
    Vector2D res(left);
    return res += right;
}
Vector2D operator-(Vector2D const &left, Vector2D const &right) {
    Vector2D res(left);
    return res -= right;
}
Vector2D operator*(Vector2D const &vec, Measure_t const &mlt) {
    Vector2D res(vec);
    return res *= mlt;
}
Vector2D operator*(Measure_t const &mlt, Vector2D const &vec) {
    Vector2D res(vec);
    return res *= mlt;
}
Vector2D operator/(Vector2D const &vec, Measure_t const &div) {
    Vector2D res(vec);
    return res /= div;
}

Measure_t operator*(Vector2D const &vec1, Vector2D const &vec2) {
    return (vec1.x_coor_ * vec2.x_coor_) + (vec1.y_coor_ * vec2.y_coor_);
}

Measure_t Vector2D::len2() const {
    return (x_coor_ * x_coor_) + (y_coor_ * y_coor_);
}
Measure_t Vector2D::len() const {
    return std::sqrt(len2());
}

} // namespace ReactorSimulation
