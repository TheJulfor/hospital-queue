#ifndef HOSPITAL
#define HOSPITAL

#include <string>
#include <queue>

struct Patient {
    std::string name;
    int priority;
    int id;

    bool operator<(const Patient& second) const {
        if (priority != second.priority) {
            return priority > second.priority;
        }
        return id > second.id;
    }
};

class Hospital {
    std::priority_queue<Patient> queue;
    int nextId;

public:
    Hospital();

    void addPatient(const std::string& name, int priority);
    void servePatient();
};

#endif