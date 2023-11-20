#include <iostream>
#include <sstream>
#include <fstream>
#include "utils.cpp"

#define PATH "resources/data.txt"

using namespace std;

void saveToFile(vector<CarDealer> &carDealers)
{
    fstream file;
    file.open(PATH, ios::out);
    if (file.is_open())
    {
        for (auto cd : carDealers)
        {
            for (auto itr = cd.cars.begin(); itr != cd.cars.end(); ++itr)
            {
                file << cd.dealerID << '\n';
                file << itr->first << '\n';
                file << itr->second.brand << '\n';
                file << itr->second.color << '\n';
                file << itr->second.price << '\n';
            }
        }

        // cout << "Dealer\t: " << dealerID << "\nID\t: " << carID << "\nBrand\t: " << brand << "\nColor\t: " << color << "\nPrice\t: " << price << endl;
    }
    file.close();
}

void readFromFile(vector<CarDealer> &carDealers)

{
    fstream file;
    file.open(PATH, ios::in);

    if (file)
    {
        string line;

        // Read data from the file object and put it into a string.
        while (getline(file, line))
        {

            string dealerID = line;
            getline(file, line);
            string carID = line;
            getline(file, line);
            string brand = line;
            getline(file, line);
            string color = line;
            getline(file, line);
            double price = stod(line);

            Car *car = new Car(dealerID, carID, brand, color, price);

            for (int i = 0; i < carDealers.size(); i++)
            {
                if (carDealers[i].dealerID == dealerID)
                    carDealers[i] += *car;
            }

            // cout << "Dealer\t: " << dealerID << "\nID\t: " << carID << "\nBrand\t: " << brand << "\nColor\t: " << color << "\nPrice\t: " << price << endl;
        }
        // cout << "File exists" << endl;
    }
    else
    {
        cout << "No Data/File!!!" << endl;
    }

    file.close();
}