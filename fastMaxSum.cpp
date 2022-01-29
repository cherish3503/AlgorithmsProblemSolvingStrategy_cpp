#include <iostream>
#include <vector>
using namespace std;

int fastMaxSum(const vector<int>& A, int lo, int hi){
  if(lo == hi) return A[lo];
  int mid = (lo+hi)/2;
  int left = A[mid], right = A[mid+1], sum = 0;
  for(int i = mid; i>=lo; --i){
    sum += A[i];
    left = max(left, sum);
  }
  sum = 0;
  for(int j = mid+1; j <= hi; ++j){
    sum+=A[j];
    right = max(right,sum);
  }
  int single = max(fastMaxSum(A,lo,mid),fastMaxSum(A,mid+1,hi));

  return max(left+right, single);
}

int main(){
  vector<int> A;
  int n, k;
  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> k;
    A.push_back(k);
  }
  cout << fastMaxSum(A, 0, A.size());
}
