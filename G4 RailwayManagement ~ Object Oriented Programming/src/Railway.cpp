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
    string station[13] {"Recto" ,"Legarda" ,"Pureza" , "V Mapa", "J Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};

    // Array for Prices
    int Recto[13] =     {0, 15, 15, 15, 20, 20, 20, 20, 25, 25, 25, 30, 30};
    int Legarda[13] =   {15, 0, 15, 15, 15, 20, 20, 20, 20, 25, 25, 25, 30};
    int Pureza[13] =    {15, 15, 0, 15, 15, 15, 20, 20, 20, 20, 25, 25, 30};
    int VMapa[13] =     {15, 15, 15, 0, 15, 15, 15, 20, 20, 20, 25, 25, 25};
    int JRuiz[13] =     {20, 15, 15, 15, 0, 15, 15, 15, 20, 20, 20, 25, 25};
    int Gilmore[13] =   {20, 20, 15, 15, 15, 0, 15, 15, 15, 20, 20, 20, 25};
    int BettyGo[13] =   {20, 20, 20, 15, 15, 15, 0, 15, 15, 15, 20, 20, 25};
    int Cubao[13] =     {20, 20, 20, 20, 15, 15, 15, 0, 15, 15, 15, 20, 20};
    int Anonas[13] =    {25, 20, 20, 20, 20, 15, 15, 15, 0, 15, 15, 20, 20};
    int Katipunan[13] = {25, 25, 20, 20, 20, 20, 15, 15, 15, 0, 15, 15, 20};
    int Santolan[13] =  {25, 25, 25, 25, 20, 20, 20, 15, 15, 15, 0, 15, 15};
    int Marikina[13] =  {30, 25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15};
    int Antipolo[13] =  {30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 15, 15, 0};


                                    
                                        
                                            cout << "\n== Approved Fares for LRT Line 2 with East Extension Stations ==\n" << endl;
                                            cout << "          Recto  Legarda Pureza V.Mapa J.Ruiz Gilmore Betty Go Cubao Anonas Katipunan Santolan Marikina Antipolo" << endl;
                                            cout << "\nRecto:    ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                
                                                cout << "   " << Recto[i] << "   ";
                                            }
                                            cout << "\nLegarda:  ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Legarda[i] << "   ";
                                            }
                                            cout << "\nPureza:   ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Pureza[i] << "   ";
                                            }
                                                cout << "\nV. Mapa:  ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << VMapa[i] << "   ";
                                            }
                                            cout << "\nJ. Ruiz:  ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << JRuiz[i] << "   ";
                                            }
                                            cout << "\nGilmore:  ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Gilmore[i] << "   ";
                                            }
                                            cout << "\nBetty Go: ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << BettyGo[i] << "   ";
                                            }
                                            cout << "\nCubao:    ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Cubao[i] << "   ";
                                            }
                                            cout << "\nAnonas:   ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Anonas[i] << "   ";
                                            }
                                            cout << "\nKatipunan:";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Katipunan[i] << "   ";
                                            }
                                            cout << "\nSantolan: ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Santolan[i] << "   ";
                                            }
                                            cout << "\nMarikina: ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Marikina[i] << "   ";
                                            }
                                            cout << "\nAntipolo: ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                cout << "   " << Antipolo[i] << "   ";
                                            }
                                            cout << "\n\n";


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
