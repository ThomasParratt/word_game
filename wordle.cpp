#include <iostream>
#include <vector>

int main(void)
{
    std::string answer = "HELLO";
    std::vector<std::string> words; // will be the vector of 6 words
    int trys = 0;
    
    for (int i = 0; i < 6; i++)
    {
        words.push_back("_____"); // initialise all words as blank to start
    }
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << words[i] << std::endl; // print all blank words
    }

    for (int i = 0; i < 6; i++) // looping through trys
    {
        trys++;
        std::cout << std::endl;
        std::cout << "Attempt " << i + 1 << ": " << std::endl;
        std::string attempt;
        std::cin >> attempt; // take word input
        //validity checks for valid guess e.g. length == 5
        std::cout << std::endl;

        for (int i = 0; i < 6; i++) // looping through words
        {
            if (i < trys)
            {
                for (int j = 0; j < 5; j++) // looping through characters
                {
                    if (attempt[j] == answer[j])
                    {
                        if (i == trys - 1) // so that we only update the word on the current try
                            words[i][j] = attempt[j]; // updates the current word to contain the guessed characters
                        std::cout << "\033[32m" << words[i][j] << "\033[0m"; // prints the corrected guess characters
                    }
                    else
                    {
                        if (i == trys - 1)
                            words[i][j] = attempt[j]; // updates the current word to contain the guessed characters
                        std::cout << "\033[31m" << words[i][j] << "\033[0m"; // prints the corrected guess characters
                    }
                }
                std::cout << std::endl;
            }
            else
                std::cout << words[i] << std::endl;
        }

        if (words[i] == answer)
        {
            /*std::cout << std::endl;
            for (int i = 0; i < 6; i++)
                std::cout << words[i] << std::endl;

            std::cout << std::endl;*/
            std::cout << "SUCCESS!" << std::endl;
            return 0;
        }
        //words[i + 1] = words[i];
    }
    std::cout << "FAIL!" << std::endl;
    return 0;
}