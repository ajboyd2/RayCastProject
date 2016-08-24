#include "Utilities.h"
#include <vector>

struct SpherePoint
{
  SpherePoint(Sphere s, Point p);

  ~SpherePoint();

  Sphere s;
  Point p;
};

int SphereIntersectionPoint(Ray r, Sphere s, Point& p); 

std::vector<SpherePoint> FindIntersectionPoints(
  std::vector<Sphere> SphereList, 
  Ray r);

Vector SphereNormalAtPoint(Sphere s, Point p);