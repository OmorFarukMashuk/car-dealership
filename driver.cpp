/*

* 3 Dealers
* Car Add to specific dealer
* Sell Car by specific dealer (by Car ID, delerID)
* Transfer Car from a dealer to another dealer (by Car ID)
* Add an exact same model of a car from a dealer to another dealer's car inventory (by Car ID)
* Sort the Cars (Ascending and descending for each dealer)
* Get the max and min expensive Car (from both a specific dealer and all dealers)
* sotre information to a file and read from the file upon starting of the program
* Change Dealer (by Dealer ID)
* Show Current Dealer Inventory
* Show All Dealer Inventory

driver.cpp, console.cpp, services.cpp, structs.cpp

*/
#include <iostream>
#include <vector>
#include <vector>
#include <map>
#include <iomanip>
#include "services.cpp"

#define TOTAL_DEALER 3

using namespace std;

void runUserPrompt(vector<CarDealer> &carDealers)

{
    string option;

    do
    {
        cout << ":::Dealers::: ";
        for (auto dealer : carDealers)
        {
            cout << "[" << dealer.dealerID << "]"
                 << " ";
        }
        cout << ":::Dealers:::" << endl;
        cout << "0 - Cancel\n"
             << "1 - Add Car\n"
             << "2 - Most Expensive Car\n"
             << "3 - Least Expensive Car\n"
             << "7 - Transfer Car to Another Dealer\n"
             << "9 - Show Cars" << endl;

        int choice;
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            addCar(carDealers);
            break;
        }

        case 2:
        {
            // function pointer
            Car maxExpCar = customExpCar(carDealers, maxCompare);
            cout << "Dealer\t: " << maxExpCar.dealerID << endl;
            cout << maxExpCar << endl;
            break;
        }

        case 3:
        {
            // function pointer
            Car minExpCar = customExpCar(carDealers, minCompare);
            cout << "Dealer\t: " << minExpCar.dealerID << endl;
            cout << minExpCar << endl;
            break;
        }
        case 7:
        {
            TransferCar(carDealers);
            break;
        }
        case 9:
        {
            showCars(carDealers);
            break;
        }

        case 0:
            break;
        default:
            break;
        }

        cout << "Type 'exit' to terminate console or any character(s) to proceed\n";
        cin >> option;
        if (option == "exit")
            break;
        else
            continue;

    } while (true);
}

int main()
{
    vector<CarDealer> carDealers;

    map<string, Car> cars;
    CarDealer cd;
    cd.dealerID = "D101",
    cd.cars = cars;
    carDealers.push_back(cd);

    cd.dealerID = "D102",
    carDealers.push_back(cd);

    cd.dealerID = "D103";
    carDealers.push_back(cd);

    runUserPrompt(carDealers);

    // Car car1 = Car("Marcedes Benz", "Black", 35000);
    // Car car2 = Car("BMW", "Red", 40000);
    // Car car3 = Car("Audi", "Grey", 50000);

    // cd += car1;
    // cd += car2;
    // cd += car3;

    // cout << car1 << "\n"
    //      << car2 << "\n"
    //      << car3 << endl;

    // cout << "====Most Expensive==== \n"
    //      << getMostExpCar(cd);
    return 0;
}