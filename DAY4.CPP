#include<iostream>
using namespace std;

const int R = 4;
const int C = 4;

//Bit Manipulation Revision 

int findOdd_occurence(int arr[] , int n){ // O(N) // O(1) // O(1)
    
    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        res = res ^ arr[i];
    }
    
    return res;
}

void TwoOddOccuring_naive_approach(int arr[] , int n){ // O(N^2) // O(1) // O(1)
    
    for(int i = 0 ; i < n ; i++){
        int count = 0;
        for(int j = 0 ; j < n ; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count%2 == 0){
            cout<<arr[i];
        }
    }
}

void TwoOddOccuring_efficient_approach(int arr[] , int n){ // idea - find XOR of all the numbers and then find the two numbers from the resultant XOR number 
                                                           // the set bit in the number will be having two different values for both the numbers;
    int x = 0;
    //finding xor of all elements in the array 
    for(int i = 0 ; i < n ; i++){
        x = x ^ arr[i];
    }
    // finding the rightmost set bit in the number 
    int k = x & (~(x-1));
    int res1 = 0 , res2 = 0;

    // finding the numbers as per the rightmost set bit
    for(int i = 0 ; i < n ; i++){
        if((arr[i]&k)!= 0){
            res1 = res1 ^ arr[i];
        }
        else{
            res2 = res2 ^ arr[i];
        }
    }

    cout<<res1<<" "<<res2;

}

void print_power_set(string s){
   
    int size = s.length();
    int power_set_size = (1 << size);
    for(int i = 0 ; i < power_set_size ; i++){
        for(int j = 0 ; j < size ; j++){
            if((i & (1 << j)) != 0){
                cout<<s[j];
            }
        
        }
        cout<<" ";
    }

}

// Todays learning content

void spiral_traversal_of_a_matrix(int matrix[R][C]){
   
   int top = 0 , right = C - 1 , bottom = R - 1 , left = 0;
    while(top <= bottom && left <= right){
        for(int i = top ; i <= right ; i++){
            cout<<matrix[top][i]<<" ";
        }
        top++;
        for(int i = top ; i <= bottom ; i++){
            cout<<matrix[i][right]<<" ";
        }
        right--;
        if(top <= bottom){
            for(int i = right ; i >= left ; i--){
                cout<<matrix[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left <= right){
            for(int i = bottom ; i >= right ; i++){
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }

    }
}

void search_element_in_sorted_matrix_efficient_my_approach(int matrix[R][C] , int element){
   
   for(int i = 0 ; i < C ; i++){
        if(matrix[i][0] > element){
            int j = i - 1;
            for(int k = 0 ; k < C ; k++)
            {
                if(matrix[j][k] == element){
                cout<<"Element found at "<<j<<" "<<k;
                return ;
            }
            }
        }
    }
    for(int i = 0 ; i < C ; i++){
        if(matrix[3][i] == element){
            cout<<"Element found at "<<3<<" "<<i;
            return;
            
        }
    }
    cout<<"Not found ";
    return ;
    
}

void search_element_in_sorted_matrix_efficient_gfg_approach(int matrix[R][C] , int element){

    int i = 0 , j = C - 1;
    while( i < R && j >= 0){
        if(matrix[i][j] == element){
            cout<<"Element is at : ("<<i<<","<<j<<")";
            return;
        }
        else if(matrix[i][j] > element){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"Element not found ";
    return;

}

// int matrix_median_efficient_solution(int matrix[R][C]){
//     int min = matrix[0][0] , max = matrix[0][C-1];
//     for(int i = 0 ; i < R ; i++){
//         if(matrix[i][0] < min){
//             min = matrix[i][R-1];
//         }
//         if(matrix[i][C-1] > max){
//             max = matrix[i][C-1];
//         }
//     }
//     int median_Position = (R*C + 1)/2;


// }
int main(){
    // int arr[]= {3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, n = 10;
    // TwoOddOccuring_naive_approach(arr,n);
    // string s = "anu";
    // print_power_set(s);

    int arr[][C] = {{10, 20, 30, 40},
    			    {15, 25, 35, 45},
    			    {27, 29, 35, 45},
    			    {32, 33, 39, 50}};
			   
	int x = 39;	   
    search_element_in_sorted_matrix_efficient_gfg_approach(arr,x);

}