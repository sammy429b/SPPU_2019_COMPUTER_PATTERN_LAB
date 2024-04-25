#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
  vector<int> temp(end - start + 1);
  int k = 0;
  int s1 = start, s2 = mid + 1, e1 = mid, e2 = end;
  while (s1 <= e1 && s2 <= e2)
  {
    if (arr[s1] <= arr[s2])
      temp[k++] = arr[s1++];

    else
      temp[k++] = arr[s2++];
  }

  while (s1 <= e1)
    temp[k++] = arr[s1++];
  while (s2 <= e2)
    temp[k++] = arr[s2++];
  for (int i = start; i <= end; i++)
    arr[i] = temp[i - start];
}

void mergeSort(vector<int> &arr, int start, int end)
{

  if (start < end)
  {
    int len = end - start;
    int mid = start + (len / 2);

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void mergeSortParallel(vector<int> &arr, int start, int end)
{

  if (start < end)
  {
    int len = end - start;
    int mid = start + (len / 2);
    {
      mergeSort(arr, start, mid);
    }
#pragma omp task shared(arr)
    {
      mergeSort(arr, mid + 1, end);
    }
#pragma omp taskwait
    {
      merge(arr, start, mid, end);
    }
  }
}

int main()
{
  vector<int> arr1;
  vector<int> arr2;
  int r = 0;
  for (int i = 0; i < 500000; i++)
  {
    r = rand() % 1000;
    arr1.push_back(r);
    arr2.push_back(r);
  }
  auto start = chrono::high_resolution_clock::now();
  mergeSortParallel(arr1, 0, arr1.size() - 1);
  auto end = chrono::high_resolution_clock::now();
  int t = chrono::duration_cast<chrono::microseconds>(end - start).count();
  cout<< "parallel merge sort :" << t<< " microsecond" << "\n";

  start = chrono::high_resolution_clock::now();
  mergeSort(arr2, 0, arr2.size() - 1);
  end = chrono::high_resolution_clock::now();
  t = chrono::duration_cast<chrono::microseconds>(end - start).count();
  cout<< "serial merge sort :" << t <<" microsecond"<< "\n";

  return 0;
}