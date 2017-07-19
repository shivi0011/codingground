#include<iostream>

using namespace std;

/*:::::::::::::::CLASSES:::::::::::::::::::*/
class building
{
    int rooms,floors,area;
    
    public:
    int getRooms();
    void setRooms(int num);
    int getFloors();
    void setFloors(int num);
    int getArea();
    void setArea(int num);
};
class house:public building
{
    int bedrooms,baths;
    
    public:
    int getBedrooms();
    void setBedrooms(int num);
    int getBaths();
    void setBaths(int num);
};
class school:public building
{
    int classrooms,offices;
    
    public:
    int getClassrooms();
    void setClassrooms(int num);
    int getOffices();
    void setOffices(int num);
};


/*::::::::::::::::FUNCTIONS::::::::::::::::::::*/
/*SET funcitons for BUILDING*/
void building::setRooms(int num)    //by using scope resolution operator, we're telling to compiler
{                           //that this fn setRooms is belongs to building class bcz we cannot make 
    rooms = num;            //any fn not belonging to any class..means either make inside the same class
}                           //or use :: to inform the compiler about the fn
void building::setFloors(int num)
{
    floors = num;
}
void building::setArea(int num)
{
    area =  num;
}
/*GET functions for BUILDING*/
int building::getRooms()
{
    return rooms;
}
int building::getFloors()
{
    return rooms;
}
int building::getArea()
{
    return area;
}
//==============================
 /*SET function for HOUSE*/
void house::setBedrooms(int num)
{
    bedrooms = num;
}
void house::setBaths(int num)
{
    baths = num;
}
/*GET function for HOUSE*/
int house::getBedrooms()
{
    return bedrooms;
}
int house::getBaths()
{
    return baths;
}
//==============================
/*SET functions for SCHOOL*/
void school::setClassrooms(int num)
{
    classrooms = num;
}
void school::setOffices(int num)
{
    offices = num;
}
/*GET functions for SCHOOL*/
int school::getClassrooms()
{
    return classrooms;
}
int school::getOffices()
{
    return offices;
}


int main()
{
    house h;        //created an object of house class
    school s;       //created an object of school class
    
    h.setRooms(12);
    h.setFloors(5);
    h.setArea(5000);
    h.setBedrooms(6);
    h.setBaths(34);
    
    cout<<"This house has "<< h.getBedrooms();
    cout<<"bedrooms\n";
    
    s.setRooms(34);
    s.setFloors(10);
    s.setArea(4545);
    s.setClassrooms(45);
    s.setOffices(5);
    
    cout<<"School has"<<s.getClassrooms()<<"classrooms\n";
    cout<<"Its area is "<<s.getArea()<<endl;
  return 0;  
}
