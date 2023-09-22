//
// Created by g on 21.09.23.
//

#ifndef CAD_BASECLASS_COORDINATES_H_
#define CAD_BASECLASS_COORDINATES_H_
#include <ostream>
class Coordinates {
  friend std::ostream& operator<<(std::ostream& os, const Coordinates& c) {
    os << "x: " << c.x_ << " y: " << c.y_ << " z: " << c.z_;
    return os;
  }

 public:
  Coordinates(double x, double y, double z) : x_(x), y_(y), z_(z) {}

  double x_;
  double y_;
  double z_;
};

#endif  // CAD_BASECLASS_COORDINATES_H_
