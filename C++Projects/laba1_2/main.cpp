#include <iostream>
#include <string>
#include "anotherCipher.h"

int main() {
    int choice;
    std::string text;
    int num_cols;

    // Приветственное сообщение
    std::cout << "Добро пожаловать в программу шифрования табличной маршрутной перестановкой!" << std::endl;

    do {
        // Вывод меню
        std::cout << "\nВыберите действие:" << std::endl;
        std::cout << "1. Шифрование текста" << std::endl;
        std::cout << "2. Дешифрование текста" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(); // Очищаем буфер после ввода числа

        switch (choice) {
            case 1: {
                // Шифрование
                std::cout << "Введите текст для шифрования: ";
                std::getline(std::cin, text);
                std::cout << "Введите количество столбцов: ";
                std::cin >> num_cols;
                std::cin.ignore();

                std::string ciphertext = encrypt(text, num_cols);
                std::cout << "Зашифрованный текст: " << ciphertext << std::endl;
                break;
            }
            case 2: {
                // Дешифрование
                std::cout << "Введите текст для дешифрования: ";
                std::getline(std::cin, text);
                std::cout << "Введите количество столбцов: ";
                std::cin >> num_cols;
                std::cin.ignore();

                std::string decrypted_text = decrypt(text, num_cols);
                std::cout << "Расшифрованный текст: " << decrypted_text << std::endl;
                break;
            }
            case 0: {
                // Выход
                std::cout << "До свидания!" << std::endl;
                break;
            }
            default: {
                // Некорректный ввод
                std::cout << "Некорректный выбор. Пожалуйста, попробуйте еще раз." << std::endl;
            }
        }
    } while (choice != 0);

    return 0;
}