#include "pch.h"
#include <vector>
using namespace std;
extern const string todayLucklib[157];

string readTxt(string filename, int line)//读取txt指定行数据存入string
{
	//line行数限制 1 - lines
	ifstream text;
	text.open(filename, ios::in);

	vector<string> strVec;
	while (!text.eof())  //行0 - 行lines对应strvect[0] - strvect[lines]
	{
		string inbuf;
		getline(text, inbuf, '\n');
		strVec.push_back(inbuf);
	}
	return strVec[line - 1];
}
int getAstIndex(int month, int day)
{
	int DayArr[12] = { 20, 19, 21 ,20 ,21 ,22 ,23 ,23 ,23 ,24 ,22 ,22 };  // 两个星座分割日
	int index = month;
	// 所查询日期在分割日之前，索引-1，否则不变
	if (day < DayArr[index - 1])
	{
		index = index - 1;
	}
	if (index == 12)
	{
		index = 0;
	}
	return index;
}
string getAstro(int month, int day)
{
	string starArr[12] = { "魔羯座","水瓶座", "双鱼座", "白羊座",
		"金牛座", "双子座", "巨蟹座", "狮子座", "处女座", "天秤座", "天蝎座", "射手座" };
	// 返回索引指向的星座string
	return starArr[getAstIndex(month,day)];
}
string getluck(int toNextBirth)
{
	return todayLucklib[ toNextBirth % 157 ];
}

int main()
{
	
	int month, day;
	auto constellation = getAstro(2, 6);
	//while (1)
	//{
	//	//cin >> month;
	//	//std::cout << getluck(month)<<endl;
	///*	cin >> month >> day;
	//	constellation = getAstro(month,day);
	//	std::cout << "Constellation:\n" << constellation<<endl;*/
	//	
	//}
	std::cout<<readTxt("TXT.txt",157);//
	return 0;
}

