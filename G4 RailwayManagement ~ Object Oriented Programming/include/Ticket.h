#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
using std::string;


class Ticket
{
    public:
        Ticket();
        virtual ~Ticket();

        /* Setters and Getters */
        // Number
        void numberSet(int x)
        {
            Number = x;
        }
        int numberGet()
        {
            return Number;
        }
        // Origin
        void originSet(string x)
        {
            Origin = x;
        }
        string originGet()
        {
            return Origin;
        }

        // Destination
        void destinationSet(string x)
        {
            Destination = x;
        }
        string destinationGet()
        {
            return Destination;
        }

        // Int Origin
        void intOriginSet(int x)
        {
            intOrigin = x;
        }
        int intOriginGet()
        {
            return intOrigin;
        }

        // Int Destination
        void intDestinationSet(int x)
        {
            intDestination = x;
        }
        int intDestinationGet()
        {
            return intDestination;
        }

        // Price
        void priceSet(int x)
        {
            Price = x;
        }
        int priceGet()
        {
            return Price;
        }

        // Date
        void dateSet(string x)
        {
            Date = x;
        }
        string dateGet()
        {
            return Date;
        }


    protected:

    private:

        // User
        long long Number;
        string Origin;
        string Destination;
        int intOrigin;
        int intDestination;
        int Price;
        string Date;


};

#endif // TICKET_H
