#include <iostream>
#include "model.cpp"

using namespace std;

void addCar(vector<CarDealer> &carDealers)
{

    string usrDid;
    string id;
    string brand;
    string color;
    double price;

    cout << "Dealer ID\t:";
    getline(std::cin >> ws, usrDid);
    cout << "Brand\t:";
    getline(std::cin >> ws, brand);
    cout << "Color\t:";
    getline(cin >> ws, color);
    cout << "Price\t:";
    cin >> price;

    int idnum = rand() % 10000; // number between 0 and 9999

    stringstream ss;
    ss << setw(4) << setfill('0') << idnum;
    id = "C" + ss.str();

    Car car = Car(usrDid, id, brand, color, price);

    insert(usrDid, car, carDealers);

    // saving data to data.txt file
    saveToFile(carDealers);

    cout << "!!!car added successfully!!!" << endl;

    // cout << "ID\t: " << id << "\nBrand\t: " << brand << "\nColor\t: " << color << "\nPrice\t: " << price << endl;

    return;
}

Car customExpCar(vector<CarDealer> &carDealers, bool (*compareFuncPtr)(double, double))
{
    Car resCar = carDealers[0].cars.begin()->second;
    for (auto cd : carDealers)
    {
        
        for (auto carItr = cd.cars.begin(); carItr != cd.cars.end(); ++carItr)
        {
            if (compareFuncPtr(carItr->second.price, resCar.price))
                resCar = carItr->second;
        }
    }

    return resCar;
}

void showCars(vector<CarDealer> &carDealers)
{
    readFromFile(carDealers);
    print(carDealers);
}