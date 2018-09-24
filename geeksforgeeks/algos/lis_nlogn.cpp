// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int n, num;
// 	vector<int> v;
// 	cin >> n;
// 	while (n--){
// 	cin >> num;
// 	if (v.size() == 0 || num > v.back())
// 	v.push_back(num);
// 	else *lower_bound(v.begin(), v.end(), num) = num;
// 	}
// 	cout << v.size();
// 	return 0;
// }

// // length of longest increasing subsequence in O(nlogn)
// #include <iostream>
// #include <set>
// using namespace std;
// /*=========================================================*/
// void LIS(int a[],int n){
// 	multiset<int> st; multiset<int>::iterator it; st.clear();
// 	for(int i=0;i<n;i++){
// 		st.insert(a[i]); it = st.find(a[i]);
// 		it++; if(it != st.end()) st.erase(it);
// 	}
// 	cout << st.size();
// }
// /*==========================================================*/

// int main() {
// 	int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
// 	int n = sizeof arr/sizeof arr[0];
// 	LIS(arr,n);
// }


// #include <iostream> 
// #include <vector> 
// #include<bits/stdc++.h>
// using namespace std;

// // Binary search (note boundaries in the caller) 
// int CeilIndex(std::vector<int> &v, int l, int r, int key) { 
// 	while (r-l > 1) { 
// 	int m = l + (r-l)/2; 
// 	if (v[m] >= key) 
// 		r = m; 
// 	else
// 		l = m; 
// 	} 

// 	return r; 
// } 

// int LongestIncreasingSubsequenceLength(std::vector<int> &v) { 
// 	if (v.size() == 0) 
// 		return 0; 

// 	std::vector<int> tail(v.size(), 0); 
// 	int length = 1; // always points empty slot in tail 

// 	tail[0] = v[0]; 
// 	for (size_t i = 1; i < v.size(); i++) { 
// 		if (v[i] < tail[0]) 
// 			// new smallest value 
// 			tail[0] = v[i]; 
// 		else if (v[i] > tail[length-1]) 
// 			// v[i] extends largest subsequence 
// 			tail[length++] = v[i]; 
// 		else
// 			// v[i] will become end candidate of an existing subsequence or 
// 			// Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i] 
// 			// (and also, v[i] would have already appeared in one of LIS, identify the location and replace it) 
// 			tail[CeilIndex(tail, -1, length-1, v[i])] = v[i]; 
// // 			tail[CeilIndex(tail, 0, length-1, v[i])] = v[i]; 
// 		for(auto it=tail.begin(); it!=tail.end(); it++)
// 		    cout<<*it<<" ";
// 		cout<<endl;
// 	} 

// 	return length; 
// } 

// int main() { 
// 	std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
// // 	vector<int>v{3, 5, 7, 3, 4, 5, 6};
// 	std::cout << "Length of Longest Increasing Subsequence is " << LongestIncreasingSubsequenceLength(v) << '\n'; 
// return 0; 
// } 


// C++ implementation to find longest increasing subsequence
// in O(n Log n) time.
#include <bits/stdc++.h>
using namespace std;

// Binary search
int GetCeilIndex(int arr[], vector<int> &T, int l, int r,
				int key)
{
	while (r - l > 1)
	{
		int m = l + (r - l)/2;
		if (arr[T[m]] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

int LongestIncreasingSubsequence(int arr[], int n)
{
	// Add boundary case, when array n is zero
	// Depend on smart pointers

	vector<int> tailIndices(n, 0); // Initialized with 0 
	vector<int> prevIndices(n, -1); // initialized with -1

	int len = 1; // it will always point to empty location
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[tailIndices[0]])
		{
			// new smallest value
			tailIndices[0] = i;
		}
		else if (arr[i] > arr[tailIndices[len-1]])
		{
			// arr[i] wants to extend largest subsequence
			prevIndices[i] = tailIndices[len-1];
			tailIndices[len++] = i;
		}
		else
		{
			// arr[i] wants to be a potential condidate of
			// future subsequence
			// It will replace ceil value in tailIndices
			int pos = GetCeilIndex(arr, tailIndices, -1,
								len-1, arr[i]);

			prevIndices[i] = tailIndices[pos-1];
			tailIndices[pos] = i;
		}
	}

	cout << "LIS of given input" << endl;
	for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i])
		cout << arr[i] << " ";
	cout << endl;
	
// 	cout << "tailIndices of given input" << endl;
// 	for (int i = 0; i <=n; i++)
// 		cout << tailIndices[i] << " ";
// 	cout << endl;
	
// 	cout << "prevIndices of given input" << endl;
// 	for (int i = 0; i <=n; i++)
// 		cout << prevIndices[i] << " ";
// 	cout << endl;

	return len;
}

int main()
{
	int arr[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("LIS size %d\n", LongestIncreasingSubsequence(arr, n));

	return 0;
}
