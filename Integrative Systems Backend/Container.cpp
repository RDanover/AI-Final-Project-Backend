#include "pch.h"
#include "Container.h"

Container::Container() {
	location = "";
	description = "";
	weight = -1;
}

Container::Container(string l, string d, int w) {
	location = l;
	description = d;
	weight = w;
}

string Container::get_location() {
	return location;
}

string Container::get_description() {
	return description;
}

int Container::get_weight() {
	return weight;
}

void Container::set_weight(int w) {
	weight = w;
}

extern "C" __declspec(dllexport) void* ConstructContainer(string l, string d, int w) {
	return (void*)new Container(l, d, w);
}
extern "C" __declspec(dllexport) string GetContainerLocation(Container * c) {
	return c->get_location();
}
extern "C" __declspec(dllexport) string GetContainerDescription(Container * c) {
	return c->get_description();
}
extern "C" __declspec(dllexport) int GetContainerWeight(Container * c) {
	return c->get_weight();
}
extern "C" __declspec(dllexport) void SetContainerWeight(Container * c, int w) {
	c->set_weight(w);
}