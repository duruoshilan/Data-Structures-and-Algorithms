#include <iostream>
#include <stdlib.h>

using namespace std;

void quicksort(int arr[], int start, int end);

int main(void)
{

    int numberCount = 10000;
    int arr[numberCount] = {};
    int i = 0;

    for (i = 0; i < numberCount; i += 1)
    {
        arr[i] = rand() % 100 + 1;
    }

    for (i = 0; i < numberCount; i += 1)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    quicksort(arr, 0, numberCount-1);

    for (i = 0; i < numberCount; i += 1)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

void quicksort(int arr[], int begin, int end)
{

    if (begin >= end)
    {
        return;
    }

    int mid = arr[begin];
    int i = begin;
    int j = end;
    
    while (i < j)
    {
        while (i < j && arr[j] > mid)
        {
            j -= 1;
        }
        if (i < j)
        {
            arr[i] = arr[j];
            i += 1;
        }

        while (i < j && arr[i] < mid)
        {
            i += 1;
        }
        if (i < j)
        {
            arr[j] = arr[i];
            j -= 1;
        }
    }

    arr[i] = mid;
    quicksort(arr, begin, i-1);
    quicksort(arr, i+1, end);
}
