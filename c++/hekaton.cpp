#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int solve(int,int,string);
int testiraj(int,int,int,const vector<int>&);

string fileName;
ifstream inputFile;
int S, V;
string B;

int main(){
    cout << "Write the file name containing the data (eg. \"input.txt\")\n";
    getline(cin,fileName);
    inputFile.open(fileName,ios::in);
    cout << "==== Results ====\n";

    while (!inputFile.eof()) {
        inputFile >> S >> V;
        getline(inputFile,B);
        B = B.substr(1);
        cout << solve(S,V,B) << "\n";
    }
    inputFile.close();
    return 0;
}

int solve(int S, int V, string B){ //Given S,V,B, calculate the highest possible size of the character
    vector<int> values; //Array of word lengths
    size_t pos = 0;
    while ((pos = B.find(" ")) != string::npos){
        values.push_back(pos);
        B.erase(0,pos+1);
    }
    values.push_back(B.length());

    if (*max_element(values.begin(),values.end()) > S) return 0;

    int size = S / *max_element(values.begin(),values.end()); //Largest possible size
    int L = 0;
    int middle;
    while (L <= size){ //find the optimal size fast by bisection
        middle = (L+size)/2;
        if (testiraj(middle,S,V,values)) L = middle + 1;
        else size = middle - 1;
    }
    return size;

    /* Naive method without bisection
    for (;size>0;size--){  //Decrease the size until the text fits
        if (testiraj(size,S,V,values))
            return size;
    }
    return 0;
    */
}

int testiraj(int size, int S, int V, const vector<int>& values){ //Returns true if it is possible to display text with given character size
    int rows = size; //keeps track of number of occupied rows
    int inRow = 0; //amount of occupied space in current row
    int lineSize; //amount of occupied space after adding the next word
    int value; //represents a single word

    for (int i=0;i<values.size();i++){
        value = values[i];
        lineSize = inRow + (value + 1)*size; //new row size after adding the current word vrednost
        if (lineSize > S) { //Current row size is bigger than it can be
            if (lineSize <= S+size){  //If this is the case, we can still fit everything on the current row by removing the trailing whitespace
                if (i != values.size() -1) rows += size;
                inRow = 0;
            }
            else {
                rows += size;
                inRow = (value + 1)*size;
            }
        }
        else inRow = lineSize;        }
        if (rows > V) return false;
    return true;
}