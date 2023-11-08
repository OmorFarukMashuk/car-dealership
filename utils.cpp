#include <iostream>


using namespace std;

struct Car
{
    string dealerID;
    string id;
    string brand;
    string color;
    double price;

    Car(string did, string id, string b, string c, double p) : dealerID(did), id(id), brand(b), color(c), price(p){};

    // operator overloading of >
    bool operator>(const Car &prevMaxCar)
    {
        return this->price > prevMaxCar.price;
    }
};

struct CarDealer
{
    map<string, Car> cars;
    string dealerID;

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

void insert( string dealerID, Car car, vector<CarDealer> &carDealers){
        for (int i = 0; i < carDealers.size(); i++)
    {
        if (carDealers[i].dealerID == dealerID){
            carDealers[i] += car;
        }

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
