#include <iostream>
#include <ostream>
#include <random>
#include "hairSalon/hairSalon.hpp"
#include "hairDresser/hairDresser.hpp"
#include "saveCSV/saveCSV.hpp"

int maxWorkTime = 15; // Время, затрачиваемое на стрижку одного клиента
int maxWorkers = 1; // Количество парикмахеров
int seats = 0; // Места в зале ожидания
int workDay = 480; // Продолжительность рабочего дня
float probability = 0.1; // Вероятность появления нового клиента каждую единицу времени
int totalQ = 0;
float Ro = 0;
float totalLine = 0;

int main() {
    createCSV("report.csv", maxWorkers, seats, probability);

    int totalIterations = 30;

    //Распределение гаусса для обработки шанса прихода клиента
    std::random_device rd;
    std::mt19937 gen(rd());
    

    std::cout << "Enter num of iterations: ";
    //std::cin >> totalIterations;
    // for(maxWorkers = 1;maxWorkers <= 5; maxWorkers++)
    // {   
    //     for(seats = 0; seats <= 10; seats++)
    //     {
    //         for(probability = 0.1000000; probability <= 0.55; probability = probability + 0.1000000)
    //         {
                std::bernoulli_distribution chance(probability);
                //rewriteCSV("report.csv", maxWorkers, seats, probability);
    // Запуск заданного числа итераций
    for(int i = 1; i <= totalIterations; i++)
    {
        HairSalon BashkaSaloon(seats, maxWorkers);
        totalQ = 0;
        Ro = 0;
        totalLine = 0;

        // Обработка рабочего дня
        for(int i = 0; i < workDay; i++)
        {
            // Генерация клиента
            if(chance(gen))
            {
                BashkaSaloon.set_newCustomer(true);
            }

            // Обновление статуса мастера
            for(int i = 0; i < maxWorkers; i++)
            {
                BashkaSaloon.get_worker(i).update_Work();
            }

            // Сначала идет обработка нового клиента (условно считаем, что обслуживаем ожидавшего в очереди, а новый просто занял его место)
            BashkaSaloon.event_newCustomer();
            BashkaSaloon.event_seat();

            // Выводим информацию о каждом работнике (каждый раз в ед. рабочего времени)
            for(int i = 0; i < maxWorkers; i++)
            {
                BashkaSaloon.print_worker(i);
            }

            std::cout << "Free Seats: " << BashkaSaloon.get_freeSeats() << "\tAbandoned: " << BashkaSaloon.get_QLoss() << std::endl;

            totalLine += seats - BashkaSaloon.get_freeSeats();
        }

        // Выводим информацию о статистике каждого парикмахера
        for(int i = 0; i < maxWorkers; i++)
        {
            std::cout << "Worker '" << BashkaSaloon.get_worker(i).get_name() << "' served: " << BashkaSaloon.get_worker(i).get_Q() << std::endl;
            totalQ += BashkaSaloon.get_worker(i).get_Q(); // Клиенты, которых не успели обслужить до конца рабочего дня, не засчитываются
        }

        // Доля занятости каждого парикмахера от продолжительности рабочего дня
        for(int i = 0; i < maxWorkers; i++)
        {   
            Ro += float(BashkaSaloon.get_worker(i).get_totalWorkTime())/workDay;
        }

        // Вывод информации о дне
        std::cout << "Total served customers: " << totalQ << std::endl;
        std::cout << "Average workload of masters: " << Ro/maxWorkers << std::endl;
        std::cout << "Loosed customers: " << BashkaSaloon.get_QLoss() << std::endl;
        std::cout << "Average line: " << totalLine/workDay << std::endl;

        saveCSV("report.csv", i, totalQ, BashkaSaloon.get_QLoss(), Ro/maxWorkers, totalLine/workDay);
           // }
       // }
    //}
    }
    return 0;
}