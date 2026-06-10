#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter the First String : ";
    cin >> str1;
    cout << "Enter the Second String : ";
    cin >> str2;
    
    int R = str1.length()+1, C = str2.length()+1;
    int maxSub = 0;
    vector<vector<int>> arr(R,vector<int>(C,0));
    for(int row = 1; row < R; row++) {
        for(int col = 1; col < C; col++) {
            if(str1[row-1] == str2[col-1]){
                arr[row][col] = arr[row-1][col-1]+1;
                if(arr[row][col] > maxSub){
                    maxSub = arr[row][col];
                }
            }
        }
    }
    
    cout << "Length of Longest Common Substring is : " << maxSub << endl;
    
}