//
// Created by g on 21.09.23.
//

#ifndef CAD_BASECLASS_FIGURE_H_
#define CAD_BASECLASS_FIGURE_H_
#include <ostream>

#include "coordinates.h"

class Figure {
 public:
  virtual void Print(std::ostream &os) const = 0;
  virtual Coordinates GetCoordinates(double t) = 0;
  virtual Coordinates GetDerivative(double t) = 0;
  friend std::ostream &operator<<(std::ostream &os, const Figure &figure) {
    figure.Print(os);
    return os;
  }
};

#endif  // CAD_BASECLASS_FIGURE_H_
