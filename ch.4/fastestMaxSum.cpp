// p.119

#include <iostream>
#include <vector>
using namespace std;

int fastestMaxSum(const vector<int>& A){
// psum과 0을 비교하여 더 큰값에 배열의 현재 값을 더함 == 0보다 크다면 더 하는 것이 더 큼
// 구간 합이 끊겼다는 것은 그 구간의 합이 0보다 작다는 뜻 == 그 구간을 더하는것에 이득이 없음

// == psum과 배열의 현재 값을 더한 값과 배열의 현재 값을 비교하여 더 큰 값을 dp에 저장
// dp의 최대 값을 리턴
  int psum = 0, ret = A[0];
  for(int i=0; i<A.size(); ++i){
    psum = max(psum + A[i], A[i]);
    ret = max(ret, psum);
  }
  return ret;
}

int main(){
  vector<int> A;
  int n, k;
  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> k;
    A.push_back(k);
  }
  cout << fastestMaxSum(A);
}
