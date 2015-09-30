#include "Truck.h"

Truck::Truck(const string& model, const string& material, int diameter, int nrWheels, int power)
	:Car(model, material, diameter, nrWheels)
	{
		this-> power = new int(power);
	}

Truck::~Truck()
{
	delete power;
}

int Truck::getPower()
{
	return *power;
}

Truck::Truck(const Truck& myTruck)
	: Car(myTruck)
{
	power = new int(*myTruck.power);
}

Truck& Truck::operator=(const Truck& myTruck)
{
	if(&myTruck == this) 
	{
		return *this;
	}

	Car::operator=(myTruck);
	delete power;
	power = new int(*myTruck.power);
	return *this;
}
