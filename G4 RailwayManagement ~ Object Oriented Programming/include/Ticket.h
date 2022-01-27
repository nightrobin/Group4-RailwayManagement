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

        string dateCheck(); // For getting the date

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

         // Station Fees
        void stationFeeSet(int origin, int destination, int price)
        {
            stationFees[origin][destination] = price;
        }
        int stationFeeGet(int origin, int destination)
        {
            return stationFees[origin][destination];
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

         // Admin
         // mga presyo ng mga ticket
        int stationFees[13][13] = {{0, 15, 15, 15, 20, 20, 20, 20, 25, 25, 25, 30, 30}, // Recto
                                {15, 0, 15, 15, 15, 20, 20, 20, 20, 25, 25, 25, 30}, // Legarda
                                {15, 15, 0, 15, 15, 15, 20, 20, 20, 20, 25, 25, 30}, // Pureza
                                {15, 15, 15, 0, 15, 15, 15, 20, 20, 20, 25, 25, 25}, // V Mapa
                                {20, 15, 15, 15, 0, 15, 15, 15, 20, 20, 20, 25, 25}, // J Ruiz
                                {20, 20, 15, 15, 15, 0, 15, 15, 15, 20, 20, 20, 25}, // Gilmore
                                {20, 20, 20, 15, 15, 15, 0, 15, 15, 15, 20, 20, 25}, // Betty Go
                                {20, 20, 20, 20, 15, 15, 15, 0, 15, 15, 15, 20, 20}, // Cubao
                                {25, 20, 20, 20, 20, 15, 15, 15, 0, 15, 15, 20, 20}, // Anonas
                                {25, 25, 20, 20, 20, 20, 15, 15, 15, 0, 15, 15, 20}, // Katipunan
                                {25, 25, 25, 25, 20, 20, 20, 15, 15, 15, 0, 15, 15}, // Santolan
                                {30, 25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15}, // Marikina
                                {30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 15, 15, 0}}; // Antipolo


};

#endif // TICKET_H
