class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        // // Using Vector
        // if(sentence1.size() < sentence2.size()) swap(sentence1, sentence2);

        // stringstream ss1(sentence1);
        // stringstream ss2(sentence2);

        // string word1, word2;
        // vector<string> words1, words2;

        // while(ss1 >> word1) words1.push_back(word1);
        // while(ss2 >> word2) words2.push_back(word2);

        // int i = 0, j = words1.size() - 1;
        // int x = 0, y = words2.size() - 1;

        // while(i < words1.size() && x < words2.size() && words2[x] == words1[i]) {
        //     x++;
        //     i++;
        // }

        // while(x <= y && words2[y] == words1[j]) {
        //     j--;
        //     y--;
        // }

        // return y < x;

        // Using Deque
        if(sentence1.size() < sentence2.size()) swap(sentence1, sentence2);

        stringstream ss1(sentence1);
        stringstream ss2(sentence2);

        string word1, word2;
        deque<string> words1, words2;

        while(ss1 >> word1) words1.push_back(word1);
        while(ss2 >> word2) words2.push_back(word2);

        while(!words1.empty() && !words2.empty() && words1.front() == words2.front()) {
            words1.pop_front();
            words2.pop_front();
        }

        while(!words1.empty() && !words2.empty() && words1.back() == words2.back()) {
            words1.pop_back();
            words2.pop_back();
        }

        return words2.empty();
    }
};