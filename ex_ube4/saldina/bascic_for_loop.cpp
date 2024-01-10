#include <iostream>
#include <vector>


int main()
    {

        std::vector<int>numbers;
      // numbers.push_back(0);

        for(int i =0; i < 10; i++) {
            numbers.push_back(i);
        }
        
        for(int number : numbers) {
            std::cout << number << std::endl;
        }
        //std::cin.get();

    }