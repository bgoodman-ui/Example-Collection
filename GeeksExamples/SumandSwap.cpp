#include<iostream>

//no array or vector
int main()
{
    int a;
    int b;

    std::cout<<"Give two numbers please: ";
    std::cin>>a>>b;
    std::cout<<"You gave "<<a<<" "<<b<<std::endl;
    std::cout<<"Here is them swapped"<<std::endl;

    int temp;
    temp = a;
    a = b;
    b = temp;
    std::cout<<a<<"::"<<b<<std::endl;
    std::cout<<"Here is your sum "<<a+b<<std::endl;
}