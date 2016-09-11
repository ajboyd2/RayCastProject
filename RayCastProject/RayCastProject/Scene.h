#pragma once

#include "Utilities.h"

#include <vector>

class Scene
{
public:

  Scene(
    std::vector<Sphere> SphereList,
    Point LightPosition,
    cv::Vec3d AmbientLightColor,
    cv::Vec3d LightColor);

  ~Scene();

  std::vector<Sphere> GetSphereList();
  Point GetLightPosition();
  cv::Vec3d GetAmbientLightColor();
  cv::Vec3d GetLightColor();


  void SetSphereList(std::vector<Sphere> sl);
  void SetLightPosition(Point pos);
  void SetAmbientLightColor(cv::Vec3d color);
  void SetLightColor(cv::Vec3d color);


private:

  std::vector<Sphere> SphereList;
  Point LightPosition;
  cv::Vec3d AmbientLightColor;
  cv::Vec3d LightColor;
};

inline std::vector<Sphere> Scene::GetSphereList()
{
  return SphereList;
}

inline Point Scene::GetLightPosition()
{
  return LightPosition;
}

inline cv::Vec3d Scene::GetAmbientLightColor()
{
  return AmbientLightColor;
}

inline cv::Vec3d Scene::GetLightColor()
{
  return LightColor;
}