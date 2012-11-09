/**
 * Example used in programming courses at University of Parma, IT.
 * Author: Michele Tomaiuolo - <tomamic@ce.unipr.it> - 2011
 *
 * This software is free: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License, version 3 or
 * later. See <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string word1, string word2) {
    return word1.size() > word2.size();
}

int main(int argc, char *argv[])
{
    vector<string> fileNames;
    vector<string> words;

    string fileName;
    cout << "Filename?" << endl;
    getline(cin, fileName);
    while (fileName != "") {

        fileNames.push_back(fileName);

        cout << "Filename?" << endl;
        getline(cin, fileName);
    }

    cout << "How many top words?" << endl;
    int n;
    cin >> n;

    for (int i = 0; i < fileNames.size(); ++i) {
        ifstream in(fileNames[i].c_str());

        string word;
        in >> word;
        while (in.good()) {
            if (count(words.begin(), words.end(), word) == 0) {
                words.push_back(word);
            }
            in >> word;
        }
    }

    sort(words.begin(), words.end(), compare);

    for (int i = 0; i < words.size() && i < n; ++i) {
        cout << words[i] << endl;
    }

    return 0;
}