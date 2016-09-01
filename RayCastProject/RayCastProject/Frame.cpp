#include "Frame.h"
#include "Collisions.h"

Frame::Frame(
  Point CameraPosition,
  Ray CameraDirection,
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

Frame::~Frame()
{
}

bool Frame::CastRay(std::vector<Sphere> SphereList, Ray r)
{
  std::vector<SpherePoint> Intersections = 
    FindIntersectionPoints(SphereList, r);

  return Intersections.size() != 0;
}

void Frame::CastAllRays(std::vector<Sphere> SphereList)
{

}

void Frame::SetCameraPosition(Point Position)
{
  CameraPosition = Position;
}

void Frame::SetCameraDirection(Ray Direction)
{
  CameraDirection = Direction;
}

void Frame::SetFrameDistance(double Distance)
{
  FrameDistance = Distance;
}

void Frame::SetWidth(double W)
{
  Width = W;
}

void Frame::SetHeight(double H)
{
  Height = H;
}

void Frame::SetResolution(cv::Size Res)
{
  Resolution = Res;
}



