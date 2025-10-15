#include<iostream>
//program that tells you how big your variables are
//int,float,double,char
int main()
{
    //just use sizeof
    int integer;
    float floating;
    double doubling;
    char character;
    

    std::cout<<"Size of integer is "<<sizeof(integer)<<"\n";
    std::cout<<"Size of float is "<<sizeof(floating)<<"\n";
    std::cout<<"Size of double is "<<sizeof(doubling)<<"\n";
    std::cout<<"Size of char is "<<sizeof(character)<<"\n";
    std::cout<<"\n";
    integer = 3;
    floating = 3.1345;
    doubling = 15.4;
    character = 't';
    std::cout<<"Size of integer 3 is "<<sizeof(integer)<<"\n";
    std::cout<<"Size of float 3.1345 is "<<sizeof(floating)<<"\n";
    std::cout<<"Size of double 15.4 is "<<sizeof(doubling)<<"\n";
    std::cout<<"Size of char t is "<<sizeof(character)<<"\n";
    std::cout<<"\n";
    std::cout<<"They are the same because a type represents how much maximum data they can hold"<<std::endl;

}