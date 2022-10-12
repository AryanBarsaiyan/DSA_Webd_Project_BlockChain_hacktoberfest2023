#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
using namespace std;
class node
{
public:
    char ch;
    bool isterminal;
    unordered_map<char, node *> h;
    node(char c)
    {
        ch = c;
        isterminal = false;
    }
};
class Trie
{
public:
    node *root;
    Trie()
    {
        root = new node('\0');
    }
    void addWord(char *word)
    {
        node *temp = root;
        for (int i = 0; word[i]; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch))
            {
                temp = temp->h[ch];
            }
            else
            {
                node *n = new node(ch);
                temp->h[ch] = n;
                temp = n;
            }
        }
        temp->isterminal = true;
    }
    bool searchWord(char *word)
    {
        node *temp = root;
        for (int i = 0; word[i]; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 1)
            {
                temp = temp->h[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->isterminal;
    }
    void findallwords(node *temp, string &x, vector<string> &ans)
    {
        // base case
        if (temp->isterminal == true)
        {
            ans.push_back(x);
        }
        // recursive case
        for (auto p : temp->h)
        {
            x.push_back(p.first);
            findallwords(p.second, x, ans);
            x.pop_back();
        }
    }
    void autofill(char *initial)
    {
        node *temp = root;
        for (int i = 0; initial[i]; i++)
        {
            char ch = initial[i];
            if (temp->h.count(ch) == 1)
            {
                temp = temp->h[ch];
            }
            else
            {
                return;
            }
        }
        string x(initial);
        vector<string> ans;
        findallwords(temp, x, ans);
        for (auto W : ans)
        {
            cout << W << endl;
        }
    }
};
int main()
{
    Trie t;
    t.addWord("Hello");
    t.addWord("Heman");
    t.addWord("Hell");
    t.addWord("Hero");
    t.addWord("Heart");

    t.addWord("Code");
    t.addWord("Coder");
    t.addWord("Coders");
    // char word[100] = "Code";
    // if (t.searchWord(word))
    // {
    //     cout << "Present hai\n";
    // }
    // else
    // {
    //     cout << "Present nahi hai\n";
    // }
    char initial[] = "He";
    t.autofill(initial);
    return 0;
}