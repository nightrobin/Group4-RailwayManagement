#include <iostream>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;



// Price function prototype
int ticketPrice(int origin, int destination);
// Date and Time to String prototype
string date();
// Hour for Timecheck prototype
int time();
// Check if Phone number is valid
bool phone(long long number);

int main()
{
    // Array for Stations
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

    int numOfTickets = 1;
    // Mini data base for bought tickets
    string ticket[100][4];
    for (int i = 0; i < 100; i++)
    {
        ticket[numOfTickets - 1][i] = "0";
    }


    //Main Loop
    while (true)
    {
        // random number for OTP
        // <ctime>
        srand (time(NULL));

        int main;
        int timecheck = time();
        cout << "\n=======================" << endl;
        cout << "LRT 2 RAILWAY" << endl;
        cout << "=======================" << endl;
        cout << date() << endl;
        if (timecheck >= 6 && timecheck <= 21)
        {
            cout << "Available for Service (OPEN)" << endl;
        }
        else
        {
            cout << "Not Available for Service (CLOSED)" << endl;
        }
        cout << "=======================" << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Exit Application" << endl;
        cout << "= ";
        cin >> main;

        if (main >= 1 && main <= 2)
        {
            if (main == 1)
            {

                // Login variable for logging out and going back to main menu
                int login = 0;
                while (login == 0)
                {

                    while(true)
                    {
                        // Login
                        long long number;
                        int otp;
                        // Variable for storing the number of digits in the variable 'number'
                        int digits = 1;
                        // Create random number from 1000 to 9999
                        int random = rand()%9999 + 1000;


                        cout << "\n=====================" << endl;
                        cout << "Login" << endl;
                        cout << "=====================" << endl;
                        cout << "Enter a 10 - Digit Phone Number: +63 ";
                        cin >> number;

                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }

                        if (phone(number))
                        {
                            // Pass
                        }
                        else
                        {
                            cout << "\n!!! Please input an 10 digit number !!!" << endl;
                            cout << "e.g. +63 9874562718" << endl;
                            continue;
                        }

                        cout << "OTP (verification code) will be sent on your phone" << endl;
                        // <windows.h>
                        Sleep(1000);

                        cout << "\n\nOTP Example: " << random << endl;
                        cout << "Input OTP: ";
                        cin >> otp;
                        if (otp == random)
                        {
                            cout << "\n" << "Success!!!" << endl;
                            break;
                        }
                        else if (cin.fail())
                        {
                            cout << "\nInvalid Input, Please try again" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }

                        else
                        {
                            cout << "\nIncorrect OTP, Please try again" << endl;
                        }

                    }

                    int x = 0;
                    while (x == 0)
                    {
                        x = 0;
                        int menu = 0;
                            // Menu
                            cout << "\n********************************************" << endl;
                            cout << "Railway Transportation (RECTO TO ANTIPOLO)" << endl;
                            cout << "********************************************" << endl;
                            cout << "[1] Buy a Ticket" << endl;
                            cout << "[2] View Ticket" << endl;
                            cout << "[3] Log out" << endl;
                            cout << "= ";
                            cin >> menu;

                            if (menu == 1)
                            {
                                while (true)
                                {
                                    // Buy a Ticket UI
                                    int buy;
                                    cout << "\n===================================" << endl;
                                    cout << "Buy a Ticket" << endl;
                                    cout << "===================================" << endl;
                                    cout << "[1] Buy Tickets" << endl;
                                    cout << "[2] View Train Transportation Fees" << endl;
                                    cout << "[3] Back" << endl;
                                    cout << "= ";
                                    cin >> buy;


                                    if (buy == 1)
                                    {

                                        int origin, destination;
                                        cout << "\nChoose Origin: " << endl;
                                        cout << "[1]  Recto" << endl;
                                        cout << "[2]  Legarda" << endl;
                                        cout << "[3]  Pureza" << endl;
                                        cout << "[4]  V. Mapa" << endl;
                                        cout << "[5]  J. Ruiz" << endl;
                                        cout << "[6]  Gilmore" << endl;
                                        cout << "[7]  Betty Go" << endl;
                                        cout << "[8]  Cubao" << endl;
                                        cout << "[9]  Anonas" << endl;
                                        cout << "[10] Katipunan" << endl;
                                        cout << "[11] Santolan" << endl;
                                        cout << "[12] Marikina" << endl;
                                        cout << "[13] Antipolo" << endl;
                                        cout << "= ";
                                        cin >> origin;

                                        cout << "\nChoose Destination: " << endl;
                                        cout << "[1]  Recto" << endl;
                                        cout << "[2]  Legarda" << endl;
                                        cout << "[3]  Pureza" << endl;
                                        cout << "[4]  V. Mapa" << endl;
                                        cout << "[5]  J. Ruiz" << endl;
                                        cout << "[6]  Gilmore" << endl;
                                        cout << "[7]  Betty Go" << endl;
                                        cout << "[8]  Cubao" << endl;
                                        cout << "[9]  Anonas" << endl;
                                        cout << "[10] Katipunan" << endl;
                                        cout << "[11] Santolan" << endl;
                                        cout << "[12] Marikina" << endl;
                                        cout << "[13] Antipolo" << endl;
                                        cout << "= ";
                                        int j = 0;
                                        while (j == 0)
                                        {
                                            cin >> destination;
                                            if (destination >= 1 && destination <= 13)
                                            {
                                                if (destination == origin)
                                                {
                                                    cout << "Invalid || the destination is the same as your origin" << endl;
                                                    cout << "= ";
                                                }
                                                else
                                                {
                                                    int price = ticketPrice(origin, destination);
                                                    int sen = 0;
                                                    while (sen == 0)
                                                    {


                                                        int discount;

                                                        cout << "\nDo you have a PWD (Person with Disability) ID or Senior ID" << endl;
                                                        cout << "[1] YES" << endl;
                                                        cout << "[2] NO" << endl;
                                                        cout << "= ";
                                                        cin >> discount;

                                                        if (discount == 1)
                                                        {
                                                            while (true)
                                                            {

                                                                int pwd;
                                                                cout << "\nThe original price is '" << price << "' and has been discounted by 20%" << endl;
                                                                pwd = price - (price * 0.2);
                                                                cout << "The ticket price is now: " << pwd << endl;
                                                                cout << "\nBuy the Ticket?" << endl;
                                                                cout << "[1] YES" << endl;
                                                                cout << "[2] NO" << endl;
                                                                cout << "= ";
                                                                int verify;
                                                                cin >> verify;

                                                                if(verify == 1)
                                                                {
                                                                    cout << "\n==========================================" << endl;
                                                                    cout << ">>> Ticket has been bought! Thank you! <<<" << endl;
                                                                    cout << "==========================================" << endl;
                                                                    if (ticket[0][0] == "0")
                                                                    {
                                                                        ticket[0][0] = station[origin-1];
                                                                        ticket[0][1] = station[destination-1];
                                                                        ticket[0][2] = "(PWD/SENIOR Discount) " + std::to_string(price);
                                                                        ticket[0][3] = date();
                                                                        sen += 1;
                                                                        j += 1;
                                                                        break;
                                                                    }
                                                                    /////////////////// this
                                                                    else
                                                                    {
                                                                        numOfTickets += 1;
                                                                        ticket[numOfTickets - 1][0] = station[origin-1];
                                                                        ticket[numOfTickets - 1][1] = station[destination-1];
                                                                        ticket[numOfTickets - 1][2] = "(PWD/SENIOR Discount) " + std::to_string(price);
                                                                        ticket[numOfTickets - 1][3] = date();
                                                                        sen += 1;
                                                                        j += 1;
                                                                        break;
                                                                    }

                                                                }
                                                                else if (verify == 2)
                                                                {
                                                                    sen += 1;
                                                                    j += 1;
                                                                    break;
                                                                }
                                                                else if (cin.fail())
                                                                {

                                                                    cin.clear();
                                                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                                    cout << "\nInvalid Input" << endl;
                                                                    cout << "= ";

                                                                }
                                                                else
                                                                {
                                                                    cout << "\nInvalid Input" << endl;
                                                                    cout << "= ";
                                                                }
                                                            }

                                                        }
                                                        else if (discount == 2)
                                                        {
                                                            while(true)
                                                            {

                                                                cout << "\nThe price of the ticket is: " << price << endl;
                                                                cout << "\nBuy the ticket?" << endl;
                                                                cout << "[1] YES" << endl;
                                                                cout << "[2] NO" << endl;
                                                                cout << "= ";
                                                                int verify;
                                                                cin >> verify;

                                                                if(verify == 1)
                                                                {
                                                                    cout << "\n==========================================" << endl;
                                                                    cout << ">>> Ticket has been bought! Thank you! <<<" << endl;
                                                                    cout << "==========================================" << endl;
                                                                    if (ticket[0][0] == "0")
                                                                    {
                                                                        ticket[0][0] = station[origin-1];
                                                                        ticket[0][1] = station[destination-1];
                                                                        ticket[0][2] = std::to_string(price);
                                                                        ticket[0][3] = date();
                                                                        sen += 1;
                                                                        j += 1;
                                                                        break;
                                                                    }
                                                                    /////////////////// this
                                                                    else
                                                                    {
                                                                        numOfTickets += 1;
                                                                        ticket[numOfTickets - 1][0] = station[origin-1];
                                                                        ticket[numOfTickets - 1][1] = station[destination-1];
                                                                        ticket[numOfTickets - 1][2] = std::to_string(price);
                                                                        ticket[numOfTickets - 1][3] = date();
                                                                        sen += 1;
                                                                        j += 1;
                                                                        break;
                                                                    }

                                                                }
                                                                else if (verify == 2)
                                                                {
                                                                    j += 1;
                                                                    sen += 1;
                                                                    break;
                                                                }
                                                                else if (cin.fail())
                                                                {
                                                                    cout << "Invalid Input\n" << endl;
                                                                    cin.clear();
                                                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                                }
                                                                else
                                                                {
                                                                    cout << "Invalid Input\n" << endl;
                                                                }


                                                            }

                                                        }
                                                        else if (cin.fail())
                                                            {
                                                                cout << "Invalid Input\n" << endl;
                                                                cin.clear();
                                                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                            }
                                                            else
                                                            {
                                                                cout << "Invalid Input\n" << endl;
                                                            }
                                                    }
                                                }

                                            }
                                            else
                                            {
                                                cout << "Invalid Input || Please input between 1 to 13" << endl;
                                                cout << "= ";
                                            }
                                        }

                                    }

                                    else if (buy == 2)
                                    {
                                        {
                                            cout << "\n== Approved Fares for LRT Line 2 with East Extension Stations ==\n" << endl;
                                            cout << "          Recto  Legarda Pureza V.Mapa J.Ruiz Gilmore Betty Go Cubao Anonas Katipunan Santolan Marikina Antipolo" << endl;
                                            cout << "\nRecto:    ";
                                            for (int i = 0; i < 13; i++)
                                            {
                                                // 6 spaces lol ignore dis
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
                                    }

                                    else if (buy == 3)
                                    {
                                        break;
                                    }


                                   else
                                    {
                                        cout << "Invalid Input";
                                    }
                                }

                            }

                            else if (menu == 2)
                            {
                                if (ticket[0][0] == "0")
                                {
                                    cout << "No ticket has been bought yet" << endl;
                                    Sleep(1000);
                                    cout << "Buy a ticket on option [1] Buy a Ticket" << endl;
                                    Sleep(2000);
                                    cout << "..." << endl;
                                    Sleep(1000);
                                    cout << "..." << endl;
                                }
                                else
                                {
                                    for (int i = 0; i < numOfTickets; i++)
                                    {
                                        cout << "\nTicket # " << i + 1 << endl;;

                                        cout << "Origin: ";
                                        cout << ticket[i][0] << endl;

                                        cout << "Destination: ";
                                        cout << ticket [i][1] << endl;

                                        cout << "Price: ";
                                        cout << ticket [i][2] << endl;

                                        cout << "Date: ";
                                        cout << ticket [i][3] << endl;

                                    }
                                }
                            }

                            else if (menu == 3)
                            {
                                while (true)
                                {
                                    char logout;
                                    cout << "\nAre you sure you want to log out?" << endl;
                                    cout << "Input y for yes and n for no" << endl;
                                    cin >> logout;
                                    if (logout == 'y' || logout == 'Y')
                                    {
                                        x += 1;
                                        login += 1;
                                        cout << "Logging out..." << endl;
                                        Sleep(1000);
                                        cout << "..." << endl;
                                        Sleep(1000);
                                        cout << "\n";
                                        break;
                                    }
                                    else if (logout == 'n' || logout == 'N')
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Invalid input" << endl;
                                    }
                                }
                            }


                        }




                    }
                }
                else if (main == 2)
                {
                    break;
                }
            }

            else if (cin.fail())
            {
                cout << "Invalid Input\n" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                cout << "Invalid Input\n" << endl;
            }

    }

    return 0;
}


int ticketPrice(int origin, int destination)
{
    int price;
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

    if (origin == 1)
    {
        price = Recto[destination - 1];
    }
    else if (origin == 2)
    {
        price = Legarda[destination - 1];
    }
    else if (origin == 3)
    {
        price = Pureza[destination - 1];
    }
    else if (origin == 4)
    {
        price = VMapa[destination - 1];
    }
    else if (origin == 5)
    {
        price = JRuiz[destination - 1];
    }
    else if (origin == 6)
    {
        price = Gilmore[destination - 1];
    }
    else if (origin == 7)
    {
        price = BettyGo[destination - 1];
    }
    else if (origin == 8)
    {
        price = Cubao[destination - 1];
    }
    else if (origin == 9)
    {
        price = Anonas[destination - 1];
    }
    else if (origin == 10)
    {
        price = Katipunan[destination - 1];
    }
    else if (origin == 11)
    {
        price = Santolan[destination - 1];
    }
    else if (origin == 12)
    {
        price = Marikina[destination - 1];
    }
    else if (origin == 13)
    {
        price = Antipolo[destination - 1];
    }


    return price;
}

string date()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    ostringstream oss;
    // <iomanip>
    oss << put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
    stoi(str);

    return str;
}

int time()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%H");
    string str = oss.str();
    int hour;
    istringstream(str) >> hour;

    return hour;
}

bool phone(long long number)
{
    bool valid;
    int digits = 0;
    while (number > 0)
    {
        digits++;
        number = number / 10;
    }

    if (digits == 10)
    {
        valid = true;
    }
    else
    {
        valid = false;
    }

    return valid;

}


