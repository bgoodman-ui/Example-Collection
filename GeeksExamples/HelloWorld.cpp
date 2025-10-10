#include<iostream>

int main()
{
    //cout Hello World
    std::cout<<"Hello World"<<std::endl;
    //cout hello world 10 times
    for (int i = 0; i<10;i++)
    {
        std::cout<<"Hello World "<<i+1<<std::endl;
    }
    //ask user how many times to say hello world
    int n;
    std::cout<<"Say Hello World, how many times ";
    std::cin>>n;
    for(int j = 0; j < n; j++)
    {
        std::cout<<"Hello World "<<j+1<<std::endl;
    }
}