#include "pch.h"
#include "Operation.h"

Operation::Operation() {
    username = "";
    note = "";
    load_or_balance = ' ';
    manifest_path = "";
    log_path = "";
}
void Operation::set_username(string name) {
    username = name;
    //update log
}

void Operation::set_note(string n) {
    note = n;
    //update log
}

void Operation::set_load_or_balance(char a) {
    load_or_balance = a;
}

void Operation::set_manifest_path(string path) {
    manifest_path = path;
    //update log stating manifest was opened
}

string Operation::get_manifest_path() {
    //make sure new manifest has been saved to new location before returning the path
    return manifest_path;
}
string Operation::get_log_path() {
    return log_path;
}
vector<Container*> Operation::get_containers() {
    //make sure all containers have been gotten before returning containers
    return containers;
}

vector<Move*> Operation::get_moves() {
    //Calculate moves given all the data before returning moves
    return moves;
}

void Operation::set_unload(vector<Container*>) {
    //do something with containers to be unloaded
}

void Operation::set_load(vector<Container*>) {
    //do something with container to be loaded
}

void Operation::move_complete(int a) {
    //update log and manfiest that move at index a of the vector moves is complete
}

void Operation::reset() {
    username = "";
    note = "";
    load_or_balance = ' ';
    manifest_path = "";
    for (Container* ptr : containers) {
        delete ptr;
    }
    for (Move* ptr : moves) {
        delete ptr;
    }
}

extern "C" __declspec(dllexport) void* ConstructOperation() {
    return (void*)new Operation();
}
extern "C" __declspec(dllexport) void SetOperationUserName(Operation * o, string n) {
    o->set_username(n);
}
extern "C" __declspec(dllexport) void SetOperationNote(Operation * o, string n) {
    o->set_note(n);
}
extern "C" __declspec(dllexport) void SetOperationLoadOrBalance(Operation * o, char x) {
    o->set_load_or_balance(x);
}
extern "C" __declspec(dllexport) void SetOperationManifestPath(Operation * o, string m) {
    o->set_manifest_path(m);
}
extern "C" __declspec(dllexport) string GetOperationManifestPath(Operation * o) {
    return o->get_manifest_path();
}
extern "C" __declspec(dllexport) string GetOperationLogPath(Operation * o) {
    return o->get_log_path();
}
extern "C" __declspec(dllexport) void GetOperationContainers(Operation * o, vector<Container*>&c) {

    c = o->get_containers();    
}
extern "C" __declspec(dllexport) void GetOperationMoves(Operation * o, vector<Move*>&m) {
    m = o->get_moves();
}
extern "C" __declspec(dllexport) void SetOperationUnLoad(Operation * o, vector<Container*>&c) {

    o->set_unload(c);
}
extern "C" __declspec(dllexport) void SetOperationLoad(Operation * o, vector<Container*>&c) {

    o->set_load(c);
}
extern "C" __declspec(dllexport) void OperationMoveComplete(Operation * o, int a) {

    o->move_complete(a);
}
extern "C" __declspec(dllexport) void OperationReset(Operation * o) {

    o->reset();
}