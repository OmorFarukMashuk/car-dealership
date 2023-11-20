#include <iostream>

using namespace std;

struct Car
{
    string dealerID;
    string id;
    string brand;
    string color;
    double price;

    Car(){};

    Car(string did, string id, string b, string c, double p) : dealerID(did), id(id), brand(b), color(c), price(p){};

    // // operator overloading of >
    // bool operator>(const Car &prevMaxCar)
    // {
    //     return this->price > prevMaxCar.price;
    // }
};

struct CarDealer
{
    map<string, Car> cars;
    string dealerID;

    CarDealer(){};
    CarDealer(map<string, Car> crs, string did) : cars(crs), dealerID(did){};

    // operator overloading of +=
    void operator+=(Car &car)
    {
        this->cars.insert({car.id, car});
    }
};

// operator overloading of <<
ostream &operator<<(ostream &COUT, const Car &car)
{
    COUT << "Brand\t: " << car.brand << endl;
    COUT << "Color\t: " << car.color << endl;
    COUT << "Price\t: $" << car.price << endl;

    // enabling multiple << operators overloading in single line
    return COUT;
}

void print(vector<CarDealer> &carDealers)
{
    for (auto cd : carDealers)
    {
        cout << "[DEALER]" << cd.dealerID << "[DEALER]" << endl;
        for (auto carItr = cd.cars.begin(); carItr != cd.cars.end(); ++carItr)
        {
            cout << "ID\t: " << carItr->first << '\n'
                 << carItr->second << '\n';
        }
    }
}

string generateRandId()
{
    int idnum = rand() % 10000; // number between 0 and 9999
    stringstream ss;
    ss << setw(4) << setfill('0') << idnum;

    return "C" + ss.str();
}

void updateDealerInventory(Car *car, CarDealer *cd)
{

    if (cd->cars.find(car->id) == cd->cars.end())
    {
        // not found
        *cd += *car;
    }
    else
    {
        car->id = generateRandId();
        updateDealerInventory(car, cd);
    }
}

bool maxCompare(double a, double b)
{
    return a > b;
}
bool minCompare(double a, double b)
{
    return a < b;
}
