#include "Collisions.h"


SpherePoint::SpherePoint(Sphere s, Point p)
  : s(s),
  p(p)
{
}

SpherePoint::~SpherePoint()
{
}

int SphereIntersectionPoint(Ray r, Sphere s, Point& p)
{
  // Set up quadratic equation arguments
  double a = r.Direction.Dot(r.Direction);
  double b = 2 * r.Location.Difference(s.Center).Dot(r.Direction);
  double c = r.Location.Difference(s.Center).Dot() - 
    (s.Radius * s.Radius);

  double discriminantSq = b * b - 4 * a * c;
  if (discriminantSq < 0)
  {
    return 1;
  }

  double t = (-1 * b - std::sqrt(discriminantSq)) / (2 * a);

  // The ray only intersects ahead of itself if t is positive
  if (t < 0)
  {
    t = (-1 * b + std::sqrt(discriminantSq)) / (2 * a);
    if (t < 0)
    {
      // The sphere exists entirely behind the ray
      return 1;
    }
  }

  p.Copy(r.Location + r.Direction * t);
  return 0;
}

std::vector<SpherePoint> FindIntersectionPoints(
  std::vector<Sphere> SphereList,
  Ray r)
{
  std::vector<SpherePoint> ReturnList;

  for (auto s : SphereList)
  {
    Point TempPoint(0,0,0);

    if (!SphereIntersectionPoint(r, s, TempPoint))
    {
      ReturnList.push_back(SpherePoint(s, TempPoint));
    }
  }

  return ReturnList;
}

Vector SphereNormalAtPoint(Sphere s, Point p)
{
  // A normalized vector going in the same direction as the vector
  // from the center of the sphere to the point
  return p.Difference(s.Center).Normalize();
}