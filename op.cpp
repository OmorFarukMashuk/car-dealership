#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Car
{
    string brand;
    string color;
    double price;

    Car(string b, string c, double p) : brand(b), color(c), price(p){};
};

struct CarCollection
{
    list<Car> cars;

    // operator overloading of +=
    void operator+=(Car& car){
        this->cars.push_back(car);
    }
};


// operator overloading of <<
ostream& operator<<(ostream& COUT, Car& car){
    COUT << "Brand\t: " << car.brand << endl;
    COUT << "Color\t: " << car.color << endl;
    COUT << "Prce\t: $" << car.price << endl;

    //enabling multiple << operators overloading in single line  
    return COUT;

}



int main()
{
    Car car1 = Car("Marcedes Benz", "Black", 35000);
    Car car2 = Car("BMW", "Red", 45000);
    Car car3 = Car("Audi", "Grey", 50000);


    CarCollection carCollection;
    carCollection+=car1;
    carCollection+=car2;
    carCollection+=car3;



    cout << car1 << "\n" << car2 << endl;

    Car maxPriceCar = carCollection.cars.front();
    for(auto car : carCollection.cars){
        if(car.price > maxPriceCar.price){
            maxPriceCar = car;
        }

    }
    cout << "====Most Expensive==== \n" << maxPriceCar;

    return 0;
}