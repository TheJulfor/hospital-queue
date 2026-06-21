#include <iostream>
#include <fstream>
#include <string>
#include "hospital.h"

int main() {
    system("chcp 65001 > nul");
    std::string filename;

    std::cout << "== ПОЛИКЛИНИКА ==\n";
    std::cout << "Введите имя файла с командами: ";
    std::cin >> filename;

    std::ifstream ifile(filename);
    if (!ifile.is_open()) {
        std::cout << "!! Ошибка: не удалось открыть файл.";
        return 1;
    }

    int count;
    if (!(ifile >> count)) {
        return 0;
    }

    Hospital hospital;
    std::cout << "Обслуженные пациенты:\n";

    for (int i = 0; i < count; i++) {
        std::string command;
        ifile >> command;

        if (command == "+") {
            std::string name;
            int priority;
            ifile >> name >> priority;
            hospital.addPatient(name, priority);
        }
        else if (command == "-") {
            hospital.servePatient();
        }
    }

    ifile.close();
    return 0;
}