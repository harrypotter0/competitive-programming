// C++ program to count the inversions 
// present in the array using segment tree 
#include "algorithm" 
#include "cstring" 
#include "iostream" 
using namespace std; 

// Function to update segment tree 
// i.e. to insert the element 
void update(int* Tree, int index, int s, int e, int num) 
{ 
	// Leaf node condition 
	if (s == num and e == num) { 
		Tree[index] = 1; 
		return; 
	} 

	// No overlap condition 
	if (num < s or num > e) { 
		return; 
	} 

	// Else call on both the children nodes 
	int mid = (s + e) >> 1; 
	update(Tree, 2 * index, s, mid, num); 
	update(Tree, 2 * index + 1, mid + 1, e, num); 

	Tree[index] = Tree[2 * index] + Tree[2 * index + 1]; 
} 

// Function to count the total numbers 
// present in the range [a[i]+1, mx] 
int query(int* Tree, int index, int s, 
		int e, int qs, int qe) 
{ 
	// Complete overlap 
	if (qs <= s and e <= qe) { 
		return Tree[index]; 
	} 

	// No Overlap 
	if (s > qe or e < qs) { 
		return 0; 
	} 

	int mid = (s + e) >> 1; 

	return query(Tree, 2 * index, s, 
				mid, qs, qe) 
		+ query(Tree, 2 * index + 1, 
				mid + 1, e, qs, qe); 
} 

// Driver code 
int main(int argc, char const* argv[]) 
{ 
	int arr[] = { 8, 4, 2, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Maximum element present in the array. 
	int mx = *max_element(arr, arr + n); 

	// Segment Tree 
	int Tree[6 * mx]; 

	// Initialize every node 
	// of segment tree to 0 
	memset(Tree, 0, sizeof(Tree)); 

	int answer = 0; 

	for (int i = 0; i < n; ++i) { 

		// add the count of inversion pair 
		// formed with the element a[i] and the 
		// elements appearing before the index i. 
		answer += query(Tree, 1, 1, mx, arr[i] + 1, mx); 

		// Insert the a[i] in the segment tree 
		update(Tree, 1, 1, mx, arr[i]); 
	} 

	cout << answer; 
	return 0; 
} 
