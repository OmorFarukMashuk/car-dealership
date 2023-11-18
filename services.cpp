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

void TransferCar(vector<CarDealer> &carDealers)
{

    string fromUsrDid;
    string fromCarID;
    string toUsrDid;

    cout << "Dealer ID (From)\t:";
    getline(std::cin >> ws, fromUsrDid);
    cout << "Car ID (From)\t:";
    getline(std::cin >> ws, fromCarID);
    cout << "Dealer ID (To)\t:";
    getline(std::cin >> ws, toUsrDid);

    for (int i = 0; i < carDealers.size(); i++)
    {
        if (carDealers[i].dealerID == fromUsrDid)
        {

            Car *targetCar = new Car(carDealers[i].cars.at(fromCarID));
            // shallow copy - pointing same memory from RHS for car
            Car *car = targetCar;
            // deep copy - allocating new memory for car
            //  Car *car = new Car(*targetCar);
            delete (targetCar);
            // carDealers[i].cars.erase(fromCarID);

            cout << *car;
            // cout << *targetCar;

            CarDealer *cd = new CarDealer(carDealers[i]);

            cout << "[DEALER]......" << cd->dealerID << "[DEALER]" << endl;
            for (auto carItr = cd->cars.begin(); carItr != cd->cars.end(); ++carItr)
            {
                cout << "ID\t: " << carItr->first << '\n'
                     << carItr->second << '\n';
            }

            // transfer(new Car(*targetCar),carDealers[i]);
        }
    }

    // transfer(fromUsrDid,fromCarID,toUsrDid,carDealers);
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