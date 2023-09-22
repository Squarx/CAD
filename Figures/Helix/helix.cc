//
// Created by g on 21.09.23.
//

#include "helix.h"
Helix::Helix(double radi, double step) : radi_(radi), step_(step) {
  if (radi < 0) {
    throw std::invalid_argument("Radi must not be negative");
  }
}
Coordinates Helix::GetCoordinates(double t) {
  double point_x = radi_ * cos(t);
  double point_y = radi_ * sin(t);
  double point_z = t / (2.0 * M_PI) * step_;
  return {point_x, point_y, point_z};
}
Coordinates Helix::GetDerivative(double t) {
  double dx_dt = -1.0 * radi_ * sin(t);
  double dy_dt = radi_ * cos(t);
  double dz_dt = step_;
  return {dx_dt, dy_dt, dz_dt};
}

bool Helix::operator==(const Helix &other) const {
  return radi_ == other.radi_ && step_ == other.step_;
}

bool Helix::operator!=(const Helix &other) const { return !(*this == other); }

void Helix::Print(std::ostream &os) const {
  os << "(Helix) Radi: " << radi_ << " Step :" << step_;
}

std::ostream &operator<<(std::ostream &os, const Helix &c) {
  os << "Radi: " << c.radi_ << " Step :" << c.step_;
  return os;
}
Helix::Helix(const Helix &other) : radi_(other.radi_), step_(other.step_) {}
Helix::Helix(Helix &&other) noexcept : radi_(other.radi_), step_(other.step_) {
  other.radi_ = 0;
  other.step_ = 0;
}
Helix &Helix::operator=(const Helix &other) {
  if (*this != other) {
    radi_ = other.radi_;
    step_ = other.step_;
  }
  return *this;
}
Helix &Helix::operator=(Helix &&other) noexcept {
  if (*this != other) {
    radi_ = other.radi_;
    step_ = other.step_;
    other.radi_ = 0;
    other.step_ = 0;
  }
  return *this;
}
