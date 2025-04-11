#include<iostream>
using namespace std;
class student
{
private:
	int id;
	string name;
	int age;
	float score;
public:
	student(int i = 2021001, string n = "Lili", int a = 19, float s = 89.5)
	{
		id =i;
		name = n;
		age = a;
		score = s;
	}
	~student()
	{
		cout << id << "," << name << "," << "~~~" << endl;
	}
};
int main()
{
	student s1;
	int id, age; float score; string name;
	cin >> id >> name >> age >> score;
	student s2(id, name, age, score);
 //// 使用构造函数创建对象的顺序与使用析构函数释放对象的顺序相反
// 即后构造的先析构（栈：先进后出）
	
	return 0;
 
}