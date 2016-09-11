#pragma once

#include <opencv2/core.hpp>

struct Point;
struct Vector;
struct Ray;
struct Sphere;

struct Point
{
  Point(double x, double y, double z);
  
  Point(Vector Vec);

  ~Point();

  bool operator==(Point Other);
  
  Point operator+(Point Other);
  
  void operator+=(Point Other);

  Point operator-(Point Other);

  void operator-=(Point Other);

  void Copy(Point Other);

  Point Translate(Vector Shift);

  Vector Difference(Point Other);

  Vector FromThisToThat(Point That);

  double x, y, z;
};

struct Vector
{
  Vector(double x, double y, double z);

  Vector(Point Pt);

  ~Vector();

  bool operator==(Vector Other);

  Vector operator+(Vector Other);

  void operator+=(Vector Other);

  Vector operator-(Vector Other);

  void operator-=(Vector Other);

  Vector operator*(double Scalar);

  void operator*=(double Scalar);

  Vector Scale(double Scalar);

  double Dot(Vector Other);

  double Dot();

  Vector Cross(Vector Other);

  double Length();

  Vector Normalize();

  double x, y, z;
};

struct Ray
{
  Ray(Point loc, Vector dir);
  
  ~Ray();

  void Move(Point shift); 

  void Move(double x = 0, double y = 0, double z = 0);

  bool operator==(Ray Other);

  Point Location;
  Vector Direction;
};

struct Sphere
{
  Sphere(Point cen, double radius, cv::Vec3b col);

  ~Sphere();

  void Move(Point shift);

  void Move(double x = 0, double y = 0, double z = 0);

  bool operator==(Sphere Other);

  Point Center;
  double Radius;
  cv::Vec3b Color;
};

struct SpherePoint
{
  SpherePoint(Sphere s, Point p);

  ~SpherePoint();

  Sphere s;
  Point p;
};