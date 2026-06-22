#ifndef HOSPITAL
#define HOSPITAL

#include <string>

struct Patient {
    std::string name;
    int priority;
    int id;
};

class Hospital {
    Patient* patients;
    int capacity;
    int size;
    int nextId;

    void resize();

public:
    Hospital();
    ~Hospital();

    void push(const std::string& name, int priority);
    Patient top() const;
    void pop();
    bool empty() const;
};

#endif