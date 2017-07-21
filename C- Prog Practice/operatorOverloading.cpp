#include <iostream>

using namespace std;

class loc
{
    int longg, latt;
    public:
    loc(){}     //constructor...it must be public as we need to access it from outside the class ie from
    loc(int lg,int lt)                                                                              //main
    {
        longg = lg;
        latt = lt;
    }
    
    void show()
    {
        cout<<longg<<" "<<latt<<endl;
    }
    
    loc operator+(loc op2);     //declaring operator+ as function which returns obj of class loc and takes
};                              //argument as obj

loc loc::operator+(loc op2)
{
    loc temp;       //create a temporary obj of class loc as we need to return the obj
    temp.longg = op2.longg + longg/*class memeber can be accessed directly*/;
    temp.latt = op2.latt + latt/*class memeber can be accessed directly*/;
    
    return temp;
}


int main()
{
    loc ob1(10,20),ob2(5,30);
    
    ob1.show();     //displays 10 20
    ob2.show();     //displays 5 30
    
    ob1 = ob1+ob2;    //displays 15 30
   return 0;
}

/*In operator overloading, unary operator takes no argument and Binary operator takes 1 argument as 
other argument is passed via a THIS pointer so no need to explicitly pass it to fn.
Always the left operand of that binary operator is passed implicitly to the fn usign THIS pointer.
*/
