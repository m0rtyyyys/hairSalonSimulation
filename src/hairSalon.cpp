#include "hairSalon/hairSalon.hpp"
#include <random>
#include <iostream>

//Имена работников
std::string names[20] = {"James", "Robert", "Donald", "Michael", "William", 
    "David", "Richard", "Joseph", "Thomas", "Charles", 
    "Emma", "Olivia", "Ava", "Sophia", "Isabella", 
    "Mia", "Charlotte", "Amelia", "Harper", "Evelyn"};
//Фамилии работников
std::string surnames[20] = {"Smith", "Johnson", "Williams", "Brown", "Jones", 
    "Garcia", "Miller", "Davis", "Rodriguez", "Martinez", 
    "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", 
    "Thomas", "Taylor", "Moore", "Jackson", "White"};

//Конструктор класса со случайной генерацией имени
HairSalon::HairSalon(int seats, int mWorkers): seats(seats), maxWorkers(mWorkers), newCustomer(false), Qloss(0), maxSeats(seats)
{ 
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dist(0, 19);
    for(int i = 0; i < maxWorkers; i++)
    {
        workers.emplace_back(names[dist(gen)] + " " + surnames[dist(gen)]);
    }
}

int HairSalon::get_freeSeats()
{
    return seats;
}

void HairSalon::set_freeSeats(int s)
{
    seats = s;
}

bool HairSalon::get_newCustomer()
{
    return newCustomer;
}

void HairSalon::set_newCustomer(bool status)
{
    newCustomer = status;
}

HairDresser& HairSalon::get_worker(size_t idx)
{
    return workers.at(idx);
}

//Вывод информации о работнике
void HairSalon::print_worker(int idx)
{
    if(idx > maxWorkers)
    {
        return;
    }
    std::string workingStatus;
    if(workers[idx].get_isTaken() == true)
    {
        workingStatus = "work";
    }
    else{
        workingStatus = "rest";
    }
    std::cout << "Employee's name: " << workers[idx].get_name() << "\tWorking status: " << workingStatus << "\tWorking time: " << workers[idx].get_workTime() << 
    "\t Total working time: " << workers[idx].get_totalWorkTime() << std::endl;
}

int HairSalon::get_QLoss()
{
    return Qloss;
}

void HairSalon::set_Qloss(int num)
{
    Qloss = num;
}

//Симуляция появления клиента
void HairSalon::event_newCustomer()
{
    if(newCustomer == false)
    {
        return; //Пропускаем при отсутсвии
    }
    for(int i = 0; i < maxWorkers; i++)
    {
        if(workers[i].get_isTaken() == false)
        {
            workers[i].set_isTaken(true);
            newCustomer = false;
            return;
        }
    }
    if(seats > 0)
    {
        seats--;
        newCustomer = false;
    }
    else
    {
        Qloss++;
        newCustomer = false;
    }
}

//Освобождение места в очереди
void HairSalon::event_seat()
{
    if(seats == maxSeats)
    {
        return;
    }
    for(int i = 0; i < maxWorkers; i++)
    {
        if(workers[i].get_isTaken() == false)
        {
            workers[i].set_isTaken(true);
            seats++;
            return;
        }
    }
}

