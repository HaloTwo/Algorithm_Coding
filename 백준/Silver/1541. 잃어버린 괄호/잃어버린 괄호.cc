#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int len, tmp;
int sum = 0;
bool flag; // '-'가 등장했는지 체크
char str[51];

int main()
{
	cin >> str;
	len = strlen(str); //식의 길이

	for (int i = 0; i <= len; i++)
	{

		if (str[i] == '+' || str[i] == '-' || i == len) // '+','-'가 등장했거나 혹은 수식의 끝일때
		{
			if (flag == false) //'-'등장 이전 모든 값 양수화
			{
				sum += tmp;
				tmp = 0;
			}
			else // (flag == true), '-'등장 이후로 모든 값 음수화
			{
				sum -= tmp;
				tmp = 0;
			}

			if (str[i] == '-') flag = true; // '-'등장 시 체크
				
		}
		else // tmp변수에 값 누적
		{
			tmp *= 10;
			tmp += str[i] - '0'; // char 데이터를 정수로 변환
		}
	}

	cout << sum;
}