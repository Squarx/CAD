//
// Created by g on 22.09.23.
//

#ifndef CAD_RANDOMAZER_RANDOMAZER_H_
#define CAD_RANDOMAZER_RANDOMAZER_H_
#include <list>
#include <memory>
#include <random>

#include "../Figures/Circle/circle.h"
#include "../Figures/Ellips/ellips.h"
#include "../Figures/Helix/helix.h"

class Randomazer {
 public:
  std::shared_ptr<Figure> GenRandomCircle(std::default_random_engine& re);
  std::shared_ptr<Figure> GenRandomEllips(std::default_random_engine& re);
  std::shared_ptr<Figure> GenRandomHelix(std::default_random_engine& re);

  std::vector<std::shared_ptr<Figure>> GenerateRandomList(int size = 20);
};
#endif  // CAD_RANDOMAZER_RANDOMAZER_H_
