#include <iostream>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
#include "Railway.h"
#include "Ticket.h"
// Lagay koh muna mga header na toh might help soon wla namang mamamatay

using namespace std;

int main()
{

  // Created Object for Railway System (Gagamitin sa buong process)
  Railway rlwy;

  // Infinite loop na pwedeng icancel through "break;". Application Menu
  while (true)
  {
      // Login Menu
      int choice = -1;
      cout << "LRT Recto to Antipolo" << endl;
      cout << "=====================" << endl;
      cout << "[1] Login" << endl;
      cout << "[0] Exit" << endl;

      cout << "\nInput a number to proceed: ";
      cin >> choice;
      // System("cls"); - for clearing the command prompt making it visually pleasing for the user.
      // tanggal lang sha text kase ang kalat parang si ano xDD
      system("cls");

      if (choice == 1)
      {
        system("cls");
        int login = 0;
        while (login == 0)
        {
            long long number;
            cout << "Login" << endl;
            cout << "==========" << endl;
            cout << "10 digit Mobile Number : +68 ";
            cin >> number;
            system("cls");
            // checkNumber(number) -- Method sha na makikita sa Railway.cpp na ginawa kow para icheck yung cellphone number if valid
            if(rlwy.checkNumber(number) == 1) // User
            {
                // Method/Function for going into the User Interface
                // Anything na valid na 10 digit number is pupunta rito
                rlwy.User(number);
                // Pag nagend na method ni User and isa lang naman ang reason pag nag end si user which is nag log out na sha so
                // Mag aadd or increment yung login which na papatigilin yung while loop tas babalik ule yung gumagamit sa pinakaunang menu
                login += 1;

                // Assigned: Harlene
            }
            else if(rlwy.checkNumber(number) == 2) // Admin
            {
                // Method/Function for going into the Admin interface
                // Di2 pupunta pag ininput sa cellphone number is "1234"
                // PWede naman iedit yung "1234" pero yan muna PIN pansamantala
                rlwy.Admin();

                // Assigned: Anny, Kenneth
            }
            else if (cin.fail())
            {
                // Method/Function for Blocking Error input on which a character or string has been input rather than an integer/number
                // Bat ka naginput ng letra sa number ha??
                rlwy.inputFail();
            }
            else
            {
                // Method/Function for Blocking the rest of input that doesn't fit to any of the conditions
                // para sa mga naginput ng different kase gus2 nila different sila
                rlwy.defaultFail();
            }

        }

      }
      else if (cin.fail())
      {
        rlwy.inputFail();
      }
      else if (choice == 0)
      {
          // cancelledt na sha quit na xd
          break;
      }
      else
      {
          rlwy.defaultFail();
      }
  }
}
