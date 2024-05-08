#include<vector>
#include<deque>
#include<ctime>
using namespace std;
#include<iostream>
#include<algorithm>
class person
{
public:
	person(string name1, int score1)
	{
		this->score = score1;
		this->name = name1;
	}
	string name;
	int score;
};
void init(vector<person>& w)
{
	string name = "ÐÕÃû";
	string add = "abcdef";
	for (int i = 0; i < 5; i++)
	{
		person p(name + add[i],0);
	    w.push_back(p);
	}
}
void setscore(vector<person>& p)
{
	deque<int>d;
	int score;
	for (vector<person>::iterator it = p.begin(); it != p.end(); it++)
	{
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			score = rand() % 41 + 60;
			d.push_back(score);
			sum += score;
		}
		sort(d.begin(), d.end());
		sum -= d[0];
		sum -= d[4];
		d.pop_back();
	    d.pop_front();
	   it->score = sum / 3;
	}
	
	
}
void print(vector<person>& d)
{
	for (vector<person>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << it->name <<"  " << it->score<<endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<person>v;
	init(v);
	setscore(v);
	print(v);

}