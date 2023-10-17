#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr, int exp) {
  int n = arr.size();
  vector<int> count(10, 0);
  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  vector<int> sorted(n);
  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    sorted[count[digit] - 1] = arr[i];
    count[digit]--;
  }
  for (int i = 0; i < n; i++) {
    arr[i] = sorted[i];
  }
}
void radixSort(vector<int>& arr) {
  int maxElement = *max_element(arr.begin(), arr.end());
  int maxDigits = 0;
  while (maxElement > 0) {
    maxElement /= 10;
    maxDigits++;
  }
  for (int exp = 1; exp <= maxDigits; exp *= 10) {
    countingSort(arr, exp);
  }
}

int main() {
  vector<int> arr = {121, 432, 564, 23, 1, 45, 788};

  radixSort(arr);

  cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
