#include <iostream>
#include <vector>
using namespace std;

vector<long int> rowMax(const vector<vector<long int>>& arr,int row,int col){
    long int Fmax = 0L, Smax = 0L;
    for(int c = 0; c < col; c++){
        if(arr[row][c] > Fmax) {
            Smax = Fmax;
            Fmax = arr[row][c];
        } else if(arr[row][c] > Smax) {
            Smax = arr[row][c];
        }
    }
    return {Fmax,Smax};
}

int main() {
    int R,C;
    cout << "Enter the Number of Rows : ";
    cin >> R;
    cout << "Enter the Number of Columns : ";
    cin >> C;
    vector<vector<int>> arr(R,vector<int>(C));
    vector<vector<long int>> dparr(R,vector<long int>(C));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
            if(i == 0){
                dparr[i][j] = arr[i][j];
            }
        }
    }
    for(int row=1; row<R; row++){
        vector<long int> FSmax = rowMax(dparr,row-1,C);
        for(int col=0; col<C; col++){
            dparr[row][col] = (dparr[row-1][col]==FSmax[0])?
            (arr[row][col]+FSmax[1]):(arr[row][col]+FSmax[0]);
        }
    }
    
    long int maximum = rowMax(dparr,R-1,C)[0];
    cout << "Maximum Value : " << maximum;
}