#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code"};

    cout << "msg.size: " << msg.size() << endl;
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}