#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string input_string = "Hello, world! This is a test string.";
    vector<string> substrings;
    stringstream ss(input_string);
    string substring;

    while (getline(ss, substring, ' '))
    {
        substrings.push_back(substring);
    }

    for (const auto &str : substrings)
    {
        cout << str << endl;
    }

    return 0;
}