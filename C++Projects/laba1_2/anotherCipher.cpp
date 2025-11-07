#include "anotherCipher.h"
#include <iostream>
#include <vector>

// Функция для шифрования текста
std::string encrypt(const std::string& plaintext, int columns) {
    int rows = (plaintext.length() + columns - 1) / columns;
    std::vector<std::vector<char>> table(rows, std::vector<char>(columns));
    int k = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (k < plaintext.length()) {
                table[i][j] = plaintext[k++];
            } else {
                table[i][j] = ' '; // Заполняем пробелами
            }
        }
    }

    std::string ciphertext = "";
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            ciphertext += table[i][j];
        }
    }
    return ciphertext;
}

// Функция для дешифрования текста
std::string decrypt(const std::string& ciphertext, int columns) {
    int rows = (ciphertext.length() + columns - 1) / columns;
    std::vector<std::vector<char>> table(rows, std::vector<char>(columns));
    int k = 0;
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            table[i][j] = ciphertext[k++];
        }
    }

    std::string plaintext = "";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            plaintext += table[i][j];
        }
    }
    return plaintext;
}