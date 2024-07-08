/*
First official project
*/
#include <fmt/core.h>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int generateRandomNumber() 
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> distrib(0, 6);
    int random_number = distrib(gen);
    return random_number;
}

bool displayGame(string word)
{
    // Colors
    string colors[6] = {
        "\033[1;31m", // 0: red
        "\033[1;32m", // 1: green
        "\033[1;33m", // 2: yellow
        "\033[1;36m", // 3: cyan
        "\033[1;34m", // 4: blue
        "\033[0m"     // 5: reset
    };

    fmt::print("{}Welcome to this amazing game!!{}\n", colors[4], colors[5]);

    // Generate the hidden version of the word with underscores
    string hidden_word(word.size(), '_');

    while (hidden_word != word) {
        fmt::print("Word: {}\n", hidden_word);
        fmt::print("Guess a letter: ");
        char guess;
        cin >> guess;

        // Check if the guessed letter is in the word
        bool found = false;
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] == guess) {
                hidden_word[i] = guess;
                found = true;
            }
        }

        if (found) {
            fmt::print("{}Good guess!{}\n", colors[1], colors[5]);
        } else {
            fmt::print("{}Wrong guess!{}\n", colors[0], colors[5]);
        }
    }

    fmt::print("{}Congratulations! You've guessed the word: {}{}\n", colors[3], word, colors[5]);
    return true;
}

int main()
{
    string words[7] = {
        "minecraft",
        "pokemon",
        "aircraft",
        "linux",
        "klkgang",
        "github",
        "seven"
    };

    int index = generateRandomNumber();
    string word = words[index];
    fmt::print("[DEBUG] The word is {}\n", word);

    if (displayGame(word)) {
        fmt::print("");
        fmt::print("\033[1;34mTHANK YOU FOR PLAYING \033[0m\n");
    }

    return 0;
}