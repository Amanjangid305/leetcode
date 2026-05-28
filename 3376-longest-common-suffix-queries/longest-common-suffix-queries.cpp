#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    // Flat struct representing a single node in the vector
    struct FlatNode {
        int children[26];   // Stores index integers instead of pointer references
        int best_word_idx;

        FlatNode() {
            std::fill(children, children + 26, -1); // -1 means no child exists
            best_word_idx = -1;
        }
    };

    std::vector<FlatNode> trie;

    void updateBestIndex(int node_id, int new_idx, const std::vector<std::string>& wordsContainer) {
        if (trie[node_id].best_word_idx == -1) {
            trie[node_id].best_word_idx = new_idx;
            return;
        }

        int curr_idx = trie[node_id].best_word_idx;
        if (wordsContainer[new_idx].length() < wordsContainer[curr_idx].length()) {
            trie[node_id].best_word_idx = new_idx;
        } 
        else if (wordsContainer[new_idx].length() == wordsContainer[curr_idx].length()) {
            if (new_idx < curr_idx) {
                trie[node_id].best_word_idx = new_idx;
            }
        }
    }

    void insert(const std::string& word, int word_idx, const std::vector<std::string>& wordsContainer) {
        int curr_id = 0; // Start at the root node (index 0)
        updateBestIndex(curr_id, word_idx, wordsContainer);

        for (int i = word.length() - 1; i >= 0; --i) {
            int char_idx = word[i] - 'a';
            
            // If the child node doesn't exist, create it by appending a new node to the vector
            if (trie[curr_id].children[char_idx] == -1) {
                trie[curr_id].children[char_idx] = trie.size();
                trie.emplace_back(); // Push a fresh node instance
            }
            
            curr_id = trie[curr_id].children[char_idx];
            updateBestIndex(curr_id, word_idx, wordsContainer);
        }
    }

    int search(const std::string& query) {
        int curr_id = 0;
        int last_valid_idx = trie[0].best_word_idx;

        for (int i = query.length() - 1; i >= 0; --i) {
            int char_idx = query[i] - 'a';
            if (trie[curr_id].children[char_idx] == -1) {
                break;
            }
            curr_id = trie[curr_id].children[char_idx];
            last_valid_idx = trie[curr_id].best_word_idx;
        }
        return last_valid_idx;
    }

public:
    std::vector<int> stringIndices(std::vector<std::string>& wordsContainer, std::vector<std::string>& wordsQuery) {
        trie.clear();
        trie.emplace_back(); // Initialize the root node at index 0

        // Build Trie
        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        // Process Queries
        std::vector<int> ans;
        ans.reserve(wordsQuery.size()); // Small optimization to prevent dynamic resizing overhead
        for (const std::string& query : wordsQuery) {
            ans.push_back(search(query));
        }

        return ans;
    }
};