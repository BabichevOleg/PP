#include <fstream>
#include <vector>
#include <iostream>
#include <filesystem>
#include <string>
#include <sstream>
#include <chrono>
#include <Windows.h>
#include <cstdlib>




std::vector<std::vector<int>> generateMatrix(size_t size) {
    std::vector<std::vector<int>> result(size, std::vector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = std::rand() % 1000;
        }
    }
    return result;
}


void saveMatrix(std::string name, const std::vector<std::vector<int>>& matrix) {
    std::ofstream file(name);

    for (const auto& row : matrix) {
        for (int num : row) {
            file << num << " ";
        }
        file << std::endl;
    }

    file.close();
}


std::vector<std::vector<int>> multiplyMatrix(const std::vector<std::vector<int>>& first, const std::vector<std::vector<int>>& second, int size) {
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    return result;
}


int main() {
    std::vector<int> sizeList = { 100, 250, 500, 750, 1000 };

    std::ofstream file("../data/Avarage time");

    for (int size : sizeList) {
        auto duration = std::chrono::milliseconds(0);
        for (int i = 0; i < 10; ++i) {
            std::vector<std::vector<int>> first = generateMatrix(size);
            std::vector<std::vector<int>> second = generateMatrix(size);
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<std::vector<int>> result = multiplyMatrix(first, second, size);
            auto end = std::chrono::high_resolution_clock::now();
            auto currDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            duration += currDuration;

            if (i == 9) {
                std::string firstMatrixName = "../data/firstMatrix_" + std::to_string(size) + ".txt";
                saveMatrix(firstMatrixName.c_str(), first);
                std::string secondMatrixName = "../data/secondMatrix_" + std::to_string(size) + ".txt";
                saveMatrix(secondMatrixName.c_str(), second);
                std::string resultdMatrixName = "../data/resultMatrix_" + std::to_string(size) + ".txt";
                saveMatrix(resultdMatrixName.c_str(), result);
            }
        }
        auto avgDuration = duration / 10;
        file << size << " - " << avgDuration.count() << std::endl;
    }
    file.close();


    return 0;
}