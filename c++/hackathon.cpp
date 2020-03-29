#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int solve(int,int,string);
int test(int,int,int,const vector<int>&);
int S, V;
string B;
ifstream inputFile;

int main(){
    cout << "Write the file name containing the data (eg. \"input.txt\")\n";
    getline(cin,B);
    inputFile.open(B,ios::in);
    cout << "=========\n";
    while (!inputFile.eof()) {
        inputFile >> S >> V;
        getline(inputFile,B);
        B = B.substr(1); //get rid of the leading whitespace
        cout << solve(S,V,B) << "\n";
    }
    inputFile.close();
    return 0;
}


int solve(int S, int V, string B){ //Given S,V,B, calculates the highest possible size of the character
    vector<int> values; //Array of word lengths
    size_t pos = 0;
    while ((pos = B.find(" ")) != string::npos){ //This loop populates the values array with words from string B
        values.push_back(pos);
        B.erase(0,pos+1);
    }
    values.push_back(B.length());

    if (*max_element(values.begin(),values.end()) > S) return 0; //If largest word is longer than S we can immediately return 0

    int R = S / *max_element(values.begin(),values.end()); //Largest possible character size
    int L = 0; 
    int middle;
    while (L <= R){ //find the optimal size fast by bisection
        middle = (L+R)/2;
        if (test(middle,S,V,values)) L = middle + 1;
        else R = middle - 1;
    }
    return R;

    /* Naive method without bisection
    for (;size>0;size--){  //Decrease the size until the text fits
        if (test(size,S,V,values))
            return size;
    }
    return 0;
    */
}

int test(int size, int S, int V, const vector<int>& values){ //Returns true if it is possible to display text with given character size
    int rows = size; //keeps track of number of occupied rows
    int inRow = 0; //amount of occupied space in current row
    int lineSize; //amount of occupied space after adding the next word
    int value; //represents a single word

    for (int i=0;i<values.size();i++){
        value = values[i]; //word to add to the screen
        lineSize = inRow + (value + 1)*size; //new row size after adding the current word value
        if (lineSize > S) { //This executes if current row size is bigger than it can be
            if (lineSize <= S+size){  //If this is the case, we can still fit everything on the current row by removing the trailing whitespace 
                if (i != values.size() -1) rows += size; //Only add new row if we aren't currently on the very last word.
                inRow = 0;
            }
            else { //this executes if we have to move to a new row
                rows += size;
                inRow = (value + 1)*size;
            }
        }
        else inRow = lineSize;    //this executes if we can add a word and remain in same row
        if (rows > V) return false;
    }
    return true;
}