#ifndef RAILWAY_H
#define RAILWAY_H
#include "Ticket.h"


class Railway
{
    public:
        Railway();
        virtual ~Railway();

        static const int ticketLimit = 100;
        int usedTickets = 0;

        Ticket tickets[ticketLimit];

        // Both
        void inputFail();
        void defaultFail();
        int checkNumber(long long number);

        // User
        void User();
        void buyTicket();
        void viewTicket();
        void viewFee();

        // Admin
        void Admin();
        void viewSale();
        void changeFee();



    protected:

    private:

};

#endif // RAILWAY_H
