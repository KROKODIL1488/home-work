#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
//Задача 1
  int y, x;
  cin >> x >> y;
  while (x != y) {
    if (x>y) {
      x = x-y;
    }
    else {
      y = y-x;
    }
  }
  cout << x;
//задача 2
int n;
cin >> n;
vector<int> a; 
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = n - 1; i >= 0; i--){
        cout << a[i] << " ";

    }
//задача 3






    return 0;
}

