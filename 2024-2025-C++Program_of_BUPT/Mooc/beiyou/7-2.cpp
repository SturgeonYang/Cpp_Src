#include<iostream>
using namespace std;

class student{
    public:
    int number,age;
    string name;
    double score;

    public:
        student(int i,string n,int a,double s){
            number = i;
            name = n;
            age = a;
            score = s;
        }
    void classInforOut(){
        cout<<number<<","<<name<<","<<age<<","<<score<<endl;
    }
};
void inforOut(student &test){
    cout<<test.number<<","<<test.name<<","<<test.age<<","<<test.score<<endl;
};

int main(){

    student test(2021001,"Lili",19,89.5);
    test.classInforOut();
    inforOut(test);


}