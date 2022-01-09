#include "Railway.h"
#include "Ticket.h"
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

Railway::Railway()
{
    //ctor
}

Railway::~Railway()
{
    //dtor
}

// Pangoptimize na Methods/Functions (Pinapaikli mga codesxszx)
int Railway::checkNumber(long long number)
{
    int valid;
    int digits = 0;

    // Punta sa admin
    if (number == 1234)
    {
        valid = 2;
    }

    while (number > 0)
    {
        digits++;
        number = number / 10;
    }

    // Punta sa user
    if (digits == 10)
    {
        valid = 1;
    }

    return valid;
}

void Railway::defaultFail()
{
    cout << "\nInvalid Input" << endl;
    // Sleep sha 1 second kapagod e
    Sleep(1000);
    system("cls");
}

void Railway::inputFail()
{
    // Pag nagerror dahil don sa naginput ng string sa integer wew aus k vakla
    cout << "\nInvalid Input" << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Sleep(1000);
    system("cls");
}

// Core Methods

// Harlene
void Railway::User()
{
}

// Christel
void Railway::buyTicket()
{

}

// Jahnielle
void Railway::viewTicket()
{

}

// Matthew
void Railway::viewFee()
{


}

// Kenneth, Anny
void Railway::Admin()
{

}

// Wilton
void Railway::viewSale()
{

}

// Frits
void Railway::changeFee()
{

}
