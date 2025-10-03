#include<iostream>
#include<vector>

//bubblesort is sorting method meant to sort vectors
void BubbleSortLS(std::vector<int> &values)
{
int n = values.size();

//outer loop for number of elements to be sorted
for(int i = 0; i < n-1; i++ )
{
    for(int j = 0; j < n-1; j++)
    {
        if(values[j] < values[j + 1])
        {
            std::swap(values[j],values[j+1]);

        }
    }
}
}
void BubbleSortSL(std::vector<int> &values)
{
int x = values.size();

//outer loop for number of elements to be sorted
for(int i = 0; i < x-1; i++ )
{
    for(int j = 0; j < x-1; j++)
    {
        if(values[j] > values[j + 1])
        {
            std::swap(values[j],values[j+1]);

        }
    }
}
}
void PrintValues(std::vector<int> &values)
{
    for( auto i : values)
    {
        std::cout<<i<<" ";

    }
    std::cout<<std::endl;
}
int main()
{
    std::vector<int> values = {67,43,1,2,3,7,99,1007,87,32,34};
    std::cout<<"Unsorted array : ";
    PrintValues(values);
    BubbleSortLS(values);
    std::cout<<"Sorted vector from largest to smallest : ";
    PrintValues(values);
    BubbleSortSL(values);
    std::cout<<"Sorted vector from smallest to largest : ";
    PrintValues(values);
    
}