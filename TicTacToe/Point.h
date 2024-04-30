#pragma once


struct Point {
public:
	Point() = default;
	Point(int x, int y)
		: x_{ x }, y_{ y }
	{
	}

public:
	int x_;
	int y_;
};