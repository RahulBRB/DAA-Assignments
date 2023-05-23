// Given an array. Let us assume that there can be duplicates in the list. Write a program to search
// for an element in the list in such a way that we get the highest index if there are duplicates.


#include<iostream>
using namespace std;

int highestindex(int array[],int size,int target){
    int highestindex = -1;
    for(int i=0;i<size;i++){
        if(array[i]==target){
            highestindex=i;
        }
    }
    return highestindex;

}

int main(){
    
    int n;
    cout<<"How many numbers you want to add in the array?: ";
    cin>>n;

    int array[n];

    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++){
        cin>>array[i];
    };

    int element;
    cout<<"\nWhich element you want to find the index for?: ";
    cin>>element;

    int size = sizeof(array)/sizeof(array[0]);
    int result = highestindex(array,size,element);

    if(result!=-1){
        cout<<"Index of the element "<<element<<" is "<<result<<endl;
    }
    else{
        cout<<"Element not found in array! \n";
    }

    return 0;
}
