/*
NAME - Jatin Singh Bisht
SID - 21105039
*/

#include <bits/stdc++.h>
using namespace std;

// LINEAR SEARCH

int LinearSearch(int arr[], int a){
    for (int i = 0;; i++){ //iterating the loop until the integer a is found
        if (arr[i] == a){
            return i; //returning index of a
        }
    }
    // else garbage value is returned.
}

// BINARY SEARCH

int BinarySearch(int arr[],int low,int high,int a){
    int l=low;
    int h=high;
    int mid = (l+h)/2;
    while(l<=h)//iterating until integer a is found or l>r
    {   
        if(arr[mid]>a){ 
            h = mid-1; //updating high
            mid = (l+h)/2; //updating mid
        }
        else if(arr[mid]<a){ //
            l = mid+1; //updating low
            mid = (l+h)/2; //updating mid
        }
        else{   
            return mid;
        }
    }

}

int BinarySearch(int arr[], int a){
    // creating search space of range[0,1]
    int low = 0; 
    int high = 1;

    while (arr[high] < a)
    {   
        low = high; //upating low 
        high = 2*high;    // doubling the search space   
    }

    return BinarySearch(arr,low,high,a);
}

int main()
{
    //sorted array
    int arr[8]={22, 33, 44, 59, 61, 64, 79, 99};

    int a;
    cout << "Enter integer to search: ";
    cin >> a;
    cout << endl;

    int idx_1=LinearSearch(arr, a); 
    int idx_2=BinarySearch(arr, a);
    if (idx_1!=idx_2){
        cout<<a<<" not Found"<<endl;
    }
    else{
        // a found
        //printing the index of a in array
        cout << "Index of " << a << " using LINEAR SEARCH : " <<idx_1<< endl;
        cout << "Index of " << a << " using BINARY SEARCH : " <<idx_2<< endl;
    }
    
}
