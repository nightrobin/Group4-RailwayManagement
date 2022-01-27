#ifndef RAILWAY_H
#define RAILWAY_H
#include "Ticket.h"


class Railway
{
    public:
        Railway();
        virtual ~Railway();

        string station[13] = {"Recto" ,"Legarda" ,"Pureza" , "V Mapa", "J Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};
        static const int ticketLimit = 100; // hanggang ilang tickets pwedeng bilin ng mga user. for now 100 baka mas bumagal pang marami
        int usedTickets = 0; // ilan na nabiling tickets ng mga users

        Ticket tickets[ticketLimit]; // gawa object for tickets
        Ticket Fee; // For fees idk

        // Both
        void inputFail();
        void defaultFail();
        int checkNumber(long long number);

        // User
        int PWDCheck(int quantity);
        void User(long long number);
        void buyTicket(long long number);
        void viewTicket(long long number);
        void viewFee();

        // Admin
        void Admin();
        void viewSale();
        void changeFee();



    protected:

    private:

};

#endif // RAILWAY_H
