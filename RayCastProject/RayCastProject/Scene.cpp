#include "Scene.h"

Scene::Scene(std::vector<Sphere> SphereList,
  Point LightPosition,
  cv::Vec3d AmbientLightColor,
  cv::Vec3d LightColor)
  : SphereList(SphereList),
  LightPosition(LightPosition),
  AmbientLightColor(AmbientLightColor),
  LightColor(LightColor)
{
}

Scene::~Scene()
{
}

void Scene::SetSphereList(std::vector<Sphere> sl)
{
  SphereList = sl;
}

void Scene::SetLightPosition(Point pos)
{
  LightPosition = pos;
}

void Scene::SetAmbientLightColor(cv::Vec3d color)
{
  AmbientLightColor = color;
}

void Scene::SetLightColor(cv::Vec3d color)
{
  LightColor = color;
}