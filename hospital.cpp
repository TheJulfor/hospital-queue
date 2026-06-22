#include "hospital.h"
#include <iostream>

Hospital::Hospital() : capacity(10), size(0), nextId(0) {
    patients = new Patient[capacity];
}

Hospital::~Hospital() {
    delete[] patients;
}

void Hospital::resize() {
    capacity *= 2;
    Patient* newArr = new Patient[capacity];
    for (int i = 0; i < size; ++i) {
        newArr[i] = patients[i];
    }
    delete[] patients;
    patients = newArr;
}

void Hospital::push(const std::string& name, int priority) {
    if (size >= capacity) {
        resize();
    }

    Patient newPatient = {name, priority, nextId++};

    int i = size - 1;
    while (i >= 0) {
        if (patients[i].priority < newPatient.priority ||
           (patients[i].priority == newPatient.priority && patients[i].id < newPatient.id)) {

            patients[i + 1] = patients[i];
            i--;
        } else {
            break;
        }
    }

    patients[i + 1] = newPatient;
    size++;
}

Patient Hospital::top() const {
    if (size > 0) {
        return patients[size - 1];
    }
    return Patient{"", 0, 0};
}

void Hospital::pop() {
    if (size > 0) {
        size--;
    }
}

bool Hospital::empty() const {
    return size == 0;
}