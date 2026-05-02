#pragma once
#include <string>

extern int maxWorkTime;

class HairDresser
{
private:
    std::string name;
    bool isTaken;
    int workTime;
    int totalWorkTime;
    int Q;
public:
    HairDresser(std::string newName, bool status, int time): name(newName), isTaken(status), workTime(time), Q(0) {};
    HairDresser(): name("John Doe"), isTaken(false), workTime(0), Q(0) {};
    HairDresser(std::string newName): name(newName), isTaken(false), workTime(0), Q(0), totalWorkTime(0) {}; // Используемый конструтор
    ~HairDresser();
    bool get_isTaken();
    void set_isTaken(bool change);
    std::string get_name();
    void set_name(std::string newName);
    int get_workTime();
    void set_workTime(int time);
    int get_Q();
    int get_totalWorkTime();
    void printStatus();
    void update_Work();
};