#include <iostream>
#include <vector>

int main(void)
{
    std::string answer = "HELLO";
    std::vector<std::string> words;
    int count = 0;
    
    for (int i = 0; i < 6; i++)
    {
        words.push_back("_____");
    }
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << words[i] << std::endl;
    }

    for (int i = 0; i < 6; i++)
    {
        count++;
        std::cout << std::endl;
        std::cout << "Attempt " << i + 1 << ": " << std::endl;
        std::string attempt;
        std::cin >> attempt;
        //validity checks for valid guess e.g. length == 5
        std::cout << std::endl;

        for (int i = 0; i < 6; i++)
        {
            if (i < count)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (attempt[j] == answer[j])
                    {
                        if (i == count - 1)
                            words[i][j] = attempt[j];
                        std::cout << "\033[32m" << words[i][j] << "\033[0m";
                    }
                    else
                    {
                        if (i == count - 1)
                            words[i][j] = '_';
                        std::cout << words[i][j];
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