#include "Camera.h"
#include "Collisions.h"

Camera::Camera(
  Ray CameraRay,
  double FrameDistance,
  double Width,
  double Height,
  cv::Size Resolution)
  : CameraPosition(CameraPosition),
  CameraDirection(CameraDirection),
  FrameDistance(FrameDistance),
  Width(Width),
  Height(Height),
  Resolution(Resolution),
  Image(cv::Mat(Resolution, CV_8UC3))
{
}

Camera::~Camera()
{
}

bool Camera::CastRay(std::vector<Sphere> SphereList, Ray r)
{
  std::vector<SpherePoint> Intersections = 
    FindIntersectionPoints(SphereList, r);

  return Intersections.size() != 0;
}

void Camera::Render(std::vector<Sphere> SphereList)
{

}

void Camera::SetCameraRay(Ray R)
{
  CameraRay = R;
}

void Camera::SetFrameDistance(double Distance)
{
  FrameDistance = Distance;
}

void Camera::SetWidth(double W)
{
  Width = W;
}

void Camera::SetHeight(double H)
{
  Height = H;
}

void Camera::SetResolution(cv::Size Res)
{
  Resolution = Res;
}



