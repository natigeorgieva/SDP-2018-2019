#include <iostream>
#include <cstring>
using namespace std;

struct Car
{
    char brand[101];
    char model[101];
    unsigned int maxSpeed;
    unsigned int hp;
    bool used;
    unsigned int mileage;
    double price;
};

struct CarDealership
{
    char address[101];
    Car cars[1000];
    int numberOfCars;

    Car& getMostExpensiveCar()
    {
        int idx = 0;
        for (int i = 1; i < numberOfCars; i++)
        {
            if (cars[i].price > cars[idx].price)
            {
                idx = i;
            }
        }

        cout << &cars[idx] << endl;
        return cars[idx];
    }

    char* const getMostExpensiveBrand()
    {
        double maxAveragePriceOfBrand = 0.0;
        int idxOfCarWithWantedBrand = -1;
        for (int i = 0; i < numberOfCars; i++)
        {
            double price = 0.0;
            int numberOfCarsOfThisBrand = 0;
            for (int j = 0; j < numberOfCars; j++)
            {
                if (!strcmp(cars[i].brand, cars[j].brand))
                {
                    price += cars[j].price;
                    numberOfCarsOfThisBrand++;
                }
            }

            double averagePrice = price / numberOfCarsOfThisBrand;/// we are sure that numberOfCarsOfThisBrand can't be 0
            if (maxAveragePriceOfBrand - averagePrice < 0.000000001)
            {
                maxAveragePriceOfBrand = averagePrice;
                idxOfCarWithWantedBrand = i;
            }
        }

        return cars[idxOfCarWithWantedBrand].brand;
    }

};

int main()
{
    Car c[10];
    int N = 3;

    strcpy(c[0].brand, "Mercedes");
    c[0].price = 100000.123;
    c[0].hp = 120;

    strcpy(c[1].brand, "BMW");
    c[1].price = 90132.222;
    c[1].hp = 170;

    strcpy(c[2].brand, "Porsche");
    c[2].price = 300000.321;
    c[2].hp = 300;

    CarDealership carDealership;
    strcpy(carDealership.address, "Some Street, 123");
    carDealership.numberOfCars = N;
    for (int i = 0; i < carDealership.numberOfCars; i++)
    {
        carDealership.cars[i] = c[i];
    }

    Car& mostExpensiveCar = carDealership.getMostExpensiveCar();
    cout << &mostExpensiveCar << endl; /// note that this address is the same a the one printed in the function: getMostExpensiveCar()
                                       /// So, what does it mean that? -> The returned Car object is not copied
    cout << mostExpensiveCar.brand << endl;

    char* const mostExpensiveBrand = carDealership.getMostExpensiveBrand();
    cout << mostExpensiveBrand << endl;

    return 0;
}
