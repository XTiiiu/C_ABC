#pragma once

#include"MyPoint.h"

class MyCircle
{
public:
	void setCircle(int r, int x, int y);
	int judgeInside(MyPoint &myp);
private:
	int mr;
	int mx;
	int my;

};

