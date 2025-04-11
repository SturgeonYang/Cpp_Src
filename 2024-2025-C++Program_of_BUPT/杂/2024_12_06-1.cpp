// #include <iostream>
// using namespace std;



// struct Student{
//     char num[15],name[100];
//     int b,c,d;
// }z[100];

// int main()
// {
//     int sum = 0, i = 0;
//     while(cin>>z[i].num>>z[i].name>>z[i].b>>z[i].c>>z[i].d){
//         i++;
//         sum++;

//     }

//     cout<<sum<<endl;
//     for(int i = 0; i < sum; i++){
//         printf("%s %s %d %d %d\n",z[i].num,z[i].name,z[i].b,z[i].c,z[i].d);
//     }
    
// }

#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();  // 这是构造函数
      ~Line();
 
   private:
      double length;
};
 
// 成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "Object is being created" << endl;
}

Line::~Line(void)
{
    cout << "over" <<endl;
}
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
// 程序的主函数
int main( )
{
   Line line;

}