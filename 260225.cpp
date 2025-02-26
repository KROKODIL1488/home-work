#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Сортировка слов в алфавитном порядке
void file(const string& vixod, const string& vxod) {
    ifstream in(vixod);
    ofstream out(vxod);

    if (!in.is_open()) {
        cerr << "файл не открыт" << vixod << endl;
        return;
    }
    if (!out.is_open()) {
        cerr << "файл не открыт" << vxod << endl;
        return;
    }

    vector<string> svo;
    string word;
    while (in >> word) { 
        svo.push_back(word);
    }

    sort(svo.begin(), svo.end()); 

    for (const string& sortedWord : svo) {
        out << sortedWord << endl; 
    }

    in.close();
    out.close();

    cout << "Слова в файле " << vixod << endl;
}
