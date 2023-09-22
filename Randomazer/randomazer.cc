//
// Created by g on 22.09.23.
//

#include "randomazer.h"

#include <functional>

std::shared_ptr<Figure> Randomazer::GenRandomCircle(
    std::default_random_engine& re) {
  double lower_bound = 0;
  double upper_bound = 10000;
  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);

  double radi = unif(re);
  return std::make_shared<Circle>(radi);
}

std::shared_ptr<Figure> Randomazer::GenRandomEllips(
    std::default_random_engine& re) {
  double lower_bound = 0;
  double upper_bound = 10000;
  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);

  double x_radi = unif(re);
  double y_radi = unif(re);
  return std::make_shared<Ellips>(x_radi, y_radi);
}

std::shared_ptr<Figure> Randomazer::GenRandomHelix(
    std::default_random_engine& re) {
  double lower_bound = 0;
  double lower_bound_z = -10000;
  double upper_bound = 10000;
  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
  std::uniform_real_distribution<double> unif_negative(lower_bound_z,
                                                       upper_bound);

  double radi = unif(re);
  double step = unif_negative(re);
  return std::make_shared<Helix>(radi, step);
}
std::vector<std::shared_ptr<Figure>> Randomazer::GenerateRandomList(int size) {
  std::vector<std::shared_ptr<Figure>> res(size);
  std::random_device rd;
  std::default_random_engine re(rd());

  std::uniform_int_distribution<int> distribution(0, 2);
  int choice = 0;
  for (auto i = 0; i < size; ++i) {
    choice = distribution(re);
    switch (choice) {
      case 0:
        res[i] = GenRandomCircle(re);
        break;
      case 1:
        res[i] = GenRandomEllips(re);
        break;
      case 2:
        res[i] = GenRandomHelix(re);
        break;
      default:
        break;
    }
  }
  return res;
}
