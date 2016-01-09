#ifndef KEYBOARD_H
#define KEYBOARD_H

class keyboard_out;
class keyboard_in
{
public:
	keyboard_in(keyboard_out& kot):_kot(kot)
	{
	}
	bool key_a();
	bool key_w();
	bool key_s();
	bool key_d();
	bool key_f();
	bool key_v();
	bool key_h();
	bool key_k();
	bool key_esc();
private:
	keyboard_out& _kot;
};

class keyboard_out
{
public:
	keyboard_out()
	{
	  _a=false;
	  _w=false;
	  _s=false;
	  _d=false;
	  _h=false;
	  _k=false;
	  _f=false;
	  _v=false;
	  _esc=false;
	}
	void set_key_a();
	void set_key_w();
	void set_key_s();
	void set_key_d();
	void set_key_f();
	void set_key_v();
	void set_key_h();
	void set_key_k();
	void set_key_esc();
	void unset_key_a();
	void unset_key_w();
	void unset_key_s();
	void unset_key_d();
	void unset_key_f();
	void unset_key_v();
	void unset_key_h();
	void unset_key_k();
	void unset_key_esc();
private:
	friend keyboard_in;
	bool _a;
	bool _w;
	bool _s;
	bool _d;
	bool _h;
	bool _k;
	bool _f;
	bool _v;
	bool _esc;
};

#endif
