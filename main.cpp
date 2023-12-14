#include "AVL.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    AVLTree avlTree;
 // Making tree object, taking in number of commands
    int numCommands = 0;
    cin >> numCommands;

    for (int i = 0; i < numCommands; ++i) {
        string function, name, id;
        string line;
        getline(cin >> ws, line);

        istringstream in(line);
        in >> function;

        //Taking in the first command which is a function call

        if (function == "insert") { //Checking if the input entered is insert
            in >> name;
            name = name.substr(1, name.length() -2);
            bool isValid = true;
            for(char c : name){
                if(!isalpha(c)){
                    isValid = false;
                }
            }
            in >> id;
            bool isNum = true;
            for(char c: id){
                if(!isdigit(c)){
                    isNum = false;
                }
            }
            if(isValid && isNum){
                avlTree.Insert(name, id);
            } else {
                cout << "unsuccessful" << endl;
            }
        } else if (function == "remove") { //Checking if the input is calling remove
            in >> id;
            bool isNum = true;
            for (char c: id) {
                if (!isdigit(c)) {
                    isNum = false;
                }
            }
            if(isNum){
                avlTree.Remove(id);
            } else{
                cout << "unsuccessful" << endl;
            }
        }
        else if (function == "search") { //Checking if the input is calling search
            in >> name;
            if(name.substr(0,1) == "\"") { // Checking to see if we are searching by name
                name = name.substr(1, name.length()-2);
                avlTree.SearchName(name);
            } else{  // Else, we search ID
                avlTree.SearchID(name);
            }
        }
        else if (function == "printInorder") { //Checking to see if the input is calling printInorder
            avlTree.PrintInorder();
            cout << endl;
        }
        else if (function == "printPreorder") {
            avlTree.PrintPreOrder();
            cout << endl;
        }
        else if (function == "printPostorder") {
            avlTree.PrintPostOrder();
            cout << endl;
        }
        else if (function == "printLevelCount") {
            avlTree.PrintLevelCount();
            cout << endl;
        }
        else if (function == "removeInorder") { //Checking to see if the input is calling removeInorder
            int n;
            in >> n;
            avlTree.removeInorderN(n);
        }
        else {
            cout << "unsuccessful" << endl;
            continue; // Continue to the next iteration of the loop
        }
    }
    return 0;
}