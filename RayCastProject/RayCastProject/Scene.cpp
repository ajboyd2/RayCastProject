#include "Scene.h"

Scene::Scene(std::vector<Sphere> SphereList,
  Point(LightPosition),
  cv::Vec3b AmbientLightColor)
  : SphereList(SphereList),
  LightPosition(LightPosition),
  AmbientLightColor(AmbientLightColor)
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

void Scene::SetAmbientLightColor(cv::Vec3b color)
{
  AmbientLightColor = color;
}