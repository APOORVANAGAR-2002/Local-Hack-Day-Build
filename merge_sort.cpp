#include<iostream>
using namespace std;

void mergeArray(int arr[], int left[], int right[], int nL, int nR)
{
    int i = 0,j = 0,k = 0;
    while(i< nL && j<nR)
    {
        if (left[i]<=right[j])
        {
            arr[k] = left[i];
            i = i+1;
        }
        else
        {
            arr[k] = right[j];
            j = j+1;
        }
        k = k+1;
    }
    while(i<nL)
    {
        arr[k] = left[i];
        i = i+1;
        k = k+1;
    }
    while(j<nR)
    {
        arr[k] = right[j];
        j = j+1;
        k = k+1;
    }

}
void mergeSort(int Array[], int length)
{
    if (length<2)
        return ;
    int mid = length/2;
    int l[mid], r[length-mid];
    for(int i=0;i<mid;i++)
        {
            l[i] = Array[i];
        }
    for(int j=mid;j<length;j++)
        {
            r[j-mid] = Array[j];
        }

    mergeSort(l, mid);

    mergeSort(r, length-mid);

    mergeArray(Array, l, r, mid, length-mid);
}

int main()
{
    int A[] = {2,4,1,6,8,5,3,7};
    cout<<"Initial list: ";
    for(int i=0;i<8;i++)
        cout<<A[i]<<" ";
    mergeSort(A, 8);

    cout<<"\n"<<"Sorted list: ";
    for (int i=0;i<8;i++)
        cout<<A[i]<<" ";
}

/*
            OUTPUT:
    Initial list: 2 4 1 6 8 5 3 7
    Sorted list: 1 2 3 4 5 6 7 8

    Time Complexity: O(nlogn)
*/
