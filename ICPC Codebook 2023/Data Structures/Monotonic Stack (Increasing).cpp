#include <bits/stdc++.h>
using namespace std;

// Function to build Monotonic
// increasing stack
void increasingStack(int arr[], int N) {
  // Initialise stack
  stack<int> stk;
  for (int i = 0; i < N; i++) {
  // Either stack is empty or
  // all bigger nums are popped off
    while (stk.size() > 0 && stk.top() > arr[i]) {
      stk.pop();
    }
    stk.push(arr[i]);
  }
  int N2 = stk.size();
  int ans[N2] = { 0 };
  int j = N2 - 1;
  // Empty Stack
  while (!stk.empty()) {
    ans[j] = stk.top();
    stk.pop();
    j--;
  }
  // Displaying the original array
  cout << "The Array: ";
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  // Displaying Monotonic increasing stack
  cout << "The Stack: ";
  for (int i = 0; i < N2; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

// Driver code
int main() {
  int arr[] = { 1, 4, 5, 3, 12, 10 };
  int N = sizeof(arr) / sizeof(arr[0]);
  // Function Call
  increasingStack(arr, N);
  return 0;
}
