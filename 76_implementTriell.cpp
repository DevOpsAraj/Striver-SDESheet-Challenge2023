// Code Studio - Implement Trie ll

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    int endWith;
    int countPrefix;
    TrieNode()
    {
        endWith = 0;
        countPrefix = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{

private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void InsertWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->countPrefix++;
            root->endWith++;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            TrieNode *newTrieNode = new TrieNode();
            root->children[index] = newTrieNode;
            child = root->children[index];
        }
        root->countPrefix++;
        InsertWord(child, word.substr(1));
    }

    int CountWords(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->endWith;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return 0;
        }

        return CountWords(child, word.substr(1));
    }

    int CountWord_withPrefix(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->countPrefix;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return 0;
        }
        return CountWord_withPrefix(child, word.substr(1));
    }

    void RemoveWords(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->countPrefix--;
            root->endWith--;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            root->countPrefix--;
            child = root->children[index];
        }
        else
        {
            return;
        }
        RemoveWords(child, word.substr(1));
    }

    void insert(string &word)
    {
        InsertWord(root, word);
    }
    int countWordsEqualTo(string &word)
    {
        return CountWords(root, word);
    }
    int countWordsStartingWith(string &word)
    {
        return CountWord_withPrefix(root, word);
    }

    void erase(string &word)
    {
        RemoveWords(root, word);
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("apple");
    trie->insert("apple");
    trie->insert("app");
    cout << trie->countWordsEqualTo("apple") << endl;
    cout << trie->countWordsStartingWith("app") << endl;
    trie->erase("apple");
    cout << trie->countWordsEqualTo("apple") << endl;
    return 0;
}