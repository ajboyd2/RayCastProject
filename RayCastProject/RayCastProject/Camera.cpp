#include "Camera.h"
#include "Collisions.h"

Camera::Camera(
  Ray CameraRay,
  Vector UprightDir,
  double FrameDistance,
  double Width,
  double Height,
  cv::Size Resolution)
  : CameraRay(CameraRay),
  UprightDir(UprightDir),
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

  // If the ray intersected with any of them, return true
  return Intersections.size() != 0;
}

void Camera::Render(std::vector<Sphere> SphereList)
{
  // Compute upper left corner of frame
  Point UpperLeftCorner(CameraRay.Location);
  UpperLeftCorner = UpperLeftCorner.Translate(CameraRay.Direction); // Currently in center of frame
  Vector UpUnit = UprightDir.Normalize();
  UpperLeftCorner = UpperLeftCorner.Translate(UpUnit*(Height / 2)); // Currently in top center of frame
  // Compute the perpendicular, leftward facing vector and move the point to the upper left corner
  Vector LeftUnit = UprightDir.Cross(CameraRay.Direction).Normalize();
  UpperLeftCorner = UpperLeftCorner.Translate(LeftUnit*(Width / 2));

  Vector HorzInc = LeftUnit * (-1 / Width);
  Vector VertInc = UpUnit * (-1 / Height);

  // Position upper left corner to be in the center of the pixel
  UpperLeftCorner = UpperLeftCorner.Translate((HorzInc * (0.5)) + (VertInc * (0.5)));

  // Iterate over the image space and render each occupied pixel
  for (int YPixel = 0; YPixel < Resolution.height; YPixel++)
  {
    for (int XPixel = 0; XPixel < Resolution.width; XPixel++)
    {
      Point PixelLocation = UpperLeftCorner.Translate((VertInc * YPixel) + (HorzInc * XPixel));
      Ray CameraToPixel(CameraRay.Location, CameraRay.Location.FromThisToThat(PixelLocation));

      cv::Vec3b PixelValue;
      if (CastRay(SphereList, CameraToPixel))
      {
        PixelValue[0] = 255;
        PixelValue[1] = 255;
        PixelValue[2] = 255;
      }
      else
      {
        PixelValue[0] = 0;
        PixelValue[1] = 0;
        PixelValue[2] = 0;
      }

      Image.at<cv::Vec3b>(YPixel, XPixel) = PixelValue;
    }
  }
}

void Camera::SetCameraRay(Ray R)
{
  CameraRay = R;
}

void Camera::SetUprightDir(Vector Dir)
{
  UprightDir = Dir;
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



