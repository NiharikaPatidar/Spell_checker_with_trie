/*

Spell Checker using custom dictionary

*/
#include <iostream>

#include <vector>
using namespace std;

struct TrieNode {

    bool terminating = false;

    TrieNode* children[26] = {NULL};

};



class Trie {

    TrieNode* root;

public:

    Trie();



    void insertWord(string word);

    bool searchWord(string word);

    bool deleteWord(string word);

    bool updateWord(string oldWord, string newWord);




};



Trie::Trie(){

    root = new TrieNode();

}





void Trie::insertWord(string word){

    TrieNode* currNode = root;

    for(char c: word){

        if (currNode->children[c - 'a']==NULL) {

            currNode->children[c - 'a'] = new TrieNode();        

        }

        currNode = currNode->children[c - 'a'];

    }    

    currNode->terminating = true;

}



bool Trie::searchWord(string word){

    TrieNode* currNode = root;

    for(char c: word){

        if( currNode->children[c - 'a'] != NULL) {        

            currNode = currNode->children[c - 'a'];

        }else{

            return false;

        }

    }

    return currNode->terminating;

}





bool Trie::deleteWord(string word){

    TrieNode* currNode = root;

    for(char c: word){

        if( currNode->children[c - 'a'] != NULL) {        

            currNode = currNode->children[c - 'a'];

        }else{

            return false;

        }

    }

    currNode->terminating = false;

    return true;

}





bool Trie::updateWord(string oldWord, string newWord){

    

    bool ret = deleteWord(oldWord);

    if(ret)

        this->insertWord(newWord);

    

    return ret;

}



void printUnderline(string s)
{
	for(int i=0;i<s.size();i++)
	{
		cout<<char(s[i]-32);
	}
}

void print1(string s)
{
	cout<<s;
}


int main(){



    Trie oTrie;



    vector<string> words = { "cat", "car", "cart", "ball", "bat", "bats"};

    for(string word: words)

        oTrie.insertWord(word);





    string s = "";

    while(true){

        char c = getchar(); 

        if(c == '\n'){ // break on enter

            oTrie.searchWord(s) ? print1(s) : printUnderline(s);

            cout << c;

            break;

        }

        if(c == ' '){ 

            oTrie.searchWord(s) ? print1(s) : printUnderline(s);

            s = "";

            cout << c;

        }

        else{

            s = s + char(c);

        }

    }    



    cout << endl << endl;

    return 0;

  }
