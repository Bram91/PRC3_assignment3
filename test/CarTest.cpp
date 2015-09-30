#include "gtest/gtest.h"
#include "Car.h"

TEST(CarTest, Destructor)
{
    Car* car = new Car("Seat Ibiza", "Aluminium", 24, 4);
    EXPECT_EQ(car->getNrWheels(), 4);
    car->~Car();
    EXPECT_NE(car->getWheel(1)->getDiameter(), 24);
}

TEST(CarTest, CopyConstructor)
{
    Car car("Volswagen Passat", "Steel", 23, 4);
    Car car2(car);
    EXPECT_EQ(car2.getNrWheels(), car.getNrWheels());
    EXPECT_NE(car2.getWheel(1), car.getWheel(1));
}

TEST(CarTest, AssignmentOperator)
{
    Car car("Seat Ibiza", "Aluminium", 25, 4);
    Car car2("Volkswagen Passat", "Steel", 24, 4);
    car = car2;
    EXPECT_EQ(car.getModel(), "Volkswagen Passat");
    Wheel* wheel_car2 = car2.getWheel(1);
    EXPECT_NE(car.getWheel(1), wheel_car2);
}
