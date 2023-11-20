#ifndef CONTAINER_H
#define CONTAINER_H
using namespace std;
#include <string>

class Container {

public:
    string location;
    string description;
    unsigned int weight;

    Container();
    Container(string, string, unsigned int);
    string get_location();
    string get_description();
    unsigned int get_weight();
    void set_weight(unsigned int);
};

extern "C" __declspec(dllexport) void* ConstructContainer(string l, string d, unsigned int w);
extern "C" __declspec(dllexport) string GetContainerLocation(Container * c);
extern "C" __declspec(dllexport) string GetContainerDescription(Container * c);
extern "C" __declspec(dllexport) unsigned int GetContainerWeight(Container * c);
extern "C" __declspec(dllexport) void SetContainerWeight(Container * c, unsigned int w);

#endif