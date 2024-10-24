#include <iostream> 
#include <vector> 
#include <cstring> 
#include <cstdlib>  // Для std::atof 

void print_usage() { 
    std::cout << "Usage: calculator -o operation operand1 operand2 operand3 [operand4] [operand5]\n"; 
    std::cout << "Supported operations:\n"; 
    std::cout << "  -o mul : multiply operands (requires 3 to 5 operands)\n"; 
    std::cout << "  -o div : divide first operand by the rest (requires 3 to 5 operands)\n"; 
} 

double multiply(const std::vector<double>& operands) { 
    double result = 1.0; 
    for (double operand : operands) 
        result *= operand; 
    return result; 
} 

double divide(const std::vector<double>& operands) { 
    double result = operands[0]; 
    for (size_t i = 1; i < operands.size(); ++i) { 
        if (operands[i] == 0) { 
            std::cerr << "Error: Division by zero is not allowed!\n"; 
            exit(1); 
        } 
        result /= operands[i]; 
    } 
    return result; 
} 

bool is_valid_number(const char* str) { 
    char* endptr; 
    std::strtod(str, &endptr);   
    return *endptr == '\0';      
} 

int main(int argc, char* argv[]) { 
    if (argc < 6 || argc > 8) { // Установлено от 6 до 8 аргументов (1 для -o, 1 для операции и от 3 до 5 операндов)
        print_usage(); 
        return 1; 
    } 

    if (std::strcmp(argv[1], "-o") != 0) { 
        std::cerr << "Error: Expected flag -o\n"; 
        print_usage(); 
        return 1; 
    } 

    std::string operation = argv[2]; 
    std::vector<double> operands; 

    for (int i = 3; i < argc; ++i) { 
        if (!is_valid_number(argv[i])) { 
            std::cerr << "Error: Invalid operand '" << argv[i] << "'\n"; 
            return 1; 
        } 

        operands.push_back(std::atof(argv[i])); 
    } 

    // Проверка на количество операндов
    if (operands.size() < 3 || operands.size() > 5) {
        std::cerr << "Error: Requires between 3 to 5 operands!\n";
        return 1; 
    }

    if (operation == "mul") { 
        std::cout << "Result: " << multiply(operands) << std::endl; 
    } else if (operation == "div") { 
        std::cout << "Result: " << divide(operands) << std::endl; 
    } else { 
        print_usage(); 
        return 1; 
    } 

    return 0; 
}
