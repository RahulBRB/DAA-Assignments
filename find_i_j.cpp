// Write a program for finding i and j in an array A for any key such that A[j]2+ A[i]2== key

#include<iostream>
using namespace std;

void findIndices(int A[],int size,int key){
    int i,j;
    bool found = false;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(A[i]*A[i]+A[j]*A[j]==key){
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }
    if(found){
        cout<<"Indices found. i: "<<i<<" j: "<<j<<endl;
    }else{
        cout<<"Indices not found, the key was "<<key<<endl;
    }

}

int main(){
    int A[]={1,4,2,3,6,7,8,5,9,0};
    int size = sizeof(A)/sizeof(A[0]);
    int key = 58;

    findIndices(A,size,key);

    return 0;
}
