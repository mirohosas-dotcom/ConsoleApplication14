#include <iostream>
using namespace std;
class IOutput
{
public:
    virtual void Show() = 0;
    virtual void Show(const char* info) = 0;
};

class Array : public IOutput
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

    void Show() override
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    void Show(const char* info) override
    {
        cout << info << endl;

        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};
int main()
{
    system("chcp 65001");
    int numbers[] = { 5, 2, 8, 1, 9 };
    Array arr(numbers, 5);
    arr.Show();
    arr.Show("Масив:");

}