#include <string>
#include <vector>

// ============================= Alphabet Trie =============================

struct Trie {
    struct Node {
        int next[26];
        int count = 0;

        Node() {
            for (int i = 0; i < 26; ++i) next[i] = -1;
        }
    };

    std::vector<Node> nodes;

    Trie() {
        nodes.emplace_back();
    }

    void insert(const std::string& word) {
        int node = 0;
        for (char character : word) {
            int c = character - 'a';
            if (nodes[node].next[c] == -1) {
                nodes[node].next[c] = static_cast<int>(nodes.size());
                nodes.emplace_back();
            }
            node = nodes[node].next[c];
            ++nodes[node].count;
        }
    }

    bool contains(const std::string& word) const {
        int node = 0;
        for (char character : word) {
            int c = character - 'a';
            if (nodes[node].next[c] == -1) return false;
            node = nodes[node].next[c];
        }
        return true;
    }

    int countWithPrefix(const std::string& prefix) const {
        int node = 0;
        for (char character : prefix) {
            int c = character - 'a';
            if (nodes[node].next[c] == -1) return 0;
            node = nodes[node].next[c];
        }
        return nodes[node].count;
    }
};
