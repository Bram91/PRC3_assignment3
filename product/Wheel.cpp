#include "Wheel.h"

Wheel::Wheel(int diameter, const string& material)
	:diameter(diameter), material(material)
{

}

std::string Wheel::getMaterial()
{
	return material;
}

void Wheel::setMaterial(const std::string& material)
{
	Wheel::material = material;
}

int Wheel::getDiameter()
{
	return diameter;
}
