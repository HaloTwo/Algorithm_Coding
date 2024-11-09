#include <iostream>
#include <algorithm>  
#include <vector>
using namespace std;

bool cmp(string a, string b)
{
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++) {
        string text;
        cin >> text;
        words.push_back(text);
    }

    sort(words.begin(), words.end(), cmp);

    // 방법 1: i를 1부터 시작
    for (int i = 0; i < n; i++) 
    {
        if (words[i] == words[i + 1]) continue;
        cout << words[i] << "\n";
    }

    return 0;
}