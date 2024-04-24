#include <iostream>
#include <omp.h>
#include <chrono>
using namespace std;

// function to merge two sorted halves of a array
void merge(int arr[], int left, int mid, int right){

  int size1 = mid - left + 1;
  int leftArr[size1];
  int size2 = right - mid;
  int rightArr[size2];


  for(int i = 0; i < size1; i++){
    leftArr[i] = arr[left + i];
  }
  for(int i = 0 ; i < size2; i++){
    rightArr[i] = arr[mid + 1 + i];
  }
  int i =0, j = 0,  k =left;
  while(i < size1 && j < size2){
    if(leftArr[i]<rightArr[j]){
      arr[k++] = leftArr[i++];
    }else{
      arr[k++] = rightArr[j++];
    }
  }

  while(i < size1){
    arr[k++] = leftArr[i++];
  }

  while(i < size2){
    arr[k++] = leftArr[j++];
  }
  
}

void serialMergeSort(int arr[], int left, int right){
  if(left<right){
    int mid = left + (right-left)/2;
    serialMergeSort(arr, left, mid);
    serialMergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
  }
}


void parallelMergeSort(int arr[], int left, int right){
  if(left<right){
    int mid = left + (right-left)/2;
    #pragma omp parallel sections
    {
        #pragma omp section
        parallelMergeSort(arr, left, mid);

        #pragma omp section
        parallelMergeSort(arr, mid+1, right);
    }
    merge(arr, left, mid, right);
  }
}


int main() {
  int sizeOfArray = 100000;

  int arr[sizeOfArray];

  for (int i = 0; i < sizeOfArray; i++) {
        arr[i] = rand() % 1000; 
    }

  cout<<endl;

// serial sort 
    auto start_serial = chrono::steady_clock::now();
    serialMergeSort(arr, 0, sizeOfArray - 1);
    auto end_serial = chrono::steady_clock::now();
    
    auto start_parallel = chrono::steady_clock::now();
    parallelMergeSort(arr, 0, sizeOfArray - 1);
    auto end_parallel = chrono::steady_clock::now();
    cout << "Serial sort time: " << chrono::duration_cast<chrono::milliseconds>(end_serial - start_serial).count() << " milliseconds" << endl;
    cout << "Parallel sort time: " << chrono::duration_cast<chrono::milliseconds>(end_parallel - start_parallel).count() << " milliseconds" << endl;


}