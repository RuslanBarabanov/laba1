#pragma once

#include <string>
#include <vector>
#include <stdexcept>

// Класс исключения для шифра
class cipher_error : public std::invalid_argument {
public:
    explicit cipher_error(const std::string& what_arg) : 
        std::invalid_argument(what_arg) {}
    explicit cipher_error(const char* what_arg) : 
        std::invalid_argument(what_arg) {}
};

std::string encrypt(const std::string& plaintext, int columns);
std::string decrypt(const std::string& ciphertext, int columns);

// Вспомогательные функции для валидации
int getValidKey(int columns);
std::string getValidOpenText(const std::string& text);
std::string getValidCipherText(const std::string& text);