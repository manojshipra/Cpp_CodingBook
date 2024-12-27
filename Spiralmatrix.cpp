// Spiral accessing and modifying of elements in a matrix , here done in a reverse order 
#include <iostream>
using namespace std;

int main(){
    int N = 3;
    int matrix[N][N];
    int value = N*N;
    int top=0,bottom=N-1,left=0,right=N-1;
    while(top<=bottom && left<=right){
        //fill from right to left 
        for(int i=right;i>=left;i--) matrix[top][i]=value--;
        top++;
        // fill from top to bottom
        for(int i=top;i<=bottom;i++) matrix[i][left]=value--;
        left++;
        //fill from left to right
        if(top<=bottom){
            for(int i=left;i<=right;i++) matrix[bottom][i]=value--;
            bottom--;
        }
        // fill from bottom to top
        if(left<=right){
            for(int i=bottom;i>=top;i--) matrix[i][right]=value--;
            right--;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
