#include <iostream>
using namespace std;

class cSquare{
    double side;
    public:
        cSquare():side(0.00){};
        cSquare(double Side):side(Side){}
        ~cSquare(){};
        double getisde(){return side;}
        void setside(double s){
            side = s;
        }

};

int main(){
    cSquare* sqr[4];
    for (int i = 0; i<4 ; i++){
        sqr[i]= new cSquare;
        sqr[0]->setside(1.0);
        return 0;
    }
}