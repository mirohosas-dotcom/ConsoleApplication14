#include <iostream>
using namespace std;
class IMath
{
public:
    virtual int Max() = 0;
    virtual int Min() = 0;
    virtual float Avg() = 0;
    virtual bool Search(int valueToSearch) = 0;
};
class Array : public IMath
{
private:
    int* data;
    int size;

public:
    Array(int arr[], int n)
    {
        size = n;
        data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = arr[i];
        }
    }
    ~Array()
    {
        delete[] data;
    }
    int Max() override
    {
        int max = data[0];

        for (int i = 1; i < size; i++)
        {
            if (data[i] > max)
            {
                max = data[i];
            }
        }

        return max;
    }
    int Min() override
    {
        int min = data[0];

        for (int i = 1; i < size; i++)
        {
            if (data[i] < min)
            {
                min = data[i];
            }
        }

        return min;
    }
    float Avg() override
    {
        int sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += data[i];
        }

        return (float)sum / size;
    }

    bool Search(int valueToSearch) override
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == valueToSearch)
            {
                return true;
            }
        }

        return false;
    }
};
int main()
{
    system("chcp 65001");
    int numbers[] = { 5, 2, 8, 1, 9 };
    Array arr(numbers, 5);
    cout << "Максимум: " << arr.Max() << endl;
    cout << "Мінімум: " << arr.Min() << endl;
    cout << "Середнє: " << arr.Avg() << endl;
    if (arr.Search(8))
    {
        cout << "Число 8 знайдено" << endl;
    }
    else
    {
        cout << "Число 8 не знайдено" << endl;
    }

    if (arr.Search(10))
    {
        cout << "Число 10 знайдено" << endl;
    }
    else
    {
        cout << "Число 10 не знайдено" << endl;
    }
}