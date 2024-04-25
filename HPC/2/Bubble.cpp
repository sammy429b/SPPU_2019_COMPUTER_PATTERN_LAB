#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <omp.h>

using namespace std;

void parallelBubbleSort(vector<int> &arr1)
{
    int N = arr1.size();
    int i = 0, j = 0;
    int first;
    for (i = 0; i < N - 1; i++)
    {
        first = i % 2;
#pragma omp parallel for default(none), shared(arr1, first, N)
        for (j = first; j < N - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                swap(arr1[j], arr1[j + 1]);
            }
        }
    }
}

void bubbleSort(vector<int> &arr2)
{
    int n = arr2.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                swap(arr2[j], arr2[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> arr1;
    vector<int> arr2;
    int r = 0;
    for (int i = 0; i < 50000; i++)
    {
        r = rand() % 10000;
        arr1.push_back(r);
        arr2.push_back(r);
    }
    auto start = chrono::high_resolution_clock::now();
    parallelBubbleSort(arr1);
    auto end = chrono::high_resolution_clock::now();

    double t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Parallel bubble sort: " << t << " milliseconds" << endl;

    start = chrono::high_resolution_clock::now();
    bubbleSort(arr2);
    end = chrono::high_resolution_clock::now();
    t = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Sequential bubble sort: " << t << " milliseconds" << endl;

    return 0;
}