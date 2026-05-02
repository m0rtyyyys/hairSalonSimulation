#pragma once
#include <string>

void saveCSV(const std::string& filename,int iteration, int Q, int Qloss, float Ro, float L);
void createCSV(const std::string& filename, int workers, int seats, float probability);
void rewriteCSV(const std::string& filename, int workers, int seats, float probability);