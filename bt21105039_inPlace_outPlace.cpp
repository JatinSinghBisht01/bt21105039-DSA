

/* 

Jatin Singh Bisht
21105039


Ques 1
An "In-Place" sorting algorithm is algorithm which uses constant space (O(1)) for producing the output.
For example sorting the array with the help of input array without using any external memory for carrying out the desired operations. 
Where as "Out-Place" sorting  needs extra space{generally O(n)- n is size of array} for carrying out the operations and producing the desired output.
For example sorting the array using stack or queue*/


//Ques - 2

#include <iostream>
using namespace std;
// Insertion Sort(In-Place)
void insertion_sort_IP(int arr[],int n){
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

//Insertion Sort (Out-Place)
void out_place_InsertionSort(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    out_place_InsertionSort(arr,si+1,ei);
}
//Print Array
void print(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    //Taking Input 
    cout<<"Enter Array Length: ";
    cin>>n;
    int arr[n],arr2[n];
    cout<<"Enter Array: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    insertion_sort_IP(arr,n);
    cout<<endl;
    cout<<"In-Place Sort : ";
    //printing array
    print(arr,n);
    cout<<endl;
    out_place_InsertionSort(arr2,0,n-1);
    cout<<"Out-Place Sort : ";
    //printing the array
    print(arr,n);
    cout<<endl;

}

/*
Ques - 3
While applying in-place techniques to an algorithm is challenging,
 applying out-of-place techniques is simple, but does raise the space complexity
  of the algorithm.for example to reverse the array using in-place sort 
  we have to swap the array elements until middle of array is reached,
  whereas while using out-place sort technique we can use an external stack(array) to reverse array 
  adding O(n) extra space to the program.Bubble sort, Selection Sort, Insertion Sort, Heapsort 
  are examples of in-place sorting techniques. Merge sort and Radix sort are examples of out-place sorting.
*/

//5 1 9 4 0 8
