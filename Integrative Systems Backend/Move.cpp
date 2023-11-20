#include "pch.h"
#include "Move.h"

Move::Move() {
	container = new Container();
	final_location = "";
	time = 0;
}

Move::Move(Container* c, string fl, unsigned int t) {
	container = c;
	final_location = fl;
	time = t;
}

Container* Move::get_container() {
	return container;
}

string Move::get_final_location() {
	return final_location;
}

unsigned int Move::get_time() {
	return time;
}

extern "C" __declspec(dllexport) void* GetMoveContainer(Move * m) {
	return m->get_container();
}

extern "C" __declspec(dllexport) string GetMoveFinalLocation(Move * m) {
	return m->get_final_location();
}

extern "C" __declspec(dllexport) unsigned int GetMoveTime(Move * m) {
	return m->get_time();
}