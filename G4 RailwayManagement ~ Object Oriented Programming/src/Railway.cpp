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

int Railway::PWDCheck(int quantity) // function for discounts
{
    char PWDchoice = 0;
    int PWD = 0;
    cout << "\nDo you have PWD/Senior IDs?" << endl;
    cout << "Y if yes or N if no" << endl;
    cout << "==============================" << endl;
    cout << "= ";
    cin >> PWDchoice;
    system("cls");
    if(PWDchoice == 'Y' || PWDchoice == 'y')
    {
        while(true)
        {

            if (quantity == 1)
            {
                PWD = 1;
                return PWD;
                break;
            }

            cout << "\nHow many PWD/Senior? ( ? / " << quantity << " )" << endl;
            cout << "= ";
            cin >> PWD;
            system("cls");
            if(PWD == 0)
            {
                char valid;
                cout << "You have inputted \"0\"" << endl;
                cout << "Are you sure you want to go back to normal payment?" << endl;
                cout << "Y for Yes or N for No" << endl;
                cin >> valid;
                system("cls");
                if (valid == 'Y' || valid == 'y')
                {
                    break;
                }
                else if (valid == 'N' || valid == 'n')
                {
                    continue;
                }
                else if(cin.fail())
                {
                    inputFail();
                }
                else
                {
                    defaultFail();
                }
            }
            else if (PWD >= 1 && PWD <= quantity)
            {
                return PWD;
            }
            else if (cin.fail())
            {
                inputFail();
            }
            else
            {
                defaultFail();
            }
        }
    }
    else if(PWDchoice == 'N' || PWDchoice == 'n')
    {
        // Ok babye salamt sa lahat
    }
    else if (cin.fail())
    {
        inputFail();
    }
    else
    {
        defaultFail();
    }

    PWD = 0;
    return PWD;
}

// Core Methods

// Harlene
void Railway::User(long long number)
{
    while (true)
    {
        int user = -1;
        cout << "USER" << endl;
        cout << "====" << endl;
        cout << "[1] Buy a Ticket" << endl;
        cout << "[2] View Tickets Bought" << endl;
        cout << "[3] View Tickets Fees" << endl;
        cout << "[0] Logout" << endl;
        cout << "= ";
        cin >> user;
        system("cls");
        if(user == 1)
        {
            buyTicket(number);
        }
        else if(user == 2)
        {
            viewTicket(number);
        }
        else if(user == 3)
        {
            viewFee();
        }
        else if (cin.fail())
        {
            inputFail();
        }
        else if(user == 0)
        {
            break;
        }
        else
        {
            cout << "\nInvalid Input" << endl;
            Sleep(1000);
            system("cls");
        }
    }
}

// Christel
void Railway::buyTicket(long long number) // get da cellphone number kase magagamit sha soon for viewSales and many more mwaha
{
    int ticketquantity;
//    int totalnoofticket;
    int price; // presyo ng ticket individually
    int displaytotalprice = 0; // total price ng mga biniling tickets ni user (display kase ididisplay sha or ooutput mamaya basta di ako marunog magvariable)
                          // e.g. tatlong recto to legarda
                          // displaytotalprice will be 15+15+15 = 45


    // Start muna sa Origin and Destination bago ticketquantity para di magulo mwehe
    int origin, destination;
    string date; // later gagamitin para i-store yung date kung kelan nabili yung ticket

    while (true) // Habang nagiinvalid yung input mauulit ng mauulit yung part na to hanggang sa pumasa
    {
        cout << "Choose Origin: " << endl;
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
        cin >> origin; // input origin
        system("cls");
        if (origin <= 13 && origin >= 1)
        {
            break; // pass
        }
        else if (cin.fail()) // if ever letra/string/char ininput ni user
        {
            inputFail();
            continue; // ulit yung loop from the top
        }
        else
        {
            defaultFail();
            continue; // ulit yung loop from the top
        }
    }

    while(true) // loop incase of same origin and destination
    {
        while(true)
        {
            cout << "Choose Destination: " << endl;
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
            cin >> destination;
            system("cls");
            if (destination <= 13 && destination >= 1)
            {
                break;
            }
            else if (cin.fail())
            {
                inputFail();
                continue;
            }
            else
            {
                defaultFail();
                continue;
            }
        }

        if (origin == destination) // if parehas ng origin and destination (e.g. Recto to Recto wtf) uulit yung loop mapupunta ule sa input destination
        {
            cout << "\nError: The Origin and Destination are the same!" << endl;
            Sleep(2000);
            system("cls");
        }
        else
            break;
    }

    price = Fee.stationFeeGet(origin, destination); // naglagay me bagong variable which is two dimensional na array stationsFee pangalan nasa ticket.h
                                                    // nakastore dito mga presyo ng tickets
    date = tickets[usedTickets].dateCheck(); // get da date ngayon

while (true) // Get da Quantity
{
    cout << "\nHow many tickets would you like to buy?" << endl;
    cin >> ticketquantity;
    // totalnoofticket = ticketquantity; // no need for totalnoofticket since may usedTickets naman from Railway.h
    // cout << "\nYour total number of ticket is" << " " << totalnoofticket << endl;

        system("cls");
        if (ticketquantity >= 1 && ticketquantity <= ticketLimit)
        {
            break;
        }
        else if (cin.fail())
        {
            inputFail();
        }
        else
        {
            defaultFail();
        }
}


    int PWD = PWDCheck(ticketquantity); // PWDCheck function ginawa ko asa taas sa baba ng inputFail na function
                                        // Punta nalang don tas eexplain ko mga nandon

    int discount = (price * 0.2) * PWD; // (price * 0.2) is yung formula ng discount
                                        // PWD is ilang tickets and PWD discounted

<<<<<<< Updated upstream
=======
    for (int x = 0; x < ticketquantity; x++)
    {
        displaytotalprice = Fee.stationFeeGet(origin, destination) * ticketquantity; // get the total price of the tickets
                                                                                     // stationFeeGet is where we get the prices of the ticket based on the origin and destination
    }

    displaytotalprice -= discount; // total price minus yung discount

    while (true)
    {
        char response;

        cout << "Origin: " << station[origin-1] << endl;
        cout << "Destination: " << station[destination-1] << endl;
        cout << "Quantity: " << ticketquantity << endl;
        cout << "========================================" << endl;
        cout << "The price is: " << displaytotalprice << endl;
        cout << "\nAre you sure you want to buy the tickets?" << endl;
        cout << "Y if Yes | N for No" << endl;
        cin >> response;
        system("cls");

        if (response == 'Y' || response == 'y') // yung "are you sure" chuchu
        {
            for (int i = 0; i < ticketquantity; i++) //  pag yes mapupunta na sa mini database naten. icoconfirm na at ilalagay yung mga info na ininput ni user sa mga variables/attributes
            {
                tickets[usedTickets].numberSet(number);
                tickets[usedTickets].intOriginSet(origin);
                tickets[usedTickets].intDestinationSet(destination);
                tickets[usedTickets].originSet(station[origin-1]);
                tickets[usedTickets].destinationSet(station[destination-1]);
                tickets[usedTickets].priceSet(price);
                tickets[usedTickets].dateSet(date);
                usedTickets += 1;
            }

            for (int j = 0; j < PWD; j++) // para sa pwd na ilalagay rin sa mini database naten
            {
                int disc = price - (price * 0.2);
                tickets[j].priceSet(disc);
            }

            cout << "Ticket(s) has been bought! Thank you!" << endl;
            Sleep(2000);
            system("cls");
            break;
        }

        else if (response == 'N' || response == 'n') // pag no alis kana dito ayaw na keta makita
        {
            cout << "Ticket Payment Cancelled" << endl;
            Sleep(1000);
            system("cls");
            break;
        }
        else
        {
            defaultFail();
        }
    }
>>>>>>> Stashed changes
}



// Janhnielle
void Railway::viewTicket(long long number)
{

}

// Matthew
void Railway::viewFee()
{
<<<<<<< Updated upstream
=======
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
>>>>>>> Stashed changes


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
