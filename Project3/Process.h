#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include <cstddef>

class Process {
private:
    int pid;
    std::string name;
    size_t memoryRequested;
public:
    Process(int id, std::string n, size_t mem);
    int getPid() const;
    std::string getName() const;
    size_t getMemorySize() const;
};

#endif