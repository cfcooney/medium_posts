#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
 
template <class Container>
void split_string(const std::string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim))
    {
        cont.push_back(token);
    }
}

void print_results(std::vector<int> vector)
    {
        for (int i = 0; i < vector.size(); i++)
        {
            std::cout << vector[i] << "\t";
        }
        std::cout << "\n";
    }

int main()
{
    //Example 1
    std::string s("ciaran cooney");
    if (s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    std::cout << "Example 1: " << "\n";
    std::cout << s << std::endl;

    //Example 2
    std::string s1("ciaran cooney");
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        *it = toupper(*it);
    }
    std::cout << "Example 2: " << "\n";
    std::cout << s1 << std::endl;

    //Example 3
    std::string s2("ciaran cooney");
    std::vector<std::string> cont;
    char dlim = ' ';  
    split_string(s2, cont, dlim);
    for (std::string &str : cont)
    {
        if (str.begin() != str.end())
        {
            auto it = str.begin();
            *it = toupper(*it);
        }
    }
    std::string strUp = cont[0] + ' ' + cont[1];
    std::cout << "Example 3: " << "\n";
    std::cout << strUp << std::endl;  
    
    //Example 4
    std::vector<std::string> text = {"Hello", "there,", "my", "name", "is", "Ciaran"};
    std::cout << "Example 4 : " << "\n";
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); it++)
    {
        std::cout << *it << " ";
        
    }
    std::cout << "\n";
    

    //Example 5
    std::vector<int> vecA = {0,1,0,0,0,1,0,1,1,1};
    std::vector<int> vecB = {0,1,1,1,0,0,0,1,0,0};
    std::vector<int> result;
    auto itA = vecA.begin();
    auto itB = vecB.begin();
    while (itA != vecA.end())
    {
        if (*itA == *itB)
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }
        itA++;
        itB++;
    }
    std::cout << "Example 5: " << "\n";
    print_results(result);
    
    //Example 6
    std::vector<int> nums = {1,2,3,4};
    std::vector<int>::iterator it2 = nums.begin();
    std::cout << "Example 6: " << "\n";
    advance(it2, 1); //increments an iterator
    std::cout << "advance: " << *it2 << "\n";

    auto it3 = next(it2, 2); //returns an iterator
    std::cout << "next: " << *it3 << std::endl;

    auto it4 = prev(it3, 1);
    std::cout << "prev: " << *it4 << std::endl;

   //Example 7
   std::vector<int> sequence1 = {1,2,3,7,8,9,10};
   std::vector<int> sequence2 = {4,5,6};
   auto it = sequence1.begin();
   advance(it, 3);
   copy(sequence2.begin(), sequence2.end(), inserter(sequence1, it));

   std::cout << "Example 7: " << "\n";
   for (int &i : sequence1)
   {
       std::cout << i << ", ";
   }
}