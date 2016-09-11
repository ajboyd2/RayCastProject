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

  SphereList.push_back(Sphere(Point(-1, 2, 0), 1, cv::Vec3b(100, 100, 40), Finish(1, 0.4, 0.5, 0.05)));
  SphereList.push_back(Sphere(Point(1, 2, 1), 0.8, cv::Vec3b(40, 180, 40), Finish(0.4, 0.4, 0.5, 0.05)));
  SphereList.push_back(Sphere(Point(0, 2, -1), 1.2, cv::Vec3b(0, 100, 200), Finish(0.8, 0.4, 0.5, 0.05)));

  Scene MasterScene(SphereList, Point(0, 0, 100), cv::Vec3d(1.0, 1.0, 1.0), cv::Vec3d(1.5, 1.5, 1.5));

  Point CameraPosition(0, -1, 2);
  Point CenterOfScene(0, 0, 0);
  Vector CameraDirection(CameraPosition.FromThisToThat(CenterOfScene));
  Vector Left(Vector(0, 1, 0).Cross(CameraDirection));
  Vector Up(CameraDirection.Cross(Left));

  Camera Cam(
    Ray(CameraPosition + Point(0, 0, 3), CameraDirection), // Camera Ray
    Up, // Up Direction
    3, // Frame Distance
    3, // Frame Width
    3, // Frame Height
    cv::Size(1280, 1280)); // Image Resolution

  Cam.Render(MasterScene);

  cv::namedWindow("Test");
  cv::imshow("Test", Cam.GetImage());

  cv::waitKey(0);

  return 0;
}

