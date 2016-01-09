#ifndef MOUSE_H
#define MOUSE_H

class mouse_out;
class mouse_in
{
public:
	mouse_in(mouse_out& mot):_mot(mot)
	{}
	int mouse_x();
	int mouse_y();
	int click_read();
private:
	mouse_out& _mot;
};

class mouse_out
{
public:
	mouse_out()
	{
		_x = 0;
		_y = 0;
		_click = 0;
	}
	void set_x(int);
	void set_y(int);
	void click();
	void motion();
	void move();
private:
	friend mouse_in;
	int _click;
	int _x;
	int _y;
};

#endif
