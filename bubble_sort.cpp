
#include<iostream>
using namespace std;

void bubbleSort(int arr[],int size){
    for(int i =0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {1,14,5,125,15,66,21,251,61,61,7,135,36,136};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,size);
    cout<<"Sorted Array: \n";
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
