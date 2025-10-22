#include <iostream>
#include  <list>
#include <string> 
#include <algorithm>
#include <vector>

struct Command {
    std::string name;
    std::vector<long long> arg;
};

std::list<int>::iterator iter_at(std::list<int> &numbers, std::size_t idx)
{
    if(idx > numbers.size())
    {
        return numbers.end();
    }
    auto it = numbers.begin();
    for(std::size_t i=0; i< idx; ++i)
    {
        ++it;
    }
    return it;
}

static bool splice(std::list<int> &numbers, const Command &cmd)
{
    std::size_t idx = cmd.arg[0];
    if (idx >0 && idx < numbers.size())
    {
        numbers.splice(numbers.begin(),numbers,next(numbers.begin(),idx),numbers.end());
    }
    else
    {
        return false;
    }
    std::cout<<"after splice ";
    for(auto i : numbers)
    std::cout<<i<< " ";
    std::cout<<std::endl;
    return true;
}

int main ()
{
    std::list<int> numbers = {10,20,30,40,50};
    std::size_t idx;
    std::cout<<"initial list ";
    for(auto i : numbers)
    std::cout<<i<< " ";
    std::cout<<std::endl;
    std::cout<<"Insert the index value you want to use: ";
    std::cin>>idx;
    std::cout<<std::endl;
    auto it = iter_at(numbers,idx);
    std::cout<<" index is "<< *it <<std::endl;
    Command cmd;
    cmd.name = "splice";
    cmd.arg.push_back(idx);
    std::cout<<"list will now be spliced at index"<<std::endl;
    splice(numbers, cmd);
    
}