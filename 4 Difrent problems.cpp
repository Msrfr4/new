#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "algorithm"
using namespace std;
int file_Comparison() {
    int i = 1;
    string name_1, name_2, word_1, word_2;
    char ch_1, ch_2, choice;
    bool same = true, same1 = true, ag = true;
    cout << "Please enter the first file path name: " << endl;
    cin >> name_1 ;
    ifstream file_1(name_1);
    while (!file_1) {
        file_1.clear();
        cout << "Could not open file 1 enter the path correctly: " << endl;
        cin >> name_1;
        file_1.open(name_1);
    }
    cout << "Please enter the second file path name: " << endl;
    cin >> name_2;
    ifstream file_2(name_2);
    while (!file_2) {
        file_2.clear();
        cout << "Could not open file 2 enter the path correctly: " << endl;
        cin >> name_2;
        file_2.open(name_2);
    }
    cout << "how do you want search\na.character by character\nb.word by word\n";
    cin >> choice;
    while (ag) {
        if (choice == 'a') {
            while (file_1.get(ch_1)) {
                file_2.get(ch_2);
                if (ch_1 != ch_2) {
                    cout << "The files are different for characters Comparison at line " << i << endl;
                    cout << ch_1 << ": in the first file " << '\n' << ch_2 << ": in the second file " << endl;
                    same = false;
                    break;
                } else {
                    if (ch_1 == '\n') {
                        i++;
                    }
                    same = true;
                }
            }
            if (same)
                cout << "the files for characters Comparison are the same" << endl;

            i = 1;
            ag = false;
        }
        else if (choice == 'b') {
            while (file_1 >> word_1) {
                file_2 >> word_2;
                if (word_1 != word_2) {
                    cout << "The files are different for word Comparison at line " << i << endl;
                    cout << word_1 << ": in the first file " << '\n' << word_2 << ": in the second file " << endl;
                    same1 = false;
                    break;
                }
                else {
                    if (word_1.back() == '\n') {
                        i++;
                    }
                    same1 = true;
                }

            }
            ag = false;
            if (same1)
                cout << "the files for words Comparison are the same" << endl;
        }
        else {
            cout << "invalid choice enter again\na.character by character\nb.word by word" << endl;
            cin >> choice;
        }
    }
    file_1.clear();
    file_2.clear();
    file_1.seekg(0);
    file_2.seekg(0);
    file_1.close();
    file_2.close();
    return 0;
}
void Fractal_Pattern (int n, int i){
    if(n==1){
        for (int j = 0; j < i; ++j) {
            cout << "  " ;
        }
        cout <<"*"<<endl;
        return;
    }
    Fractal_Pattern(n/2,i);
    for (int j = 0; j < i; ++j) {
        cout << "  " ;
    }
    for (int j = 0; j < n; ++j) {
        cout << "* ";
    }
    cout << endl;
    Fractal_Pattern(n/2,i+n/2);

}
string toLowerCase(string str) {
    string result = "";
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}
int inclusive_speech(){
    string First_Sentence, Test_Sentence = "",Test_Sentence_1 = "", x, FinL_Sentence = "";
    string case_1 = " or she", case_2 = " or her", case_3 = " or hers", case_4 = " or herself";
    cout<< "enter your sentence: "<<endl;
    getline(cin, First_Sentence);
    for (int i = 0; i < First_Sentence.length(); ++i) {
        Test_Sentence += First_Sentence[i];
        Test_Sentence_1=toLowerCase(Test_Sentence);
        x = First_Sentence[i];
        int leng = Test_Sentence.length();
        if (x == " " || x == "." || x == "?" || x == "," || x == "!") {
            if (leng == 3 && Test_Sentence_1 == "he" + x ) {
                for (int j = 0; j < case_1.length(); ++j) {
                    FinL_Sentence += case_1[j];
                }
                Test_Sentence = "";
            }
            else if (leng == 4 && Test_Sentence_1 == "him" + x) {
                for (int j = 0; j < case_2.length(); ++j) {
                    FinL_Sentence += case_2[j];
                }
                Test_Sentence = "";
            }
            else if (leng == 4 && Test_Sentence_1 == "his" + x) {
                for (int j = 0; j < case_3.length(); ++j) {
                    FinL_Sentence += case_3[j];
                }
                Test_Sentence = "";
            }
            else if (leng == 8 && Test_Sentence_1 == "himself" + x) {
                for (int j = 0; j < case_4.length(); ++j) {
                    FinL_Sentence += case_4[j];
                }
                Test_Sentence = "";
            }
            else {
                Test_Sentence = "";
            }
        }
        FinL_Sentence += First_Sentence[i];
    }
    cout << FinL_Sentence << endl;
    return 0;
}
int score_bord() {
    vector<pair<int, string >> v;
    string name, name1, add1;
    char cho;
    int score, count = 0;
    bool k = true, found,t= true;

    while (t) {
    string add;
    cout << "\na.add player\nb.search for a player score\nc.print the list\nd.exit"<<endl;
    cin >> cho;
    if (cho == 'a') {
        while (k) {
            cout << "add name and score:\n";
            cin >> name >> score;
            v.push_back({score, name});
            sort(v.rbegin(), v.rend());
            count += 1;
            if (count > 10)
                v.pop_back();
            cout << "do u want to add player?(yes/no):\n ";
            cin >> add;
            if (add == "no")
                k = false;
        }
    }
    else if (cho == 'b') {
        found = false;
        cout << "enter the player name: ";
        cin >> name1;
        for (const auto &pair: v) {
            if (name1 == pair.second) {
                cout << "the player score is: " << pair.first << '\n';
                found = true;
                break;
            }
        }
        if (!found)
            cout << "the name is not on the list!\n";
    }
    else if (cho == 'c') {
        cout << "name----score" << endl;
        for (const auto &pair: v) {
            cout << pair.second << "------" << pair.first << endl;
        }
    }
    else if(cho=='d'){
        cout<<"the program ends";
        t= false;
    }
    else{
        cout << "invalid choice enter again"<<endl;
    }

}

    return 0;
}
int main() {
// File:A1_T1_S7_20230735.cpp
// Purpose:learning
// Author:Mohamed Elmugtaba Omer Ahmed
// Section:s7
// ID:20230735
// TA:dont know yet
// Date: 10 Oct 2024
// Detailed explanation of the file and how program works in the text file
    char choice;
    bool again = true;
    while (again) {
        cout << " choose an option:\na.inclusive speech\nb.scoreboard\nc.print shape\nd.file comparison\ne. exit\n";
        cin >> choice;
        cin.ignore();
        if (choice == 'a') {
            inclusive_speech();
        }
        else if (choice == 'b') {
            score_bord();

        }
        else if (choice == 'c') {
            int n, i;
            cout << "Enter a number (power of 2 greater than zero) and a beginning column:\n";
            cin >> n >> i;
            Fractal_Pattern(n, i);
        }
        else if (choice == 'd') {
            file_Comparison();
        }
        else if (choice == 'e') {
            again = false;
            cout << "The program ends\n";
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}
