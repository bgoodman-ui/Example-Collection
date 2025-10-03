#include <iostream>
#include <vector>

void SelectionSort(std::vector<int> &arr)
{
    int n = arr.size(); 
    for(int i=0;i < n-1;i++)
    {
        //assume that current position is smallest
        int min = i;

        //go through unsorted to find actual minimum
        for(int j = i+1;j < n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}

void PrintArray(std::vector<int> &arr)
{
    for(int &val : arr)
    {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    std::vector<int> arr = {65,113,43,78,4,7,1};
    std::cout<<"Unsorted array : ";
    PrintArray(arr);
    SelectionSort(arr);
    std::cout<<"Sorted array : ";
    PrintArray(arr);
}
