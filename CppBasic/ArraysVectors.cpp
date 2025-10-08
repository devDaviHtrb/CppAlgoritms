#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {1, 2};
    int array[2] = {1, 4};

    cout << array[0];

    for (int n = 0; n < numbers.size(); n++)
    {
        cout << numbers[n];
    }
}