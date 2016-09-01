#include "Utilities.h"
#include <vector>

int SphereIntersectionPoint(Ray r, Sphere s, Point& p); 

std::vector<SpherePoint> FindIntersectionPoints(
  std::vector<Sphere> SphereList, 
  Ray r);

Vector SphereNormalAtPoint(Sphere s, Point p);