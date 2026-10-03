#include <iostream>
using namespace std;
class IDrivable
{
public:
    virtual void StartEngine() = 0;
    virtual void StopEngine() = 0;
    virtual void Drive() = 0;
};

class Car : public IDrivable
{
public:
    void StartEngine() override
    {
        cout << "Автомобіль: двигун запущено" << endl;
    }

    void StopEngine() override
    {
        cout << "Автомобіль: двигун зупинено" << endl;
    }

    void Drive() override
    {
        cout << "Автомобіль їде" << endl;
    }
};

class Motorcycle : public IDrivable
{
public:
    void StartEngine() override
    {
        cout << "Мотоцикл: двигун запущено" << endl;
    }

    void StopEngine() override
    {
        cout << "Мотоцикл: двигун зупинено" << endl;
    }

    void Drive() override
    {
        cout << "Мотоцикл їде" << endl;
    }
};
int main()
{
    system("chcp 65001");
    Car car;
    Motorcycle motorcycle;
    cout << "Автомобіль:" << endl;
    car.StartEngine();
    car.Drive();
    car.StopEngine();
    cout << endl;
    cout << "Мотоцикл:" << endl;
    motorcycle.StartEngine();
    motorcycle.Drive();
    motorcycle.StopEngine();
}