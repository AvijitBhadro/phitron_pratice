#include <iostream>
#include <map>
#include <string>

int main() {
    std::string text = "this is a sample text is a sample text";
    std::map<std::string, int> wordFreq;

    // Count word frequency
    for (const std::string& word : text) {
        ++wordFreq[word];
    }

    std::string maxWord;
    int maxFreq = 0;

    // Find the maximum frequency and lexicographically smallest word
    for (const auto& entry : wordFreq) {
        if (entry.second > maxFreq || (entry.second == maxFreq && entry.first < maxWord)) {
            maxWord = entry.first;
            maxFreq = entry.second;
        }
    }

    // Print the result
    std::cout << "Maximum occurring word: " << maxWord << " (Frequency: " << maxFreq << ")" << std::endl;

    return 0;
}