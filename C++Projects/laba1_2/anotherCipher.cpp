#include "anotherCipher.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

int getValidKey(int columns) {
    if (columns <= 0) {
        throw cipher_error("Ошибка: Количество столбцов должно быть положительным числом");
    }
    if (columns > 100) {
        throw cipher_error("Ошибка: Слишком большое количество столбцов (максимум 100)");
    }
    return columns;
}

std::string getValidOpenText(const std::string& text) {
    if (text.empty()) {
        throw cipher_error("Ошибка: Открытый текст не может быть пустым");
    }

    bool has_printable = false;
    for (char c : text) {
        if (std::isprint(c) && c != ' ') {
            has_printable = true;
            break;
        }
    }
    
    if (!has_printable) {
        throw cipher_error("Ошибка: Открытый текст должен содержать хотя бы один непробельный символ");
    }
    
    return text;
}

// Валидация зашифрованного текста
std::string getValidCipherText(const std::string& text) {
    if (text.empty()) {
        throw cipher_error("Ошибка: Зашифрованный текст не может быть пустым");
    }
    
    for (char c : text) {
        if (!std::isprint(c)) {
            throw cipher_error("Ошибка: Зашифрованный текст содержит недопустимые символы");
        }
    }
    
    return text;
}

std::string encrypt(const std::string& plaintext, int columns) {
    int valid_columns = getValidKey(columns);
    std::string valid_text = getValidOpenText(plaintext);
    
    int rows = (valid_text.length() + valid_columns - 1) / valid_columns;
    std::vector<std::vector<char>> table(rows, std::vector<char>(valid_columns, ' '));
    int k = 0;
    
    try {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < valid_columns; ++j) {
                if (k < valid_text.length()) {
                    table[i][j] = valid_text[k++];
                }
 
            }
        }


        std::string ciphertext = "";
        for (int j = valid_columns - 1; j >= 0; --j) {
            for (int i = 0; i < rows; ++i) {
                ciphertext += table[i][j];
            }
        }
        return ciphertext;
    } catch (const std::exception& e) {
        throw cipher_error(std::string("Ошибка при шифровании: ") + e.what());
    }
}

std::string decrypt(const std::string& ciphertext, int columns) {

    int valid_columns = getValidKey(columns);
    std::string valid_text = getValidCipherText(ciphertext);
    
    int rows = (valid_text.length() + valid_columns - 1) / valid_columns;
    
    if (rows * valid_columns != valid_text.length()) {
        throw cipher_error("Ошибка: Некорректная длина зашифрованного текста для данного количества столбцов");
    }
    
    std::vector<std::vector<char>> table(rows, std::vector<char>(valid_columns, ' '));
    int k = 0;
    
    try {
        for (int j = valid_columns - 1; j >= 0; --j) {
            for (int i = 0; i < rows; ++i) {
                table[i][j] = valid_text[k++];
            }
        }

        std::string plaintext = "";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < valid_columns; ++j) {
                plaintext += table[i][j];
            }
        }
        return plaintext;
    } catch (const std::exception& e) {
        throw cipher_error(std::string("Ошибка при дешифровании: ") + e.what());
    }
}