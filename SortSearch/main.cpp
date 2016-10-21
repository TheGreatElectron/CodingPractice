#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>

// Print array
template <typename T>
void printArr(T A, size_t size) {
  std::cout << "[ " << A[0];
  for (size_t i=1; i<size; ++i) {
    std::cout << ", " << A[i];
  }
  std::cout << " ]" << std::endl;
}

// Randomoized Quicksort
template <typename T>
void quicksort(T *A, size_t left, size_t right) {
  size_t l = left;
  size_t r = right - 1;
  size_t size = right - left;

  if (size > 1) {
    T pivot = A[rand() % size + l];

    while (l < r) {
      while (A[r] > pivot && r > 1){
        r--;
      }

      while (A[l] < pivot && l <= r) {
        l++;
      }

      if (l < r) {
        std::swap(A[l], A[r]);
        l++;
      }
    }

    quicksort(A,left, l);
    quicksort(A, r, right);
  }
}

template <typename T>
void merge(T *A, size_t l, size_t m, size_t r) {
  size_t i, j, k;
  size_t n1 = m - l + 1;
  size_t n2 = r - m;

  // Create and fill temp arrays
  T L[n1], R[n2];
  for (i = 0; i < n1; ++i) {
    L[i] = A[ l + i ];
  }
  for (j = 0; j < n2; ++j) {
    R[j] = A[ m + 1 + j ];
  }

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}

// Mergesort
template <typename T>
void mergesort(T *A, size_t left, size_t right) {
  if (left < right) {
    size_t m = (left + right)/2;

    mergesort(A, left, m);
    mergesort(A, m+1, right);

    merge(A, left, m, right);
  }
}

// Binary search of an array
template <typename T>
int binarySearch(T array[], size_t len, T target) {
  size_t front = 0;
  size_t back = len-1;
  size_t mid;
  size_t iterations = 0;

  do {
    ++iterations;
    mid = (back+front)/2;
    if (array[mid] == target) {
      std::cout << "Iterations: " << iterations << std::endl;
      return mid;
    }
    else {
      (array[mid] < target) ? front = mid+1 : back = mid-1;
    }
  } while (front <= back);
  std::cout << "Iterations: " << iterations << std::endl;
  return -1;
}

int main() {
  // Crate a randomized array vals [0,99]
  srand(time(NULL));
  size_t size = 25;
  int *A = new int[size];

  for (size_t i=0; i < size; ++i) {
    A[i] = rand() % 100;
  }

  // Print unsorted array, then sort, then print
  printArr(A, size);
  mergesort(A, 0, size-1);
  printArr(A, size);

  // search for a random value
  int target = rand()%100 ;
  std::cout << "Searching for " << target << " in A." << std::endl;
  int indexFound = binarySearch(A, size, target);
  std::string foundString = (indexFound > 0) ? "found at " + std::to_string(indexFound) : "not found";
  std::cout << "Target " << foundString << std::endl;

  delete [] A;
  return 0;
}
