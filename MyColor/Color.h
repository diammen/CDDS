#pragma once

class MyColor
{
public:
	MyColor();
	MyColor(int red, int green, int blue, int alpha);

	int r;
	int g;
	int b;
	int a = 256;

	MyColor operator+(const MyColor &rhs) const
	{
		return MyColor(r + rhs.r, g + rhs.g, b + rhs.b, a + rhs.a);
	}
	MyColor operator-(const MyColor &rhs) const;
	MyColor operator*(const MyColor &rhs) const;
	MyColor operator/(const MyColor &rhs) const;

	MyColor& operator+=(const MyColor &rhs)
	{
		r = (r + rhs.r) % 255;
		g = (g + rhs.g) % 255;
		b = (b + rhs.b) % 255;
		a = (a + rhs.a) % 255;

		return *this;
	}
	MyColor& operator-=(const MyColor &rhs);
	MyColor& operator*=(const MyColor &rhs);
	MyColor& operator/=(const MyColor &rhs);

	bool operator==(const MyColor &rhs) const
	{
		if (r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a)
			return true;
		return false;
	}
	bool operator!=(const MyColor &rhs) const;

	MyColor operator!() const;
};