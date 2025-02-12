#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Function declarations
bool isValidWord(const string &word, const unordered_set<char> &validLetters);
bool hasConsecutiveIdenticalLetters(const string &word);
unordered_set<string> generateInvalidPairs(const vector<string> &sides);
bool containsInvalidPair(const string &word, const unordered_set<string> &invalidPairs);
int computeCWS(const string &smallWord, const string &largeWord);
size_t computeLetterCount(const string &word1, const string &word2);
unordered_set<string> basicDict();
unordered_set<string> userValidDict(const unordered_set<char>& validLetters);
unordered_set<string> finalDict(const unordered_set<char>& validLetters, const unordered_set<string>& invalidPairs);
vector<tuple<int, int, string, string>> findValidSolutions(const unordered_set<string>& validWords);
void optimizationRank(vector<tuple<int, int, string, string>>& solutions);

bool givensTest(unordered_set<string> wordles){
    string connections = "givens";
    size_t mini = wordles.count(connections);
    if (mini > 0){
        return true;
    } else {
        return false;
    }
        
}


int main() {
    cout << "NYT Letterboxed" << endl;

    vector<string> sides(4);
    unordered_set<char> validLetters;
    bool debug = false;
    if (debug) {
        sides[0] = "teb";
        sides[1] = "sva";
        sides[2] = "wih";
        sides[3] = "ong";
        for (char c : sides[0]) validLetters.insert(c);
        for (char c : sides[1]) validLetters.insert(c);
        for (char c : sides[2]) validLetters.insert(c);
        for (char c : sides[3]) validLetters.insert(c);
    } else {
        for (int i = 0; i < 4; i++) {
            cout << "Side " << (i + 1) << ": ";
            cin >> sides[i];
            for (char c : sides[i]) validLetters.insert(c);
        }
    }

    unordered_set<string> invalidPairs = generateInvalidPairs(sides);
    unordered_set<string> validWords = finalDict(validLetters, invalidPairs);
    unordered_set<string> useableWords = basicDict();
    unordered_set<string> refinedwords = userValidDict(validLetters);
    vector<tuple<int, int, string, string>> solutions = findValidSolutions(validWords);

    optimizationRank(solutions);

    if (!solutions.empty()) {
        auto [best_letter_count, best_cws, best_word1, best_word2] = solutions.front();
       // cout << "basic dict: " << givensTest(useableWords)<< " userinputdict: " << givensTest(refinedwords);
        cout << "\nOptimal Solution: " << best_word1 << " " << best_word2 << "\n\n" ;
        cout << "Solutions:\n";
        int rank = 1;
        for (const auto &[letter_count, cws, word1, word2] : solutions) {
            cout << rank++ << ". " << word1 << " " << word2 << "\n";
        }
    } else {
        cout << "No valid solutions found!" << endl;
    }
    return 0;
}

// Function definitions
bool isValidWord(const string &word, const unordered_set<char> &validLetters) {
    for (char c : word) {
        if (validLetters.find(c) == validLetters.end()) return false;
    }
    return true;
}

bool hasConsecutiveIdenticalLetters(const string &word) {
    for (size_t i = 1; i < word.size(); i++) {
        if (word[i] == word[i - 1]) return true;
    }
    return false;
}

unordered_set<string> generateInvalidPairs(const vector<string> &sides) {
    unordered_set<string> invalidPairs;
    for (const string &side : sides) {
        for (size_t i = 0; i < side.size(); i++) {
            for (size_t j = i + 1; j < side.size(); j++) {
                invalidPairs.insert({side[i], side[j]});
                invalidPairs.insert({side[j], side[i]});
            }
        }
    }
    return invalidPairs;
}

bool containsInvalidPair(const string &word, const unordered_set<string> &invalidPairs) {
    for (size_t i = 0; i < word.size() - 1; i++) {
        if (invalidPairs.find({word[i], word[i + 1]}) != invalidPairs.end()) return true;
    }
    return false;
}

int computeCWS(const string &smallWord, const string &largeWord) {
    unordered_set<char> uniqueLetters(smallWord.begin(), smallWord.end());
    int score = 0;
    for (char c : uniqueLetters) {
        score += count(largeWord.begin(), largeWord.end(), c);
    }
    return max(score, 1);
}

size_t computeLetterCount(const string &word1, const string &word2) {
    return word1.size() + word2.size();
}

unordered_set<string> basicDict() {
    unordered_set<string> validWords;
    string strands = "givens";
    validWords.insert(strands);
    ifstream dict("/usr/share/dict/words");
    string word;
    while (dict >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word != "bohawn" && word != "bhowani" && word != "bhowanis" && word != "genevois" && word.size() >= 3 && word.size() <= 13 && !hasConsecutiveIdenticalLetters(word)) {
            validWords.insert(word);
        }
    }
    dict.close();
    return validWords;
}

unordered_set<string> userValidDict(const unordered_set<char>& validLetters) {
    unordered_set<string> basicWords = basicDict();
    unordered_set<string> filteredWords;
    for (const string& word : basicWords) {
        if (isValidWord(word, validLetters)) {
            filteredWords.insert(word);
        }
    }
    return filteredWords;
}

unordered_set<string> finalDict(const unordered_set<char>& validLetters, const unordered_set<string>& invalidPairs) {
    unordered_set<string> userWords = userValidDict(validLetters);
    unordered_set<string> finalWords;
    for (const string& word : userWords) {
        if (!containsInvalidPair(word, invalidPairs)) {
            finalWords.insert(word);
        }
    }
    return finalWords;
}

void optimizationRank(vector<tuple<int, int, string, string>>& solutions) {
    sort(solutions.begin(), solutions.end(), [](const auto& a, const auto& b) {
        return get<0>(a) < get<0>(b);
    });
    stable_sort(solutions.begin(), solutions.end(), [](const auto& a, const auto& b) {
        return get<1>(a) < get<1>(b);
    });
}

vector<tuple<int, int, string, string>> findValidSolutions(const unordered_set<string>& validWords) {
    vector<tuple<int, int, string, string>> solutions;
    for (const string &word1 : validWords) {
        for (const string &word2 : validWords) {
            if (word1.back() == word2.front()) {
                unordered_set<char> usedLetters(word1.begin(), word1.end());
                usedLetters.insert(word2.begin(), word2.end());
                if (usedLetters.size() == 12 && word1.size() + word2.size() >= 13 && word1.size() + word2.size() <= 19) {
                    solutions.emplace_back(computeCWS(word1, word2), computeLetterCount(word1, word2), word1, word2);
                }
            }
        }
    }
    return solutions;
}


