#pragma once

#include "Utilities.h"
#include <opencv2/core.hpp>
#include <vector>

class Frame
{
public:

  Frame(
    Point CameraPosition,
    Ray CameraDirection,
    double FrameDistance,
    double Width,
    double Height,
    cv::Size Resolution);
    
  ~Frame();

  static bool CastRay(std::vector<Sphere> SphereList, Ray r);

  void CastAllRays(std::vector<Sphere> SphereList);
  
  void SetCameraPosition(Point Position);
  void SetCameraDirection(Ray Direction);
  void SetFrameDistance(double Distance);
  void SetWidth(double Width);
  void SetHeight(double Height);
  void SetResolution(cv::Size Resolution);

  Point GetCameraPosition();
  Ray GetCameraDirection();
  double GetFrameDistance(); 
  double GetWidth();
  double GetHeight();
  cv::Size GetResolution(); 
  cv::Mat GetImage();


private:


  Point CameraPosition;
  Ray CameraDirection;
  double FrameDistance; // Perpendicular distance from camera to frame
  // Width and Height of the frame in units
  double Width;
  double Height; 
  cv::Size Resolution; // Resolution of resulting image
  cv::Mat Image;
};

inline Point Frame::GetCameraPosition()
{
  return CameraPosition;
}

inline Ray Frame::GetCameraDirection()
{
  return CameraDirection;
}

inline double Frame::GetFrameDistance()
{
  return FrameDistance;
}

inline double Frame::GetWidth()
{
  return Width;
}

inline double Frame::GetHeight()
{
  return Height;
}

inline cv::Size Frame::GetResolution()
{
  return Resolution;
}

inline cv::Mat Frame::GetImage()
{
  return Image;
}