//
// Created by g on 21.09.23.
//

#include "circle.h"

Circle::Circle(const Circle &other) : radi_(other.radi_) {}

Circle::Circle(double radi) : radi_(radi) {
  if (radi < 0) {
    throw std::invalid_argument("Radi must not be negative");
  }
}

Circle::Circle(Circle &&other) noexcept : radi_(other.radi_) {
  other.radi_ = 0;
}

Circle &Circle::operator=(const Circle &other) {
  if (*this != other) {
    radi_ = other.radi_;
  }
  return *this;
}

Circle &Circle::operator=(Circle &&other) noexcept {
  if (*this != other) {
    radi_ = other.radi_;
    other.radi_ = 0;
  }
  return *this;
}

Coordinates Circle::GetCoordinates(double t) {
  double point_x = radi_ * cos(t);
  double point_y = radi_ * sin(t);
  double point_z = 0;
  return {point_x, point_y, point_z};
}

Coordinates Circle::GetDerivative(double t) {
  double dx_dt = -1.0 * radi_ * sin(t);
  double dy_dt = radi_ * cos(t);
  double dz_dt = 0;
  return {dx_dt, dy_dt, dz_dt};
}

bool Circle::operator<(const Circle &other) const {
  return radi_ < other.radi_;
}

bool Circle::operator>(const Circle &other) const {
  return radi_ > other.radi_;
}

bool Circle::operator==(const Circle &other) const {
  return radi_ == other.radi_;
}

bool Circle::operator!=(const Circle &other) const {
  return radi_ != other.radi_;
}

bool Circle::operator<=(const Circle &other) const {
  return radi_ <= other.radi_;
}

bool Circle::operator>=(const Circle &other) const {
  return radi_ >= other.radi_;
}

void Circle::Print(std::ostream &os) const { os << "(Circle) Radi: " << radi_; }

std::ostream &operator<<(std::ostream &os, const Circle &c) {
  os << "Radi: " << c.radi_;
  return os;
}