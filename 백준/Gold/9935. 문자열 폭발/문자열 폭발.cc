#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	vector<char> vec;

	string word;
	string bomb;

	cin >> word >> bomb;


	for (int i = 0; i < word.size(); i++)
	{
		vec.push_back(word[i]);

		if (vec.size() >= bomb.size())
		{
			bool isSame = true;

			for (int i = 0; i < bomb.size(); i++)
			{
				if (vec[vec.size() - bomb.size() + i] != bomb[i])
				{
					isSame = false;
					break;
				}
			}

			if (isSame)
			{
				for (int i = 0; i < bomb.size(); i++) 
				{
					vec.pop_back();
				}
			}
		}
	}

	if (vec.empty()) 
	{
		cout << "FRULA";
	}
	else for (char c : vec) 
	{
		cout << c;
	}


}
