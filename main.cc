#include <iostream>
#include <list>
#include <random>

#include "Randomazer/randomazer.h"

int main() {
  using std::list, std::cout, std::endl, std::accumulate,
      std::dynamic_pointer_cast, std::shared_ptr;

  Randomazer r;
  double t = M_PI / 4;

  // Creating figures in random manner with random parameters (size = 20
  // default)
  auto figures = r.GenerateRandomList();
  // Print coordinates of points and derivatives of all curves in the container
  // at t=PI/4

  for (size_t i = 0; i < figures.size(); ++i) {
    auto figure = figures[i];
    cout << i + 1 << ": " << *figure << endl;
    cout << "Coordinates at t = " << t << endl;
    cout << (*figure).GetCoordinates(t) << endl;
    cout << "Derivateive at t = " << t << endl;
    cout << (*figure).GetDerivative(t) << endl;
    cout << endl;
  }

  // Second container that would contain only circles from the first container
  // without copy object

  list<shared_ptr<Circle>> circles;
  for (size_t i = 0; i < figures.size(); ++i) {
    auto figure = figures[i];
    if (dynamic_pointer_cast<Circle>(figure)) {
      circles.push_back(dynamic_pointer_cast<Circle>(figure));
    }
  }

  // Sort the second container in the ascending order of circles’ radii
  circles.sort([](const std::shared_ptr<Circle> &circle1,
                  const std::shared_ptr<Circle> &circle2) {
    return *circle1 < *circle2;
  });

  // Print second container after sort
  cout << "Count of circles = " << circles.size() << endl;
  for (auto c : circles) {
    cout << *c << endl;
  }

  // Compute the total sum of radii of all curves in the second container
  double sum =
      accumulate(circles.begin(), circles.end(), 0.0,
                 [](double accumulator, const std::shared_ptr<Circle> &circle) {
                   return accumulator + circle->GetRadi();
                 });
  cout << "Total sum of radii of all curves in the second container" << endl;
  cout << sum << endl;

  return 0;
}
