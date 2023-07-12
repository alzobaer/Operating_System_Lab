#include <bits/stdc++.h>
using namespace std;

void create(string src){
    ofstream output(src, ios::binary);
    return;
}

void copypaste(string src, string dest){
    ifstream input(src, ios::binary);
    if(!input.is_open()){
        cout << "Error opening input file\n";
        return;
    }
    ofstream output(dest, ios::binary);
    if(!output.is_open()){
        cout << "Error Opening output File\n";
        return;
    }

    output << input.rdbuf();
    if(!output)
        cout << "Error copying file\n";
    else
        cout << "Successfully copied the file\n";
    return;
}

void cutpaste(string src, string dest){
    copypaste(src, dest);
    if(remove(src.c_str()) != 0)
        cout << "Error deleting input file: " << src << endl;
    return;
}

void del(string src){
    if(remove(src.c_str()) != 0)
        cout << "Error Deleting the file\n";
    else
        cout << "Successfully Deleted\n";
    return;
}

int main(){
    string command;
    while (1){
        string temp = "";
        vector <string> words;
        int numberOfWords = 0;
        getline(cin, command);
        if (command == "exit"){
            cout << "Exiting";
            return 0;
        }

        else{
            for (int i = 0; command[i] != '\0'; i++){
                if (command[i] == ' '){
                    words.push_back(temp);
                    temp = "";
                    numberOfWords++;
                }
                else
                    temp = temp + command[i];
            }

            words.push_back(temp);
            numberOfWords++;

            if (numberOfWords < 2 || numberOfWords > 3){
                printf("Invalid command, try again\n");
                continue;
            }

            if (numberOfWords == 3){
                if (strcasecmp(words[0].c_str(), "Copy") == 0)
                    copypaste(words[1], words[2]);
                else if (strcasecmp(words[0].c_str(), "Move") == 0)
                        cutpaste(words[1], words[2]);
                else{
                    cout << words[0];
                    cout << " : Wrong Input" << endl;
                }
            }
            else{
                if (strcasecmp(words[0].c_str(), "Delete") == 0)
                    del(words[1]);
                else if(strcasecmp(words[0].c_str(), "Create") == 0)
                    create(words[1]);
                else{
                    cout << words[0];
                    cout << " : wrong input" << endl;
                }
            }
        }
    }
    return 0;
}
