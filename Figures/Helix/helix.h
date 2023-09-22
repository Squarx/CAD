//
// Created by g on 21.09.23.
//

#ifndef CAD_FIGURES_HELIX_HELIX_H_
#define CAD_FIGURES_HELIX_HELIX_H_
#include <cmath>
#include <stdexcept>

#include "../../BaseClass/figure.h"

class Helix : public Figure {
 public:
  void Print(std::ostream &os) const override;
  friend std::ostream &operator<<(std::ostream &os, const Helix &c);

  Helix() : radi_(0), step_(0) {}
  Helix(double radi, double step);

  Helix(const Helix &other);
  Helix(Helix &&other) noexcept;
  Helix &operator=(const Helix &other);
  Helix &operator=(Helix &&other) noexcept;

  Coordinates GetCoordinates(double t) override;
  Coordinates GetDerivative(double t) override;

  bool operator==(const Helix &other) const;
  bool operator!=(const Helix &other) const;

  ~Helix() = default;

 private:
  double radi_;
  double step_;
};

#endif  // CAD_FIGURES_HELIX_HELIX_H_
