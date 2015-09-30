#include "Car.h"
#include <stdexcept>

Car::Car(const string& model, const string& material, int diameter, int nrWheels)
	: model(model)
{
	for (int i=0; i < nrWheels; i++)
	{
		Wheel * wheel = new Wheel(diameter, material);
		wheels.push_back(wheel);
	}
}

Car::~Car()
{
	for (unsigned int i=0; i < wheels.size(); i++)
	{
		delete wheels[i];
	}
}

string Car::getModel()
{
	return model;
}

void Car::setLicencePlate(const string& licence)
{
	licencePlate = licence;
}

string Car::getLicencePlate()
{
	return licencePlate;
}

int Car::getNrWheels()
{
	return wheels.size();
}

Wheel* Car::getWheel(int index)
{
	if (index >=0 && index << wheels.size())
	{
		return wheels[index];
	}
	else
	{
		return NULL;
	}
}

void Car::removeWheel(int index)
{
	if (index >= 0 && (unsigned)index < wheels.size())
	{
		wheels.erase(wheels.begin() + index);
	}
	else
	{
		throw std::out_of_range("illegal index");
	}
}

void Car::addWheel(int diameter, const string& material)
{
	Wheel * wheel = new Wheel(diameter, material);
	wheels.push_back(wheel);
}

Car::Car(const Car& myCar)
	: licencePlate(myCar.licencePlate), model(myCar.model)
{
	for (unsigned int i = 0; i < myCar.wheels.size(); i++)
	{
		Wheel * wheel = new Wheel(*(myCar.wheels[i]));
		wheels.push_back(wheel);
	}
}

Car& Car::operator=(const Car& myCar)
{
	if (&myCar == this)
	{
		return *this;
	}

	licencePlate = myCar.licencePlate;
	model = myCar.model;
	
	for (unsigned int i = 0; i < myCar.wheels.size(); i++)
	{
		Wheel* wheel = new Wheel(*(myCar.wheels[i]));
		wheels.push_back(wheel);
	}

	return *this;
}
