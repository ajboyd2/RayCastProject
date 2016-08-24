#include "Utilities.h"

//-------------------------------------------------------------------
// Point ------------------------------------------------------------
//-------------------------------------------------------------------
Point::Point(double x, double y, double z)
  : x(x),
  y(y),
  z(z)
{
}

Point::~Point()
{
}

bool Point::operator==(Point other)
{
  return x == other.x && y == other.y && z == other.z;
}

Point Point::operator+(Point other)
{
  return Point(x + other.x, y + other.y, z + other.z);
}

void Point::operator+=(Point other)
{
  x += other.x;
  y += other.y;
  z += other.z;
}

Point Point::operator-(Point other)
{
  return Point(x - other.x, y - other.y, z - other.z);
}

void Point::operator-=(Point other)
{
  x -= other.x;
  y -= other.y;
  z -= other.z;
}

//-------------------------------------------------------------------
// Vector -----------------------------------------------------------
//-------------------------------------------------------------------
Vector::Vector(double x, double y, double z)
  : x(x),
  y(y),
  z(z)
{
}

Vector::~Vector()
{
}

bool Vector::operator==(Vector other)
{
  return x == other.x && y == other.y && z == other.z;
}

Vector Vector::operator+(Vector other)
{
  return Vector(x + other.x, y + other.y, z + other.z);
}

void Vector::operator+=(Vector other)
{
  x += other.x;
  y += other.y;
  z += other.z;
}

Vector Vector::operator-(Vector other)
{
  return Vector(x - other.x, y - other.y, z - other.z);
}

void Vector::operator-=(Vector other)
{
  x -= other.x;
  y -= other.y;
  z -= other.z;
}

//-------------------------------------------------------------------
// Ray --------------------------------------------------------------
//-------------------------------------------------------------------
Ray::Ray(Point loc, Vector dir)
  : Location(loc),
  Direction(dir)
{
}

Ray::~Ray()
{
}

void Ray::Move(Point shift)
{
  Location += shift;
}

void Ray::Move(double x = 0, double y = 0, double z = 0)
{
  Location += Point(x, y, z);
}

bool Ray::operator==(Ray other)
{
  return Location == other.Location && Direction == other.Direction;
}

//-------------------------------------------------------------------
// Sphere -----------------------------------------------------------
//-------------------------------------------------------------------
Sphere::Sphere(Point cen, double radius)
  : Center(cen),
  Radius(radius)
{
}

Sphere::~Sphere()
{
}

void Sphere::Move(Point shift)
{
  Center += shift;
}

void Sphere::Move(double x = 0, double y = 0, double z = 0)
{
  Center += Point(x, y, z);
}

bool Sphere::operator==(Sphere other)
{
  return Center == other.Center && Radius == other.Radius;
}