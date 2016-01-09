#include "keyboard.h"

void keyboard_out::set_key_a()
{
	_a = true;
}
void keyboard_out::set_key_w()
{
	_w = true;
}
void keyboard_out::set_key_s()
{
	_s = true;
}
void keyboard_out::set_key_d()
{
	_d = true;
}
void keyboard_out::set_key_h()
{
	_h = true;
}
void keyboard_out::set_key_k()
{
	_k = true;
}
void keyboard_out::set_key_f()
{
	_f = true;
}
void keyboard_out::set_key_v()
{
	_v = true;
}
void keyboard_out::set_key_esc()
{
	_esc = true;
}
void keyboard_out::unset_key_a()
{
	_a = false;
}
void keyboard_out::unset_key_w()
{
	_w = false;
}
void keyboard_out::unset_key_s()
{
	_s = false;
}
void keyboard_out::unset_key_d()
{
	_d = false;
}
void keyboard_out::unset_key_h()
{
	_h = false;
}
void keyboard_out::unset_key_k()
{
	_k = false;
}
void keyboard_out::unset_key_f()
{
	_f = false;
}
void keyboard_out::unset_key_v()
{
	_v = false;
}
void keyboard_out::unset_key_esc()
{
	_esc = false;
}
bool keyboard_in::key_a()
{
	return _kot._a;
}
bool keyboard_in::key_w()
{
	return _kot._w;
}
bool keyboard_in::key_s()
{
	return _kot._s;
}
bool keyboard_in::key_d()
{
	return _kot._d;
}
bool keyboard_in::key_h()
{
	return _kot._h;
}
bool keyboard_in::key_k()
{
	return _kot._k;
}
bool keyboard_in::key_f()
{
	return _kot._f;
}
bool keyboard_in::key_v()
{
	return _kot._v;
}
bool keyboard_in::key_esc()
{
	return _kot._esc;
}
