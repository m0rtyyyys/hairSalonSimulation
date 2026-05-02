#pragma once
#include <vector>
#include "hairDresser/hairDresser.hpp"

class HairSalon{

    private:
    int seats;
    int maxSeats;
    bool newCustomer;
    int maxWorkers;
    std::vector<HairDresser> workers;
    int Qloss;
    public:
    HairSalon(int seats, int maxWorkers);
    int get_freeSeats();
    void set_freeSeats(int seats);
    bool get_newCustomer();
    void set_newCustomer(bool status);
    HairDresser& get_worker(size_t idx);
    void print_worker(int idx);
    int get_QLoss();
    void set_Qloss(int num);
    void event_newCustomer();
    void event_seat();
};