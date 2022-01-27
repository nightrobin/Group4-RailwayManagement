#include "Ticket.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>


Ticket::Ticket()
{
    //ctor
}

Ticket::~Ticket()
{
    //dtor
}

string Ticket::dateCheck()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
    stoi(str);

    return str;
}
