#include <bits/stdc++.h>
using namespace std;
class TrieNode{
  public:
  char data;
  TrieNode *children[26];
  bool isEnd;
  TrieNode(char ch)
  {
    data=ch;
    for(int i=0;i<26;i++)
    {children[i]=NULL;}

    isEnd=false;
  } 
  
};
class Trie
{
public:
TrieNode *root;
Trie()
{
   root=new TrieNode('\0');
}

void insertUtil(TrieNode *root,string word)
{
 if(word.size()==0)
 {
  root->isEnd=true;
 }
 int idx=word[0]-'A';
 TrieNode *child;
 if(root->children[idx]!=NULL)
 {
  child=root->children[idx];
 }
 else
 {
  child=new TrieNode(word[0]);
  root->children[idx]=child;
 }
 insertUtil(child,word.substr(1));
}
void insertWord(string word)
{
  insertUtil(root,word);
}
bool searchUtil(TrieNode* root,string word)
{
  if(word.size()==0)
  return root->isEnd;
 int idx=word[0]-'A';
 TrieNode *child;
 //present
 if(root->children[idx]!=NULL)
 {
  child=root->children[idx];
 }
 //absent
 else
 {
 return false;

 }
 return searchUtil(child,word.substr(1));
}
bool searchWord(string word)
{
  return searchUtil(root,word);
}
};
int main()
{
  cout<<"Hi\n";
 Trie *t=new Trie();
 
 t->insertWord("ARM");
 
 t->insertWord("TIME");
 t->insertWord("TIM");
 cout<<"Hi\n";
//  if(t->searchWord("abcd"))
//  cout<<"Found the word:"<<endl;
//  else
//  cout<<"Not Found\n";
return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//   public:
//   Node *links[26];
//   bool flag=false;
//   bool containsKey(char c)
//   {
//     return links[c-'a']!=NULL;
//   }
//   void put(char c,Node* node)
//   {
//     links[c-'a']=node;
//   }
//   Node *get(char c)
//   {
//     return links[c-'a'];
//   }
//   void setEnd()
//   {
//     flag=true;
//   }
//   bool isEnd()
//   {
//     return flag;
//   }
// };
// class Trie{
  
//     public:
//     Node *root;
//     Trie()
//     {
//       root=new Node();

//     }
//     //O(length of word)
//     void insert(string word)
//     {
//       Node *node=root;
//       for(int i=0;i<word.size();i++)
//       {
//         if(!node->containsKey(word[i]))
//         node->put(word[i],new Node());
//         // moves to the reference trie
//         node->get(word[i]);
//       }
//    node->setEnd();
//     }
//     bool search(string word)
//     {
//        Node* node=root;
//        for(int i=0;i<word.size();i++)
//        {
//         if(!node->containsKey(word[i]))
//         return false;
//         node=node->get(word[i]);
//        }
//        return node->isEnd();
//     }
//     bool startwith(string prefix)
//     {
//       Node* node=root;
//       for(int i=0;i<prefix.size();i++)
//       {
//           if(!node->containsKey(prefix[i]))
//         return false;
//         node=node->get(prefix[i]);
//       }
//       return true;
//     }
// };
// int main()
// {
//   Trie object;
//     cout<<"Press 1 to insert\n";
//     cout<<"Press 2 to find\n";
//     cout<<"Press 3 start with\n";
//     cout<<"Press 0 to exit\n";
   
//     while(1)
//     {
//        int x;
//       cin>>x;
//       if(x==1)
//       {
//         string s;
//         cin>>s;
//          object.insert(s);
//       }
//       else if(x==2)
//       {
//          string s;
//         cin>>s;
//          if(object.search(s))
//          {
//           cout<<"String find\n";
//          }
//          else
//          {
//           cout<<"Not find\n";
//          }
//       }
//       else if(x==3)
//       {
//         string s;
//         cin>>s;
//          if(object.startwith(s))
//          {
//            cout<<"String find\n";
//          }
         
//          else
//          {
//           cout<<"Not find\n";
//          }
//       }
//       else
//       break;
//     }
//     return 0;
// }