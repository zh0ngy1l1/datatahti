// https://cses.fi/484/task/B
 
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    string word;
    int len;
    vector<string> w_queue;
    vector<string> ss_queue;
    int ss_size;
    string curr_w = "";
    
    cin >> word;
    
    for (int _ = 0; _ < 4; _++)
    {
        ss_size = 0;

        len = int(word.size());

        for (int i = 0; i < len; i++)
        {
            if (isalpha(word[i])) {
                curr_w += word[i];
            } else {
                w_queue.push_back(curr_w);
                curr_w = "";

                int number = word[i] - 48;

                string ss = word.substr(i + 1, number);

                ss_queue.push_back(
                    ss
                );

                ss_size++;

                i += number;

            }
        }
        word = "";
        for (int i = 0; i < ss_size; i++)
        {
            word += w_queue[i] += ss_queue[i] += ss_queue[i];
        }
        word += curr_w;

        cout << word << endl;
    
        curr_w = "";
        w_queue.clear();
        ss_queue.clear();

    }
    //cout << word << endl;
    
    }
