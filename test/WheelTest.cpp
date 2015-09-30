#include "gtest/gtest.h"
#include "Wheel.h"

TEST(WheelTest, Material)
{
	Wheel wheel(23,"Chocolade");
	EXPECT_EQ(wheel.getMaterial(), "Chocolade");
	wheel.setMaterial("Peperkoek");
	EXPECT_EQ(wheel.getMaterial(), "Peperkoek");
}

TEST(WheelTest, Size)
{
	Wheel wheel(23,"Chocolade");
	EXPECT_EQ(wheel.getDiameter(), 23);
}
