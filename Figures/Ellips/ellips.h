//
// Created by g on 21.09.23.
//

#ifndef CAD_FIGURES_ELLIPS_ELLIPS_H_
#define CAD_FIGURES_ELLIPS_ELLIPS_H_
#include <cmath>
#include <stdexcept>

#include "../../BaseClass/figure.h"

class Ellips : public Figure {
 public:
  void Print(std::ostream& os) const override;
  friend std::ostream& operator<<(std::ostream& os, const Ellips& c);

  Ellips() : x_radi_(0), y_radi_(0) {}
  Ellips(double x_radi, double y_radi);

  Ellips(const Ellips& other);
  Ellips(Ellips&& other) noexcept;
  Ellips& operator=(const Ellips& other);
  Ellips& operator=(Ellips&& other) noexcept;

  Coordinates GetCoordinates(double t) override;
  Coordinates GetDerivative(double t) override;

  bool operator==(const Ellips& other) const;
  bool operator!=(const Ellips& other) const;

  ~Ellips() = default;

 private:
  void CreateEccentricity();

  double x_radi_;
  double y_radi_;
};

#endif  // CAD_FIGURES_ELLIPS_ELLIPS_H_
