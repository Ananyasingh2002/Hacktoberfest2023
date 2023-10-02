// Time Complexity -> O(N * log(N))
// Space Complexity -> O(N)

#include <queue>

void findMedian(int *arr, int n) {
  // Write your code here

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i = 0; i < n; ++i) {
    if (maxHeap.empty() and minHeap.empty())
      maxHeap.push(arr[i]);
    else {
      if (arr[i] > maxHeap.top()) {
        minHeap.push(arr[i]);
      } else {
        maxHeap.push(arr[i]);
      }
    }

      int maxSize = maxHeap.size();
      int minSize = minHeap.size();

      if (maxSize - minSize == 2 or maxSize - minSize == -2) {
        if (maxSize > minSize) {
          int cur = maxHeap.top();
          maxHeap.pop();
          minHeap.push(cur);

          --maxSize;
          ++minSize;
        } else {
          int cur = minHeap.top();
          minHeap.pop();
          maxHeap.push(cur);

          --minSize;
          ++maxSize;
        }
      }

      // median

      if (maxSize > minSize)
        cout << maxHeap.top() << ' ';
      else if (minSize > maxSize)
        cout << minHeap.top() << ' ';
      else {
        int ans = (maxHeap.top() + minHeap.top()) >> 1;
        cout << ans << ' ';
      }
    }
  
}
