#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    char brand[101];
    char model[101];
    unsigned int maxSpeed;
    unsigned int hp;
    bool used;
    unsigned int mileage;
    double price;

public:
    Car(const char* nBrand = "VW", const char* nModel = "Golf 4", unsigned int nMaxSpeed = 100,
        unsigned int nHp = 100, bool nUsed = true, unsigned int nMileage = 100000, double nPrice = 7432.5)
    {
        strcpy(brand, nBrand);
        strcpy(model, nModel);
        maxSpeed = nMaxSpeed;
        hp = nHp;
        used = nUsed;
        mileage = nMileage;
        price = nPrice;
    }

    ///getters

    const char* getBrand()
    {
        return brand;
    }

    const char* getModel()
    {
        return model;
    }

    unsigned int getMaxSpeed()
    {
        return maxSpeed;
    }

    unsigned int getHp()
    {
        return hp;
    }

    bool isUsed()
    {
        return used;
    }

    unsigned int getMileage()
    {
        return mileage;
    }

    double getPrice()
    {
        return price;
    }

    ///setters

    void setBrand(const char* nBrand)
    {
        strcpy(brand, nBrand);
    }

    void setModel(const char* nModel)
    {
        strcpy(model,nModel);
    }

    void setMaxSpeed(unsigned int nMaxSpeed)
    {
        if(nMaxSpeed > 0){
            maxSpeed = nMaxSpeed;
        }
    }

    void setHp(unsigned int nHp)
    {
        if(nHp > 0){
            hp = nHp;
        }
    }

    void setUsed(bool nUsed)
    {
        used = nUsed;
    }

    void setMileage(unsigned int nMileage)
    {
        if(nMileage > 0){
            mileage = nMileage;
        }
    }

    void setPrice(double nPrice){
        if(nPrice > 0){
            price = nPrice;
        }
    }
};

class CarDealership
{
public:
    char address[101];
    Car cars[1000];
    int numberOfCars;

    Car& getMostExpensiveCar()
    {
        int idx = 0;
        for (int i = 1; i < numberOfCars; i++)
        {
            if (cars[i].getPrice() > cars[idx].getPrice())
            {
                idx = i;
            }
        }

        cout << &cars[idx] << endl;
        return cars[idx];
    }

    const char* const getMostExpensiveBrand()
    {
        double maxAveragePriceOfBrand = 0.0;
        int idxOfCarWithWantedBrand = -1;
        for (int i = 0; i < numberOfCars; i++)
        {
            double price = 0.0;
            int numberOfCarsOfThisBrand = 0;
            for (int j = 0; j < numberOfCars; j++)
            {
                if (!strcmp(cars[i].getBrand(), cars[j].getBrand()))
                {
                    price += cars[j].getPrice();
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

        return cars[idxOfCarWithWantedBrand].getBrand();
    }

};

int main()
{
    Car c[10];
    int N = 3;

    c[0].setBrand("Mercedes");
    c[0].setPrice(100000.123);
    c[0].setHp(120);

    c[1].setBrand("BMW");
    c[1].setPrice(90132.222);
    c[1].setHp(170);

    c[2].setBrand("Porsche");
    c[2].setPrice(300000.321);
    c[2].setHp(300);

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
    cout << mostExpensiveCar.getBrand() << endl;

    const char* const mostExpensiveBrand = carDealership.getMostExpensiveBrand();
    cout << mostExpensiveBrand << endl;

    return 0;
}
