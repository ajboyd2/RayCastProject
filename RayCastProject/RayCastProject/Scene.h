#pragma once

#include "Utilities.h"

#include <vector>

class Scene
{
public:

  Scene(
    std::vector<Sphere> SphereList,
    Point LightPosition,
    cv::Vec3b AmbientLightColor);

  ~Scene();

  std::vector<Sphere> GetSphereList();
  Point GetLightPosition();
  cv::Vec3b GetAmbientLightColor();

  void SetSphereList(std::vector<Sphere> sl);
  void SetLightPosition(Point pos);
  void SetAmbientLightColor(cv::Vec3b color);

private:

  std::vector<Sphere> SphereList;
  Point LightPosition;
  cv::Vec3b AmbientLightColor;
};

inline std::vector<Sphere> Scene::GetSphereList()
{
  return SphereList;
}

inline Point Scene::GetLightPosition()
{
  return LightPosition;
}

inline cv::Vec3b Scene::GetAmbientLightColor()
{
  return AmbientLightColor;
}