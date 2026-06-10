#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R,C;
    cout << "Enter the Number of Rows : ";
    cin >> R;
    cout << "Enter the Number of Columns : ";
    cin >> C;
    vector<vector<int>> arr(R,vector<int>(C,0));
    cout << "Enter the Matrix\n";
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    
    int row, col;
    cout << "Enter the Index of Row : ";
    cin >> row;
    cout << "Enter the Index of Column : ";
    cin >> col;
    
    const vector<vector<int>> diff = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        int ar = row+diff[i][0], ac = col+diff[i][1];
        if(ar<R && ar>=0 && ac<C && ac>=0) {
            sum += arr[ar][ac];
        }
    }
    
    cout << "Adjacent Sum : " << sum << endl;
}s