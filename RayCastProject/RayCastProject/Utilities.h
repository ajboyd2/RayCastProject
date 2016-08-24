



struct Point
{
  Point(double x, double y, double z);
  
  ~Point();

  bool operator==(Point other);
  
  Point operator+(Point other);
  
  void operator+=(Point other);

  Point operator-(Point other);

  void operator-=(Point other);

  double x, y, z;
};

struct Vector
{
  Vector(double x, double y, double z);

  ~Vector();

  bool operator==(Vector other);

  Vector operator+(Vector other);

  void operator+=(Vector other);

  Vector operator-(Vector other);

  void operator-=(Vector other);

  double x, y, z;
};

struct Ray
{
  Ray(Point loc, Vector dir);
  
  ~Ray();

  void Move(Point shift); 

  void Move(double x = 0, double y = 0, double z = 0);

  bool operator==(Ray other);

  Point Location;
  Vector Direction;
};

struct Sphere
{
  Sphere(Point cen, double radius);

  ~Sphere();

  void Move(Point shift);

  void Move(double x = 0, double y = 0, double z = 0);

  bool operator==(Sphere other);

  Point Center;
  double Radius;
};