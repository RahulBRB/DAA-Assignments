// Given key in a sorted array A with distinct values. Write a program to find i, j, k such that A[i] + A[j] + A[k] == key.

#include<iostream>
using namespace std;

void findIndices(int A[],int size,int key){
    int i,j,k;
    bool found = false;
    for(i=0;i<size-2;i++){
        j=i+1;
        k=size-1;

        while(j<k){
            int sum = A[i]+A[j]+A[k];

            if (sum==key){
                found=true;
                break;               
            }
            else if(sum<key){
                j++;
            }else{
                k--;
            }
        }
        if(found){
            break;
        }
    }
    if(found){
        cout<<"Found. Indices are i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
    }else{
        cout<<"Indices not found. \n";
    }
}

int main(){
    int A[] = {6, 1, 0, 2, 4, 7, 10};
    int size = sizeof(A) / sizeof(A[0]);
    int key = 6;

    findIndices(A, size, key);

    return 0;
}
