#pragma once

#include "Utilities.h"
#include <opencv2/core.hpp>
#include <vector>

class Camera
{
public:

  Camera(
    Ray CameraRay,
    Vector UprightDir,
    double FrameDistance,
    double Width,
    double Height,
    cv::Size Resolution);
    
  ~Camera();

  static bool CastRay(std::vector<Sphere> SphereList, Ray r);

  void Render(std::vector<Sphere> SphereList);
  
  void SetCameraRay(Ray R);
  void SetUprightDir(Vector Dir);
  void SetFrameDistance(double Distance);
  void SetWidth(double Width);
  void SetHeight(double Height);
  void SetResolution(cv::Size Resolution);

  Ray GetCameraRay();
  Vector GetUprightDir();
  double GetFrameDistance(); 
  double GetWidth();
  double GetHeight();
  cv::Size GetResolution(); 
  cv::Mat GetImage();


private:


  Ray CameraRay;
  Vector UprightDir;
  double FrameDistance; // Perpendicular distance from camera to Camera
  // Width and Height of the Camera in units
  double Width;
  double Height; 
  cv::Size Resolution; // Resolution of resulting image
  cv::Mat Image;
};

inline Ray Camera::GetCameraRay()
{
  return CameraRay;
}

inline Vector Camera::GetUprightDir()
{
  return UprightDir;
}

inline double Camera::GetFrameDistance()
{
  return FrameDistance;
}

inline double Camera::GetWidth()
{
  return Width;
}

inline double Camera::GetHeight()
{
  return Height;
}

inline cv::Size Camera::GetResolution()
{
  return Resolution;
}

inline cv::Mat Camera::GetImage()
{
  return Image;
}