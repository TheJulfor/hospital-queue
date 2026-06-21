#include "hospital.h"
#include <iostream>

Hospital::Hospital() : nextId(0) {}

void Hospital::addPatient(const std::string& name, int priority) {
    queue.push({name, priority, nextId});
    nextId++;
}

void Hospital::servePatient() {
    if (!queue.empty()) {
        std::cout << queue.top().name << std::endl;
        queue.pop();
    }
}