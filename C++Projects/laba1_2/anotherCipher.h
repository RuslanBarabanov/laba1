#pragma once

#include <string>
#include <vector>

std::string encrypt(const std::string& plaintext, int columns);
std::string decrypt(const std::string& ciphertext, int columns);