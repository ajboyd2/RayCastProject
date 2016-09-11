#include "Utilities.h"
#include "Collisions.h"
#include "Camera.h"

#include <iostream>
#include <vector>

#include <opencv2/highgui.hpp>

int main()
{
  
  std::vector<Sphere> SphereList;

  SphereList.push_back(Sphere(Point(-1, 2, 0), 1));
  SphereList.push_back(Sphere(Point(1, 2, 1), 0.8));
  SphereList.push_back(Sphere(Point(0, 2, -1), 1.2));

  Camera Cam(Ray(Point(0, 0, 0), Vector(0, 1, 0)), Vector(0, 0, 1), 2, 3, 3, cv::Size(1280, 1280));

  Cam.Render(SphereList);

  cv::namedWindow("Test");
  cv::imshow("Test", Cam.GetImage());

  cv::waitKey(0);

  return 0;
}