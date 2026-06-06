#include <iostream>
#include <vector>
using namespace std;

vector<long int> colMax(const vector<vector<long int>>& arr,int col,int row){
    long int Fmax = 0L, Smax = 0L;
    for(int r = 0; r < row; r++){
        if(arr[r][col] > Fmax) {
            Smax = Fmax;
            Fmax = arr[r][col];
        } else if(arr[r][col] > Smax) {
            Smax = arr[r][col];
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
            if(j == 0){
                dparr[i][j] = arr[i][j];
            }
        }
    }
    for(int col=1; col<C; col++){
        vector<long int> FSmax = colMax(dparr,col-1,R);
        for(int row=0; row<R; row++){
            dparr[row][col] = (dparr[row][col-1]==FSmax[0])?
            (arr[row][col]+FSmax[1]):(arr[row][col]+FSmax[0]);
        }
    }
    
    long int maximum = colMax(dparr,C-1,R)[0];
    cout << "Maximum Value : " << maximum;
}