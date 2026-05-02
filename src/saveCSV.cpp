#include "saveCSV/saveCSV.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void saveCSV(const std::string& filename, int iteration, int Q, int Qloss, float Ro, float L)
{
    fs::path outDir = "out";
    fs::path filePath = outDir / filename;
    std::ofstream file(filePath, std::ios::app);
    if(file.is_open())
    {
        file << iteration << "," << Q << "," << Qloss << "," << Ro << "," << L << "\n";
    }
    file.close();
    std::cout << "Data saved at file: " << filename << std::endl;
}

void createCSV(const std::string& filename, int workers, int seats, float probability)
{
    fs::path outDir = "out";
    fs::path filePath = outDir / filename;
    try {
        if(!fs::exists(outDir))
        {
            fs::create_directories(outDir);
        }
        std::ofstream file(filePath);
        // if(file.is_open())
        // {
        //     file << "workers,seats,probability" << "\n";
        //     file << seats << "," << workers << "," << probability << "\n\n";
        //     file << "iteration,Q,Qloss,Ro,L" << "\n";
        // }
        // file.close();
        // std::cout << "Data saved at file: " << filename << std::endl;
    }
    catch (const fs::filesystem_error& e) {
        std::cout << "File system error: " << e.what() << std::endl;
    }
}

void rewriteCSV(const std::string& filename, int workers, int seats, float probability)
{
    fs::path outDir = "out";
    fs::path filePath = outDir / filename;
    try {
        if(!fs::exists(outDir))
        {
            fs::create_directories(outDir);
        }
        std::ofstream file(filePath, std::ios::app);
        if(file.is_open())
        {
            file << "\n\n" << "workers,seats,probability" << "\n";
            file << workers << "," << seats << "," << probability << "\n";
            file << "iteration,Q,Qloss,Ro,L" << "\n";
        }
        file.close();
        std::cout << "Data saved at file: " << filename << std::endl;
    }
    catch (const fs::filesystem_error& e) {
        std::cout << "File system error: " << e.what() << std::endl;
    }
}
