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
    vector<int> vrednosti; //Array of word lengths
    size_t pos = 0;
    while ((pos = B.find(" ")) != string::npos){
        vrednosti.push_back(pos);
        B.erase(0,pos+1);
    }
    vrednosti.push_back(B.length());

    if (*max_element(vrednosti.begin(),vrednosti.end()) > S) return 0;
    
    //for (int vrednost : vrednosti) cout << vrednost << endl;
    int size = S / *max_element(vrednosti.begin(),vrednosti.end()); //Begin with the largest possible size
    int L = 0;
    int middle;
    while (L <= size){ //find the optimal size fast by bisection
        middle = (L+size)/2;
        if (testiraj(middle,S,V,vrednosti)) L = middle + 1;
        else size = middle - 1;
    }

    /* Naive method without bisection
    for (;size>0;size--){  //Decrease the size until the text fits
        if (testiraj(size,S,V,vrednosti))
            return size;
    }
    return 0;
    */
    return size;
}

int testiraj(int size, int S, int V, const vector<int>& vrednosti){ //Returns true if it is possible to display text with given character size
    int vrstice = size; //keeps track of number of occupied rows
    int vVrstici = 0; //amount of occupied space in current row
    int LineSize; //amount of occupied space after adding the next word
    int vrednost; //represents a single word

    for (int i=0;i<vrednosti.size();i++){
        vrednost = vrednosti[i];
        LineSize = vVrstici + (vrednost + 1)*size; //new row size after adding the current word vrednost

        if (LineSize > S) { //Current row size is bigger than it can be
            if (LineSize <= S+size){  //If this is the case, we can still fit everything on the current row by removing the trailing whitespace
                if (i != vrednosti.size() -1) vrstice += size;
                vVrstici = 0;
            }
            else {
                vrstice += size;
                vVrstici = (vrednost + 1)*size;
            }
        }
        else vVrstici = LineSize;
        if (vrstice > V) return false;
    }
    return true;
}