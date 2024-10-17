#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>

// Функция для вывода справки
void printHelp() {
    std::cout << "Использование: calculator -o операция операнд1 операнд2 [операнд3] [операнд4]\n";
    std::cout << "Операции:\n";
    std::cout << "  summa    : Вычисляет сумму операндов\n";
    std::cout << "  minus    : Вычисляет разность операций\n";
    std::cout << "  multiply  : Вычисляет произведение операндов\n";
    std::cout << "  divide    : Вычисляет деление операндов\n";
}

// Функция для выполнения операции
double performOperation(const std::string& operation, const std::vector<double>& operands) {
    if (operation == "summa") {
        double result = 0;
        for (double num : operands) {
            result += num;
        }
        return result;
    } else if (operation == "minus") {
        if (operands.empty()) {
            throw std::invalid_argument("Ошибка: Нет операндов для вычитания");
        }
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); i++) {
            result -= operands[i];
        }
        return result;
    } else if (operation == "multiply") {
        double result = 1;
        for (double num : operands) {
            result *= num;
        }
        return result;
    } else if (operation == "divide") {
        if (operands.empty()) {
            throw std::invalid_argument("Ошибка: Нет операндов для деления");
        }
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); i++) {
            if (operands[i] == 0) {
                throw std::runtime_error("Ошибка: Деление на ноль");
            }
            result /= operands[i];
        }
        return result;
    }
    throw std::invalid_argument("Ошибка: Неизвестная операция");
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printHelp();
        return 1;
    }

    std::string operation;
    if (std::string(argv[1]) == "-o" || std::string(argv[1]) == "--operation") {
        operation = argv[2];
    } else {
        printHelp();
        return 1;
    }

    std::vector<double> operands;
    for (int i = 3; i < argc; i++) {
        operands.push_back(std::strtod(argv[i], nullptr));
    }

    try {
        double result = performOperation(operation, operands);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
