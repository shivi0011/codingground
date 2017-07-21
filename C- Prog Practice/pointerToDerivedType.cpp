#include<iostream>

using namespace std;

class base
{
    int i;      //by default all the member variables are private and can be accessed by only member fns
    public:
    void set_i(int n){i=n;}
    int get_i(){return i;}
};

class derived:public base
{
    int j;
    public:
    void set_j(int n){j=n;}
    int get_j(){return j;}
    
};

int main()
{
    base *bp;
    derived d;
    
    bp=&d;  //base pointer points to derived obj
    
    //access derived object using base pointer
    bp->set_i(10);                      //need to use arrow operator to access thru pointer
    cout<<bp->get_i()<<endl;

/* This wont work. You cant access an element of a derived class using a base class pointer
    bp->set_j(40);    
    cout<<get_j()<<endl;
*/

/*to access the members of derived class using base class pointer, we need to cast base pointer to a 
pointer of derived type*/

((derived*)bp)->set_j(500);
cout<<((derived*)bp)->get_j()<<endl;

    return 0;
}
