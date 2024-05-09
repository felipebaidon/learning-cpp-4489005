// Learning C++ 
// Challenge 02_13
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>

int main(){
    int nums[5] = {1,23,32,24,337};
    float result; 

    // Write your code here
    for(auto num : nums)
    {
        result += num;
    }

    result = result/5;
    
    std::cout << "The average is " << result << std::endl;
    
    std::cout << std::endl << std::endl;

    return (0);
}
