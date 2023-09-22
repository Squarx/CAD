//
// Created by g on 21.09.23.
//

#include "ellips.h"

Ellips::Ellips(double x_radi, double y_radi)
    : x_radi_(x_radi), y_radi_(y_radi) {
  if (x_radi < 0 || y_radi_ < 0) {
    throw std::invalid_argument("Radi must not be negative");
  }
}

Ellips::Ellips(const Ellips &other)
    : x_radi_(other.x_radi_), y_radi_(other.y_radi_) {}

Ellips::Ellips(Ellips &&other) noexcept
    : x_radi_(other.x_radi_), y_radi_(other.y_radi_) {
  other.x_radi_ = 0;
  other.y_radi_ = 0;
}

Ellips &Ellips::operator=(const Ellips &other) {
  if (*this != other) {
    x_radi_ = other.x_radi_;
    y_radi_ = other.y_radi_;
  }
  return *this;
}

Ellips &Ellips::operator=(Ellips &&other) noexcept {
  if (*this != other) {
    x_radi_ = other.x_radi_;
    y_radi_ = other.y_radi_;
    other.x_radi_ = 0;
    other.y_radi_ = 0;
  }
  return *this;
}

Coordinates Ellips::GetCoordinates(double t) {
  double x = x_radi_ * cos(t);
  double y = y_radi_ * sin(t);
  double z = 0;
  return {x, y, z};
}

Coordinates Ellips::GetDerivative(double t) {
  double dx_dt = -x_radi_ * sin(t);
  double dy_dt = y_radi_ * cos(t);
  double dz_dt = 0;
  return {dx_dt, dy_dt, dz_dt};
}
bool Ellips::operator==(const Ellips &other) const {
  return x_radi_ == other.x_radi_ && y_radi_ == other.y_radi_;
}
bool Ellips::operator!=(const Ellips &other) const { return !(*this == other); }

void Ellips::Print(std::ostream &os) const {
  os << "(Ellips) X_radi: " << x_radi_ << " Y_radi :" << y_radi_;
}

std::ostream &operator<<(std::ostream &os, const Ellips &c) {
  os << "X radi: " << c.x_radi_ << " Y radi :" << c.y_radi_;
  return os;
}