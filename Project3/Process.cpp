#include "Process.h"

Process::Process(int id, std::string n, size_t mem) 
    : pid(id), name(n), memoryRequested(mem) {}

int Process::getPid() const { return pid; }
std::string Process::getName() const { return name; }
size_t Process::getMemorySize() const { return memoryRequested; }