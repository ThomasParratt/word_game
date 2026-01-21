#include <iostream>
#include <vector>
#include <fstream>
#include <random>

std::string randomWord()
{
    std::ifstream file("words.txt");
    if (!file) 
    {
        std::cerr << "Could not open the file!\n";
        exit(1);
    }

    std::vector<std::string> words;
    std::string word;
    while (file >> word) 
    {
        words.push_back(word);
    }

    if (words.empty()) 
    {
        std::cerr << "No words found!\n";
        exit(1);
    }

    // Randomly pick a word
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);

    return words[dis(gen)];
}

bool isWord(std::string word)
{
    std::ifstream file("words.txt");
    if (!file)
    {
        std::cerr << "Could not open the file!\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line == word)
            return true;
    }

    return false;
}

int main(void)
{
    std::string answer = randomWord();
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

    for (int k = 0; k < 6; k++) // looping through trys
    {
        trys++;
        std::cout << "Guess the word in 6 tries." << std::endl;
        std::cout << "If the letter is displayed in \033[32mgreen\033[0m it is in the correct spot." << std::endl;
        std::cout << "If the letter is displayed in \033[33morange\033[0m it is in the word but in the wrong spot." << std::endl;
        std::cout << "If the letter is displayed in \033[31mred\033[0m it is not in the word in any spot." << std::endl;
        std::cout << std::endl;
        std::cout << "Attempt " << trys << ": " << std::endl;
        std::vector<std::string> attempts(6);
        std::cin >> attempts[k]; // take word input
        //also need to check for valid characters
        if (attempts[k].size() != 5)
        {
            std::cout << "Word must be 5 characters long." << std::endl;
            trys--;
            k--;
            continue;
        }
        if (!isWord(attempts[k]))
        {
            std::cout << "That's not a word..." << std::endl;
            trys--;
            k--;
            continue;
        }
        std::cout << std::endl;

        for (int i = 0; i < 6; i++) // looping through words
        {
            if (i < trys)
            {
                std::string tempAnswer = answer;
                for (int j = 0; j < 5; j++) // looping through characters
                {
                    if (i == trys - 1) // so that we only update the word on the current try
                    {
                        words[i][j] = attempts[k][j]; // updates the current word to contain the guessed characters
                    }
                    if (words[i][j] == tempAnswer[j])
                    {
                        tempAnswer[j] = '*';
                    }
                }
                std::cout << "\r";
                for (int j = 0; j < 5; j++) // looping through characters
                {
                    if (words[i][j] == answer[j])
                    {
                        std::cout << "\033[32m" << words[i][j] << "\033[0m"; // prints the correctly guessed characters in green
                    }
                    else if (size_t pos = tempAnswer.find(words[i][j]); pos != std::string::npos)
                    {
                        // orange if character is in word but in wrong place
                        std::cout << "\033[33m" << words[i][j] << "\033[0m";
                        tempAnswer[pos] = '*';
                    }
                    else
                    {
                        std::cout << "\033[31m" << words[i][j] << "\033[0m"; // prints the incorrectly guessed characters in red
                    }
                }
                std::cout << std::endl;
            }
            else
                std::cout << words[i] << std::endl;
        }

        if (words[k] == answer)
        {
            std::cout << "WELL DONE!" << std::endl;
            return 0;
        }
    }
    std::cout << "Better luck next time!" << std::endl;
    std::cout << "The correct answer is: " << answer << std::endl;
    return 0;
}