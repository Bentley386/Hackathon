#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int solve(int,int,string);
int test(int,int,int,vector<int>);

int main(){
    ifstream inputFile;
    int S;
    int V;
    string B;
    inputFile.open("input.txt",ios::in);
    while (!inputFile.eof()) {
        inputFile >> S >> V;
        getline(inputFile,B);
        B = B.substr(1);
        cout << solve(S,V,B) << endl;
    }

    inputFile.close();
    return 0;
}

int solve(int S, int V, string B){
    vector<int> vrednosti;
    size_t pos = 0;
    while ((pos = B.find(" ")) != string::npos){
        vrednosti.push_back(pos);
        B.erase(0,pos+1);
    }
    vrednosti.push_back(B.length());

    if (*max_element(vrednosti.begin(),vrednosti.end()) > S)
        return 0;
    
    //for (int vrednost : vrednosti) cout << vrednost << endl;
    int size = S / *max_element(vrednosti.begin(),vrednosti.end());

    for (;size>0;size--){
        if (test(size,S,V,vrednosti))
            return size;
    }
    return 0;
}

int test(int size, int S, int V, vector<int> vrednosti){
    int vrstice = size;
    int vVrstici = 0;
    int LineSize;
    int vrednost;

    for (int i=0;i<vrednosti.size();i++){
        vrednost = vrednosti[i];
        LineSize = vVrstici + (vrednost + 1)*size;

        if (LineSize > S) {
            if (LineSize <= S+size){
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