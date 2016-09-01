#include "Utilities.h"
#include <opencv2/core.hpp>

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

  static bool CastRay(std::vector<SpherePoint> SphereList, Ray r);

  void CastAllRays(std::vector<SpherePoint> SphereList);
  
  void SetCameraPosition();
  void SetCameraDirection();
  void SetFrameDistance();
  void SetWidth();
  void SetHeight();
  void SetResolution();

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