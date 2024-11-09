#include <unordered_map>
#include <string>
#include <iostream>
#include <cctype> 

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string pokemonName;
    unordered_map<int, string> numToName;
    unordered_map<string, int> nameToNum;

    cin >> n >> m;  

    for (int i = 1; i <= n; i++)
    {
        cin >> pokemonName;
        numToName[i] = pokemonName;
        nameToNum[pokemonName] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> pokemonName;
        if (isdigit(pokemonName[0]))
        {
            int num = stoi(pokemonName);
            cout << numToName[num] << '\n';  
        }
        else
        {
            cout << nameToNum[pokemonName] << '\n';  
        }
    }
    return 0;
}