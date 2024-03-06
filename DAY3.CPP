#include<iostream>
using namespace std;

const int R = 4;
const int C = 4;

void transpose_of_a_matrix_naive_approach(int matrix[R][C]){ //O(R*C) // O(R*C) // O(R*C)
    
    int ans[R][C];

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            ans[i][j] = matrix[j][i];
        }
    }

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            matrix[i][j] = ans[i][j];
        }
    }
    
}

void transpose_of_a_matix_efficient_solution(int matrix[R][C]){ // idea - diaognal elements remains same in a matrix // the elements lying above the dioagnal element can be swapped with the lower triangle
                                                                // O(R*C) // O(R*C) // O(1)
    for(int i = 0 ; i < R ; i++){
        for(int j = i + 1 ; j < C ; j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }

}

void Rotate_matrix_by_90_naive_approach(int matrix[R][C]){ //0(N^2) // 0(N^2) //O(N^2)
    
    int temp[R][C];
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            temp[R-j-1][i] = matrix[i][j];     
        }
    }
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            matrix[i][j] = temp[i][j];
        }
    }

}

void Rotate_matrix_by_90_efficient_solution(int matrix[R][C]){ // idea - first transpose the matrix then reverse the columns
    
    //transpose
    for(int i = 0 ; i < R ; i++){
        for(int j = i + 1 ; j < C ; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // reversal of the columns
    for(int i = 0 ; i < R ; i++){
        int low = 0 , high = R - 1;
        while(low < high){
            swap(matrix[low][i],matrix[high][i]);
            low++;
            high--;
        }
    }

}

void Rotate_matrix_by_90_article_approach(int matrix[R][C]){
  
   for(int i = 0 ; i < R / 2 ; i++){

    for(int j = i ; j < R - i - 1 ; j++){

        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][R-1-i];
        matrix[j][R-1-i] = matrix[R-1-i][R-1-j];
        matrix[R-1-i][R-1-j] = matrix[R-1-j][i];
        matrix[R-1-j][i] = temp;
    }

   } 
}

void spiral_traversal_of_matrix(int matrix[R][C]){
    
    int top = 0 , left = 0 , bottom = R - 1 , right = C - 1;
    while(top <= bottom && left<= right){
        //top row 
        for(int i = left ; i <= right ; i++){
            cout<<matrix[top][i]<<" ";
        }
        top++;

        //right column
        for(int i = top ; i <= bottom ; i++){
            cout<<matrix[i][right]<<" ";
        }
        right--;
        if(top <= bottom){
        //bottom row 
            for(int i = right ; i >= left ; i--){
                cout<<matrix[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left <= right){
        //left column 
            for(int i = bottom ; i >= right ; i--){
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }
    }
}

// BitManipulation Revision 

void isSet_naive_approach(int n , int k){ //O(k) //O(1) //O(1) 

    int x = 1 ;
    for(int i = 0 ; i < k - 1 ; i++){
        x = x * 2;
    }
    if((n&x) != 0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}

void isSet_another_naive_approach(int n , int k){

    for(int i = 0 ; i < (k - 1) ; i++){
        n = n / 2;
    }    
    if((n&1)!= 0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

}

void isSet_efficient_solution(int n , int k){
    
    int x = (1 << (k - 1));
    if((n&x) != 0){
        cout<<"True";
    }
    else{
        cout<<"false";
    }

}

void isSet_another_efficient_solution(int n , int k){
    
    n = (n >> (k - 1));
    if((n&1) != 0){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

}

int Count_set_bits_my_approach(int n){

    int count = 0 ;
    while(n != 0){
        count = count + (n & 1); // Brian Kerningham Algorithm
        n = n >> 1; 
    }
    return count;

}

int Count_set_Bits_efficient_approach(int n){ 
    
    int count = 0 ;
    while(n != 0){
        n = n & (n - 1);
        count++;
    }
    return count;

}

int table[256];

void initialize(int n){
    table[0] = 0;
    for(int i = 1 ; i < 256 ; i++){
        table[i] = table[i&(i-1)] + 1;
    }
}

int count_bits(int n){
    return table[n&255] + table[(n>>8)&255] + table[(n>>16)&255] + table[(n>>24)&255];
}

bool Power_of_2(int n){
    int count = 0;
    while(n != 0){
        n = n & (n - 1);
        count++;
    }
    if(count == 1){
        return true;
    }
    return false;
}

bool Power_of_2_efficient_solution(int n){
    if( n == 0){
        return false;
    }
    else{
        return ((n&(n - 1)) == 0);
    } 
}
int main(){

    int matrix[4][4] = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12} , {13,14,15,16}};
    spiral_traversal_of_matrix(matrix);
    
    // for(int i = 0 ; i < R ; i++){
    //     for(int j = 0 ; j < C ; j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int number = 5;
    // int k = 3;
    cout<<"is bit set or not : "<<isSet_another_efficient_solution(number);

}