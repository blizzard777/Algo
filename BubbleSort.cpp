#include <bits/stdc++.h> 
using namespace std; 


void bubbleSort(int arr[], int n) 
{ 
	for (int i = 0; i < n - 1; i++) {	 
	  for (j = 0; j < n - i - 1; j++) { 
		  if (arr[j] > arr[j+1]) 
			  swap(arr[j], arr[j+1]); 
      }
    }
  }
}

int main() 
{ 
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bubbleSort(arr, n); 
} 
