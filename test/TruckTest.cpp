#include "gtest/gtest.h"
#include "Truck.h"

TEST(TruckTest, Destructor)
{
    Truck* truck = new Truck("Seat Ibiza", "Aluminium", 24, 4, 100);
    EXPECT_EQ(truck->getNrWheels(), 4);
    EXPECT_EQ(truck->getPower(), 100);
    truck->~Truck();
    EXPECT_NE(truck->getWheel(1)->getDiameter(), 24);
    EXPECT_NE(truck->getPower(),100);
}

TEST(TruckTest, CopyConstructor)
{
    Truck truck("Volswagen Passat", "Steel", 23, 4, 50);
    Truck truck2(truck);
    EXPECT_EQ(truck2.getNrWheels(), truck.getNrWheels());
    EXPECT_EQ(truck2.getPower(), truck.getPower());
    EXPECT_NE(truck2.getWheel(1), truck.getWheel(1));
}

TEST(TruckTest, AssignmentOperator)
{
    Truck truck("Seat Ibiza", "Aluminium", 25, 4, 100);
    Truck truck2("Volkswagen Passat", "Steel", 24, 4, 50);
    truck = truck2;
    EXPECT_EQ(truck.getModel(), "Volkswagen Passat");
    EXPECT_EQ(truck.getPower(), 50);
    Wheel* wheel_truck2 = truck2.getWheel(1);
    EXPECT_NE(truck.getWheel(1), wheel_truck2);
}
