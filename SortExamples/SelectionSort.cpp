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
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}
void SelectionSortLS(std::vector<int> &arr)
{
    int x = arr.size(); 
    for(int i=0;i < x-1;i++)
    {
        //assume that current position is largest
        int max = i;

        //go through unsorted to find actual maximum
        for(int j = i+1;j < x;j++)
        {
            if(arr[j]>arr[max])
            {
                max = j;
            }
        }
        std::swap(arr[i],arr[max]);
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
    std::cout<<"Sorted array smallest to largest : ";
    PrintArray(arr);
    SelectionSortLS(arr);
    std::cout<<"Sorted array largest to smallest : ";
    PrintArray(arr);
}
