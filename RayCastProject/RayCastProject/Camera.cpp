#include "Camera.h"
#include "Collisions.h"
#include "Scene.h"

#include <cmath>

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

cv::Vec3b Camera::CastRay(Scene scene, Ray r)
{
  std::vector<SpherePoint> Intersections = 
    FindIntersectionPoints(scene.GetSphereList(), r);

  cv::Vec3b ReturnColor(255, 255, 255);
  // If the ray intersected with any of them, find the closest point
  if (Intersections.size() != 0)
  {
    Sphere ClosestSphere(Point(0,0,0),0,cv::Vec3b(0,0,0),Finish(0,0,0,0));
    Point ClosestPoint(0, 0, 0);
    double ShortestDistance = std::numeric_limits<double>::max();
    for (auto& SpherePoint : Intersections)
    {
      Sphere& S = SpherePoint.s;
      Point& P = SpherePoint.p;

      double TempDist = r.Location.FromThisToThat(P).Length();
      if (TempDist < ShortestDistance)
      {
        ShortestDistance = TempDist;
        ClosestSphere = S;
        ClosestPoint = P;
      }
    }

    // Compute ambient component
    cv::Vec3d& SceneAmb = scene.GetAmbientLightColor();
    cv::Vec3b SphereAmbientColor = ClosestSphere.Color * ClosestSphere.Fin.Ambient;
    SphereAmbientColor[0] *= SceneAmb[0];
    SphereAmbientColor[1] *= SceneAmb[1];
    SphereAmbientColor[2] *= SceneAmb[2];

    // Compute diffuse component
    // Translate the intersection point to avoid precision errors
    cv::Vec3b DiffuseColor(0, 0, 0);
    cv::Vec3b SpecularColor(0, 0, 0);
    Vector SphereNormal = SphereNormalAtPoint(ClosestSphere, ClosestPoint);
    ClosestPoint = ClosestPoint.Translate(SphereNormal * 0.01);
    Vector PointToLight = ClosestPoint.FromThisToThat(scene.GetLightPosition()).Normalize();
    // Check to see if intersection point is on the same side as the light
    // And to make sure there is not another sphere in the way
    double DotProduct = PointToLight.Dot(SphereNormal);
    if (DotProduct > 0)
    {
      Intersections = FindIntersectionPoints(scene.GetSphereList(), Ray(ClosestPoint, PointToLight));
      // Need to account for when spheres are past the light
      if (Intersections.size() == 0)
      {
        cv::Vec3d& LightColor = scene.GetLightColor();
        DiffuseColor = ClosestSphere.Color * ClosestSphere.Fin.Diffuse;
        DiffuseColor[0] *= DotProduct * LightColor[0];
        DiffuseColor[1] *= DotProduct * LightColor[1];
        DiffuseColor[2] *= DotProduct * LightColor[2];

        // Compute the specular light contribution
        Vector ReflectionVector = PointToLight - (SphereNormal * (2 * DotProduct));
        Vector ViewDirection = r.Location.FromThisToThat(ClosestPoint).Normalize();
        double SpecIntensity = ReflectionVector.Dot(ViewDirection);
        if (SpecIntensity > 0)
        {
          double Multiplier = 
            ClosestSphere.Fin.Specular *
            std::pow(SpecIntensity, 1 / ClosestSphere.Fin.Roughness);
          SpecularColor[0] = Multiplier * LightColor[0] * 255;
          SpecularColor[1] = Multiplier * LightColor[1] * 255;
          SpecularColor[2] = Multiplier * LightColor[2] * 255;
        }
      }
    }

    ReturnColor = SphereAmbientColor + DiffuseColor + SpecularColor;
  }

  return ReturnColor;
}

void Camera::Render(Scene scene)
{
  // Compute upper left corner of frame
  Point UpperLeftCorner(CameraRay.Location);
  UpperLeftCorner = UpperLeftCorner.Translate(CameraRay.Direction.Normalize() * FrameDistance); // Currently in center of frame
  Vector UpUnit = UprightDir.Normalize();
  UpperLeftCorner = UpperLeftCorner.Translate(UpUnit*(Height / 2)); // Currently in top center of frame
  // Compute the perpendicular, leftward facing vector and move the point to the upper left corner
  Vector LeftUnit = UprightDir.Cross(CameraRay.Direction).Normalize() * -1;
  UpperLeftCorner = UpperLeftCorner.Translate(LeftUnit*(Width / 2));

  Vector HorzInc = LeftUnit * (-1 * Width/ static_cast<double>(Resolution.width)); // Progress to the right
  Vector VertInc = UpUnit * (-1 * Height/ static_cast<double>(Resolution.height)); // Progress downwards

  // Position upper left corner to be in the center of the pixel
  UpperLeftCorner = UpperLeftCorner.Translate((HorzInc * (0.5)) + (VertInc * (0.5)));

  Point PixelLocation(0,0,0);
  // Iterate over the image space and render each occupied pixel
  for (int YPixel = 0; YPixel < Resolution.height; YPixel++)
  {
    for (int XPixel = 0; XPixel < Resolution.width; XPixel++)
    {
      PixelLocation = UpperLeftCorner.Translate((VertInc * YPixel) + (HorzInc * XPixel));
      Ray CameraToPixel(CameraRay.Location, CameraRay.Location.FromThisToThat(PixelLocation));

      cv::Vec3b PixelValue = CastRay(scene, CameraToPixel);

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



