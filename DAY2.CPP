#include<iostream>
using namespace std;

const int R = 4;
const int C = 4;

void bTraversal(int matrix[R][C]){ //0(R+C) T.C // 0(1) //0(1)

    if(R == 1){
        for(int i = 0 ; i < C ; i++){
            cout<<(matrix[0][i])<<" ";
        }
    }
    else if(C == 1){
        for(int i = 0 ; i < R ; i++){
            cout<<(matrix[i][0])<<" ";
        }
    }
    else{
        for(int i = 0 ; i < C ; i++){
            cout<<(matrix[0][i])<<" ";
        }
        for(int i = 0 ; i < R ; i++){
            cout<<(matrix[i][C-1])<<" ";
        }
        for(int i = C - 2 ; i >= 0 ; i--){
            cout<<(matrix[R-1][i])<<" ";
        }
        for(int i = R-2 ; i>= 1 ; i--){
            cout<<(matrix[i][0])<<" ";
        }
    }
}

void Transpose_of_a_matrix(int matrix[R][C]){

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void transpose_of_a_matrix_naive_approach(int matrix[R][C]){ //O(R*C) //O(R*C) //O(R*C)
    
    int transpose[R][C];
    for(int i = 0  ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            transpose[j][i] = matrix[i][j];
        }
    }
    for(int i = 0 ; i < R ; i++ ){
        for(int j = 0 ; j < C ; j++){
            matrix[i][j] = transpose[i][j];
        }
    }

}


int main()
{	
	int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{13, 14, 15, 16}};
    transpose_of_a_matrix_naive_approach(arr);
    for(int i = 0; i < 4; i++)
	{
        for(int j = 0; j < 4; j++)
		{
            cout << arr[i][j] << " ";
		}
        cout << endl;
    }	
    return 0;
}

