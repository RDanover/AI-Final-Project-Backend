#ifndef OPERATION_H
#define OPERATION_H

#include "Move.h"

class Operation {

public:
    string username;
    string note;
    char load_or_balance; // set to l means load operation, set to b means balance
    string manifest_path; //file location of the manifest
    vector<Container*> containers; //vector of container pointers
    vector<Move*> moves; //vector of move pointers to be completed in order index 0 = first move

    Operation();

    void set_username(string);

    void set_note(string);

    void set_load_or_balance(char);

    void set_manifest_path(string);

    string get_manifest_path();

    vector<Container*> get_containers();

    vector<Move*> get_moves();

    void set_unload(vector<Container*>);

    void set_load(vector<Container*>);

    void move_complete(int);

    void reset();

};

extern "C" __declspec(dllexport) void* ConstructOperation();
extern "C" __declspec(dllexport) void SetOperationUserName(Operation * o, string n);
extern "C" __declspec(dllexport) void SetOperationNote(Operation * o, string n);
extern "C" __declspec(dllexport) void SetOperationLoadOrBalance(Operation * o, char x);
extern "C" __declspec(dllexport) void SetOperationManifestPath(Operation * o, string m);
extern "C" __declspec(dllexport) string GetOperationManifestPath(Operation * o);
extern "C" __declspec(dllexport) void GetOperationContainers(Operation * o, vector<Container*>&c);
extern "C" __declspec(dllexport) void GetOperationMoves(Operation * o, vector<Move*>&m);
extern "C" __declspec(dllexport) void SetOperationUnLoad(Operation * o, vector<Container*>&c);
extern "C" __declspec(dllexport) void SetOperationLoad(Operation * o, vector<Container*>&c);
extern "C" __declspec(dllexport) void OperationMoveComplete(Operation * o, int a);
extern "C" __declspec(dllexport) void OperationReset(Operation * o);

#endif