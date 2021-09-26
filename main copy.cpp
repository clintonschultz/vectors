/* Name: Clinton Schultz
 * Professor: Michael Clark Jr.
 * Assignment: Programming Homework #1
 * Date: 02/07/2021
 *
 * This simple program takes the longest string(s) from a vector and stores them in a new vector
 * that is in turn printed out so the used can see the result. */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// uses the first element as the max size and checks against the sizes of the rest of the strings
vector<string> getLongestLength(vector<string> &stringList, vector<string> &newList) {

    int currentMax = stringList[0].size(); // begin with first element initialized as max

    for (int i = 1; i < stringList.size(); i++) {
        if (stringList[i].size() == currentMax) { // if sizes of the two strings are equal
            newList.push_back(stringList[i]); // add the new string to the list
        }
        else if (stringList[i].size() > currentMax) { // if new element is larger in size than currentMax
            newList.clear(); // clear the whole list to zero elements
            newList.push_back(stringList[i]); // add the new element to the empty list
            currentMax = stringList[i].size(); // set the current element to new currentMax
        }
    }
    return newList;
}

// prints out each element in newList, each separated by new line
void printList(vector<string> &list) {
    for (int i = 0; i < 4; i++) {
        std::cout << list[i] << "\n";
    }
}

int main() {

    string input;

    cout << "Enter in strings.  Enter in 0 to indicate you are done" << endl;

    std::vector<std::string> stringList;
    std::vector<std::string> newList;

    // if there is input, then add string to stringList
    while (cin>>input && input != "0")
    {
        stringList.push_back(input); // add string to stringList
    }
    getLongestLength(stringList, newList);
    printList(newList);

    return 0;
}
