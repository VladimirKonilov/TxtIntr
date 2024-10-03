import sys
import argparse

def summa(operands):
    return sum(operands)

def subtraction(operands):
    return operands[0] - sum(operands[1:])

def multiplication(operands):
    result = 1
    for number in operands:
        result *= number
    return result

def division(operands):
    if len(operands) < 2:
        raise ValueError("Для деления необходимо как минимум два операнда.")
    result = operands[0]
    for number in operands[1:]:
        if number == 0:
            raise ValueError("Деление на ноль невозможно.")
        result /= number
    return result

def main():
    # Создание парсера аргументов
    parser = argparse.ArgumentParser(description="Простой калькулятор для выполнения арифметических операций.")
    parser.add_argument('-o', '--operation', type=str, required=True, 
                        choices=['summa', 'subtraction', 'multiplication', 'division'],
                        help="Операция для выполнения: summa, subtraction, multiplication, division.")
    parser.add_argument('operands', type=float, nargs='+', help="Операнды для выполнения операции.")

    # Получение аргументов
    args = parser.parse_args()

    # Выполнение выбранной операции
    if args.operation == 'summa':
        result = summa(args.operands)
    elif args.operation == 'subtraction':
        result = subtraction(args.operands)
    elif args.operation == 'multiplication':
        result = multiplication(args.operands)
    elif args.operation == 'division':
        result = division(args.operands)

    print("Результат:", result)

if __name__ == "__main__":
    main()
