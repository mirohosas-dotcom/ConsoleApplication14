#include <iostream>
using namespace std;
class ISort
{
public:
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
};

class Array : public ISort
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

    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    void SortAsc() override
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (data[j] > data[j + 1])
                {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    void SortDesc() override
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (data[j] < data[j + 1])
                {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    void SortByParam(bool isAsc) override
    {
        if (isAsc)
        {
            SortAsc();
        }
        else
        {
            SortDesc();
        }
    }
};
int main()
{
    system("chcp 65001");
    int numbers[] = { 7, 2, 9, 1, 5 };
    Array arr(numbers, 5);
    cout << "Початковий масив: ";
    arr.Show();
    arr.SortAsc();
    cout << "За зростанням: ";
    arr.Show();
    arr.SortDesc();
    cout << "За спаданням: ";
    arr.Show();
    arr.SortByParam(true);
    cout << "SortByParam(true): ";
    arr.Show();
    arr.SortByParam(false);
    cout << "SortByParam(false): ";
    arr.Show();
}