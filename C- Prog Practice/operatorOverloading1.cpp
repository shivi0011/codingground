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
                              //argument as obj
    loc operator-(loc op2);
    loc operator=(loc op2);
    loc operator++();

};
loc loc::operator+(loc op2)
{
    loc temp;       //create a temporary obj of class loc as we need to return the obj
    temp.longg = op2.longg + longg/*class memeber can be accessed directly*/;
    temp.latt = op2.latt + latt/*class memeber can be accessed directly*/;
    
    return temp;
}

loc loc::operator-(loc op2)
{
    loc temp;
    /*notice the ordeer of operands*/
    /*For minus-->  ans is left - right
    The obj on the left that generates the call to the operator-() fn. Means op2's data must be subtracted
    from the data pointed to by the THIS pointer
    */
    temp.longg = longg - op2.longg;
    temp.latt = latt - op2.latt;
    
    return temp;
}


loc loc::operator=(loc op2)
{
    /*loc temp;
    temp.longg = op2.longg;
    temp.latt = op2.latt;
    return temp;*/
    
    longg = op2.longg;
    latt = op2.latt;
    return *this;
}

loc loc::operator++()
{
    longg++;
    latt++;
    
    return *this;
}

int main()
{
    loc ob1(10,20),ob2(5,30),ob3(90,90);
    
    ob1.show();     //displays 10 20
    ob2.show();     //displays 5 30
    ob3.show();
    
    cout<<"\n::::::::::\n";
    loc res = ob3-ob1;
    ob1.show();
    ob3.show();
    res.show();
    cout<<"::::::::::\n";
    
    ++ob1;
    ob1.show();     //displays 11 21
    
    ob2 = ++ob1;
    ob1.show();
    ob2.show();
    
    
    
    ob1 = ob2 = ob3;
    ob1.show();     //displays 90 90
    ob2.show();     //displays 90 90
    
    return 0;
}

