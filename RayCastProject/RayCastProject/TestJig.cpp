#include "Utilities.h"
#include "Collisions.h"
#include "Camera.h"
#include "Scene.h"

#include <iostream>
#include <vector>

#include <opencv2/highgui.hpp>

int main()
{
  
  std::vector<Sphere> SphereList;

  SphereList.push_back(Sphere(Point(-1, 2, 0), 1, cv::Vec3b(100, 100, 40), Finish(1, 0.4)));
  SphereList.push_back(Sphere(Point(1, 2, 1), 0.8, cv::Vec3b(40, 180, 40), Finish(0.4, 0.4)));
  SphereList.push_back(Sphere(Point(0, 2, -1), 1.2, cv::Vec3b(0, 100, 200), Finish(0.8, 0.4)));

  Scene MasterScene(SphereList, Point(0, 0, 100), cv::Vec3b(255, 255, 255));

  Camera Cam(Ray(Point(0, 0, 0), Vector(0, 1, 0)), Vector(0, 0, 1), 2, 3, 3, cv::Size(1280, 1280));

  Cam.Render(MasterScene);

  cv::namedWindow("Test");
  cv::imshow("Test", Cam.GetImage());

  cv::waitKey(0);

  return 0;
}