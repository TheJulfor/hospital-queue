#include <iostream>
#include <fstream>
#include <string>

int main() {
    system("chcp 65001 > nul");
    std::string filename;

    std::cout << "== ПОЛИКЛИНИКА ==\n";
    std::cout << "Введите имя файла с командами: ";
    std::cin >> filename;

    std::ifstream ifile(filename);
    if (ifile.is_open()) {
        std::cout << "!! Ошибка: не удалось открыть файл.";
        return 1;
    }

    // handle commands

    ifile.close();
    return 0;
}