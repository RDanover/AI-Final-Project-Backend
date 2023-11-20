#ifndef MOVE_H
#define MOVE_H
#include "Container.h"
#include <vector>

class Move {

public:
    Container* container;
    string final_location;
    unsigned int time;//time in minutes it takes for move to be completed

    Move();
    Move(Container*, string, unsigned int);
    Container* get_container();
    string get_final_location();
    unsigned int get_time();
};

extern "C" __declspec(dllexport) void* GetMoveContainer(Move * m);

extern "C" __declspec(dllexport) string GetMoveFinalLocation(Move * m);

extern "C" __declspec(dllexport) unsigned int GetMoveTime(Move * m);

#endif