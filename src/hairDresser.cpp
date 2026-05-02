#include "hairDresser/hairDresser.hpp"

bool HairDresser::get_isTaken()
{
    return isTaken;
}

void HairDresser::set_isTaken(bool change)
{
    isTaken = change;
}

std::string HairDresser::get_name()
{
    return name;
}

void HairDresser::set_name(std::string newName)
{
    name = newName;
}

int HairDresser::get_workTime()
{
    return workTime;
}

void HairDresser::set_workTime(int time)
{
    workTime = time;
}

int HairDresser::get_Q()
{
    return Q;
}

int HairDresser::get_totalWorkTime()
{
    return totalWorkTime;
}

// Отвечает за занятость и освобождение мастера
void HairDresser::update_Work()
{
    if(isTaken == true)
    {
        workTime++;
        totalWorkTime++;
        
    }
    if(workTime >= 15)
    {
        isTaken = false;
        Q++;
        workTime = 0;
    }
}

HairDresser::~HairDresser() {}
