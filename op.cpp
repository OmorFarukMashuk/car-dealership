/*

* Multiple Dealers
* Car Add to specific dealer
* Sell Car by specific dealer (by Car ID)
* Transfer Car from a dealer to another dealer (by Car ID)
* Add an exact same model of a car from a dealer to another dealer's car inventory (by Car ID)
* Sort the Cars (Ascending and descending for each dealer)
* Get the max and min expensive Car (from both a specific dealer and all dealers)
* sotre information to a file and read from the file upon starting of the program

*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <iomanip>
#include <sstream>
#include <string>


using namespace std;

struct Car
{
    string id;
    string brand;
    string color;
    double price;

    Car(string id, string b, string c, double p) : id(id), brand(b), color(c), price(p){};

    // operator overloading of >
    bool operator>(const Car &prevMaxCar)
    {
        return this->price > prevMaxCar.price;
    }
};

struct CarDealer
{
    map<string, Car> cars;

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

// Car getMostExpCar(CarDealer cd)
// {
//     Car maxPriceCar = cd.cars.front();
//     for (auto car : cd.cars)
//     {
//         if (car > maxPriceCar)
//         {
//             maxPriceCar = car;
//         }
//     }

//     return maxPriceCar;
// }

void addCar(CarDealer &cd)
{

    string id;
    string brand;
    string color;
    double price;

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


    cout << "!!!car added successfully!!!" << endl;

    // cout << "ID\t: " << id << "\nBrand\t: " << brand << "\nColor\t: " << color << "\nPrice\t: " << price << endl;

    Car car = Car(id, brand, color, price);
    cd += car;

    return;
}

void showCars(CarDealer& cd)
{
       for (auto itr = cd.cars.begin(); itr != cd.cars.end(); ++itr) {  
        cout << "ID\t: " << itr->first  << '\n' << itr->second << '\n';  
    }  
}

void runUserPrompt(CarDealer &cd)
{
    string option;

    do
    {
        cout << "0 - Cancel\n"
             << "1 - Add Car\n"
             << "2 - Show Cars" << endl;

        int choice;
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addCar(cd);
            break;
        case 2:
            showCars(cd);
            break;
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
    CarDealer cd;
    runUserPrompt(cd);

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