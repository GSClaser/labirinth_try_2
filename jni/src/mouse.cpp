#include "mouse.h"

void mouse_out::set_x(int x)
{
	_x = x;
}

void mouse_out::set_y(int y)
{
	_y = y;
}

void mouse_out::click()
{
	_click = 1;
}

void mouse_out::motion()
{
	_click = 0;
}

void mouse_out::move()
{
	_click = 2;
}

int mouse_in::mouse_x()
{
	return _mot._x;
}

int mouse_in::mouse_y()
{
	return _mot._y;
}

int mouse_in::click_read()
{
	return _mot._click;
}
