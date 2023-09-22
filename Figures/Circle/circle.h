//
// Created by g on 21.09.23.
//

#ifndef CAD_FIGURES_CIRCLE_CIRCLE_H_
#define CAD_FIGURES_CIRCLE_CIRCLE_H_
#include <cmath>
#include <ostream>
#include <stdexcept>

#include "../../BaseClass/figure.h"
class Circle : public Figure {
 public:
  void Print(std::ostream& os) const override;
  friend std::ostream& operator<<(std::ostream& os, const Circle& c);

  Circle() : radi_(0) {}
  Circle(double radi);
  Circle(const Circle& other);
  Circle(Circle&& other) noexcept;
  Circle& operator=(const Circle& other);
  Circle& operator=(Circle&& other) noexcept;

  [[nodiscard]] double GetRadi() const { return radi_; }

  bool operator<(const Circle& other) const;
  bool operator>(const Circle& other) const;
  bool operator==(const Circle& other) const;
  bool operator!=(const Circle& other) const;
  bool operator<=(const Circle& other) const;
  bool operator>=(const Circle& other) const;

  Coordinates GetCoordinates(double t) override;
  Coordinates GetDerivative(double t) override;

  ~Circle() = default;

 private:
  double radi_;
};

#endif  // CAD_FIGURES_CIRCLE_CIRCLE_H_
