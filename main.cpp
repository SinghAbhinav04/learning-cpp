#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

//operator overloading
/*

class Dog{
public:int age , weight ;
    Dog(){

    }
    Dog(int age , int weight){
        this->age=age;
        this->weight=weight;
    }

    void printDetails(){
        cout<<"Age: "<<age<<"\t weight: "<<weight<<endl;
    }
    Dog operator+(Dog &dog){
        Dog temp;
        temp.age= age + dog.age;
        temp.weight=weight+ dog.weight;

        return temp;
    }
};


int main() {
    Dog dog1(12, 20);
    Dog dog2(10,30);
    Dog dog3;

    dog3 = dog1+dog2;

    dog3.printDetails();
    dog1.printDetails();
    dog2.printDetails();
    return 0;
}
*/

//inheritance + virtual and override
/*
#include <iostream>

class Animal{
public:std::string name;
public:

   virtual void speak(){
    }
   virtual void eat(){
    }
   virtual void sleep(){
    }
};

class Fish:public Animal{
public:
    std::string  name ;

    Fish(std::string name){
        this->name=name;
    }

public:
    void speak() override{
        std::cout<<name<<" is speaking"<<std::endl;
    }
    void eat() override{
        std::cout<<name<<" is eating"<<std::endl;
    }
    void sleep() override{
        std::cout<<name<<" is sleeping"<<std::endl;
    }
};

int main(){
    Fish fish("rubicon");
    fish.eat();
    fish.sleep();
    fish.speak();
}
*/

//cli register version
/*

class User{
private:string name,email,password ;
        int id =0 ;
public:
    User(){
    }

    User(string name , string email, string password){
        this->name = name;
        this->email= email;
        this->password= password;
        createId();
    }

    void printDetails(){
        cout<<name <<"\t"<<email <<"\t"<<password<<"\t"<<id<<endl;
    }

private:
    void createId(){
        id+=1;
    }
};

User registerUser(string name , string email , string password);
void printDetails( User &user);

int main() {

    string name, email, password;
    User user;

    while (true) {
        cout<<"1)Register"<<endl;
        cout<<"2)Print your details"<<endl;
        cout<<"3)Logout"<<endl;

        int userChoice = cin.get();
        cin.ignore();
        switch(userChoice){
            case '1':
               user =  registerUser(name , email,password);
                break;
            case '2':
                printDetails(user);
                break;
            case '3':
                return 0;
            default:
                cout<<"Enter the correct option!"<<endl;
                break;
        }
    }
}

User registerUser(string name, string email , string password){
    cout << "Enter your name" << endl;
    getline(cin, name);
    cout << "Enter your email" << endl;
    getline(cin, email);
    cout << "Enter your password" << endl;
    getline(cin, password);
    User user(name, email, password);
    cout<<"User created successfully!"<<endl;
    return user;
}

void printDetails( User &user){
    user.printDetails();
}
*/

// calculator
/*
class Calculator{

public:double number1, number2, result=0;

    Calculator(double number1 , double number2){
        this->number1=number1;
        this->number2=number2;
    }

    double add(){
        if(result!=0){
            cout<<"Enter the next number"<<endl;
            cin>>number2;

            result +=number2;

        }else {
            result = number1 + number2;
        }
        return result;
    }
    double sub(){
        if(result!=0) {
            cout << "Enter the next number" << endl;
            cin >> number2;

            result -= number2;
        }else {
            result = number1 - number2;
        }
        return result;
    }
    double mul(){
        if(result!=0) {
            cout << "Enter the next number" << endl;
            cin >> number2;

            result *=number2;
        }else {
            result = number1 * number2;
        }
        return result;
    }
    double div(){
        if(result!=0) {
            cout << "Enter the next number" << endl;
            cin >> number2;
            result /= number2;
        }else {
            result = number1 / number2;
        }
        return result;
    }

};


int main(){
    double number1, number2;

    cout<<"Welcome to calculator program"<<endl;
    cout<<"Enter the first number"<<endl;
    cin>>number1;
    cout<<"Enter the second number"<<endl;
    cin>>number2;

    Calculator c(number1,number2);

    while(true){
        cout<<"1)Addition"<<"\n2)Subtraction"<<"\n3)Multiplication"<<"\n4)Division"<<"\n5)exit"<<endl;
        int userInput;
        cin>>userInput;
        cin.ignore();
        switch(userInput) {
            case 1:
               cout<< c.add()<<endl;
                break;
            case 2:
                cout<< c.sub()<<endl;
                break;
            case 3:
                cout<<c.mul()<<endl;
                break;
            case 4:
                cout<<c.div()<<endl;
                break;
            case 5:
                return 0;
            default:
                cout<<"Choose the correct option"<<endl;
                break;
        }
    }
}
 */

//all types of inheritance
/*
class BaseOne{
public:
    void print(){
        cout<<"Inside Base 1"<<endl;
    }
    virtual void sleep(){
        cout<<"Base one is sleeping"<<endl;
    }
};

class BaseTwo{
public:
    void print(){
        cout<<"Inside Base 2"<<endl;
    }

};

class BaseThree{
public:
    void print(){
        cout<<"Inside Base 3"<<endl;
    }
};

class DerivedOne:public BaseOne,BaseTwo,BaseThree{
public:
    void print(){
        cout<<"Inside Derived 1"<<endl;
    }

    void sleep() override{
      cout<<"Derived one is sleeping"<<endl;
    }
};

class DerivedTwo:public BaseOne,BaseTwo{
public:
    void print(){
        cout<<"Inside Derived 2"<<endl;
    }
};

class DerivedThree :public DerivedOne,BaseOne{
public:
    void print(){
        cout<<"Inside Derived 3"<<endl;
    }

    void sleep(){
        DerivedOne::sleep();
    }
};


int main(){
    BaseOne baseOne;
    baseOne.print();

    BaseTwo baseTwo;
    baseTwo.print();

    BaseThree baseThree;
    baseThree.print();

    DerivedOne derivedOne;
    derivedOne.sleep();

    DerivedTwo derivedTwo;
    derivedTwo.sleep();

    DerivedThree derivedThree;
    derivedThree.sleep();
}
 */

//friend class and function
/*
class Base {
private:int privateNumber ;
protected:int protectedNumber;
public:
    Base(){
        privateNumber=10;
        protectedNumber=7;
    }
   // friend class Friend;
   friend void friendFunction(Base &object);
};

void friendFunction(Base &object){
    cout<<object.privateNumber<<endl;
    cout<<object.protectedNumber<<endl;
}

/*
class Friend{
public:
    void display(Base &base){
        cout<<base.protectedNumber<<endl;
        cout<<base.privateNumber<<endl;
    }
};


int main(){
    Base b;
   // Friend f;
   //f.display(b);
    friendFunction(b);
}
*/

//Call by value: Passes a copy, original remains unchanged.
//Call by reference: Passes a reference, original can be modified.
//Call by address: Passes a pointer, original can be modified via dereferencing.
/*
//call by value passes the copy of the variable , modifies the variable locally but the original one remains unchanged
void increment(int  x){
    x = x+1;
}

//call by reference (the reference acts as an alias for original variable)
void incrementByReference(int &x){
    x = x+1;
}

//call by address , original variable address is passed can be modified by dereferencing using astrix

void incrementByAddress(int *x){
    *x = *x+1;
}

int main(){
    int number = 5 ;
    increment(number);
    cout<<"Increment by value: "<<number<<endl;

    incrementByReference(number);
    cout<<"Increment by reference: "<<number<<endl;

    incrementByAddress(&number);
    cout<<"Increment by address: "<<number<<endl;
}

*/

//abstraction
/*
 Abstraction in C++ is a key concept of Object-Oriented Programming (OOP)
 that allows you to hide the internal implementation details of a function,
 class, or object and expose only the necessary functionality.
 It helps reduce complexity by showing only the essential features
 while hiding the complex underlying code.
 */
//example using a class
/*
class Car{
private: // in this example the engine work has been hidden , user doesnt need to know about
    // the implementation of these , only the neccessary details are shown to the user
    // another example can be , think of a driver he only drives the car , presses
    // accelator for increasing the speed and brake for stopping he is not interested in
    // knowing about the complex implementation of how this is being done
    void startEngine(){
        cout<<"Engine has started"<<endl;
    }

    void stopEngine(){
        cout<<"Engine has stopped"<<endl;
    }

public:
    void start(){
        startEngine();
        cout<<"Car is now running"<<endl;
    }

    void stop(){
        stopEngine();
        cout<<"Car has now stopped"<<endl;
    }
};

int main(){
    Car bugatti;
    bugatti.start();
    bugatti.stop();
}
*/

//abstraction using pure abstract class and virtual functions
/*
class Shape{
public:
    //pure virtual class providing interface for derived classes
    virtual void draw()=0;

};

class Circle:public Shape{
public:
    void draw() override{
        cout<<"Drawing a circle"<<endl;
    }
};

class Square:public Shape{
public:
    void draw() override{
        cout<<"Drawing a Square"<<endl;
    }
};

int main(){
 //   Shape s; // cant create an object of abstract class
    Circle c;
    Square sq;

    c.draw();
    sq.draw();
  //  s.draw();
}
 */

//STL
// c++ stl -> 1)algorithms , 2) containers

//Using auto simplifies your code by letting the compiler infer the correct type
// without you having to explicitly write it,
// which is especially useful with complex types like iterators or pairs in C++.

//vector(dynamic array)
/*
int main(){
    vector<int> v;

    v.push_back(1);
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(4);
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(5);
    cout<<"Size -> "<<v.size()<<endl;
    cout<<"Capacity -> "<<v.capacity()<<endl;

    //finding mean
    //include <numeric>
    int sum = accumulate(v.begin(),v.end(),0);
    double mean = static_cast<double>(sum)/v.size();
    cout<<mean<<endl;
}
 */
//deque(doubly queue)
/*
int main(){
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(0);
    d.push_front(5);

    for(auto i : d){
        cout<<i<<" ";
    }cout<<endl;

    d.pop_back();
    for(auto i : d){
        cout<<i<<" ";
    }cout<<endl;
    d.erase(d.begin(),d.begin()+2);

    for(auto i : d){
        cout<<i<<" ";
    }
}
*/
//priority queue(max heap , min heap)
/*
int main(){
    priority_queue<int> maxi;
    priority_queue<int ,vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(5);
    maxi.push(10);
    maxi.push(0);

    int n = maxi.size();

    for(int i =0 ; i<n ; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;

    mini.push(1);
    mini.push(10);
    mini.push(0);
    mini.push(7);

    int m = mini.size();

    for(int i =0 ; i <m ; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;
}
*/
//set(unique value)
/*
int main(){
    set<int> s ;
    s.insert(1);
    s.insert(10);
    s.insert(20);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(0);


    for(auto i : s){
        cout<<i<<" ";
    }cout<<endl;

    set<int>::iterator it = s.find(10);
    s.erase(it);

    for(auto i : s){
        cout<<i<<" ";
    }cout<<endl;
}
*/
//map(key value pairs)
/*
int main(){
    map<int , string> m;
    m[0]="Abhinav";
    m[1]="Singh";

    m.insert({2,"God"});

    for(auto i : m){
        cout<<i.first<<" : "<<i.second<<endl;
    }
    cout<<"finding 0-> "<< m.count(0)<<endl;

    auto it = m.find(0);
    m.erase(it);

    for(auto i : m){
        cout<<i.first<<" : "<<i.second<<endl;
    }
}
*/
//algorithms
/*
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    v.push_back(10);
    v.push_back(12);

    //binary_search
    cout<<"finding 6-> "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"lower bound -> "<< lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"upper_bound -> "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    //min max
    int a = 5;
    int b = 3;
    cout<<max(a,b)<<endl;
    cout<<min(a,b)<<endl;

    //swap
    swap(a,b);
    cout<<"a: "<<a<<" b: "<<b<<endl;

    //reverse string
    string abc = "abcd";
    reverse(abc.begin(),abc.end());
    cout<<"String -> "<<abc<<endl;

    //rotate
    rotate(v.begin(),v.begin()+2,v.end());
    cout<<"after rotate"<<endl;

    for(auto i : v){
        cout<<i<<" ";
    }cout<<endl;

    //sort
    sort(v.begin(),v.end());

    cout<<"after sorting ";

    for(int i : v){
        cout<< i<<" ";
    }

    //trying to sort string
    sort(abc.begin(),abc.end());
    cout<<endl<<abc<<endl;
}
 */

//generics
//generic class with multiple params
/*
template<class T , class G>
class Number{
public:
    Number(T value , G variable){
        cout<<"Number entered is: "<<value<<" Second input is: "<<variable<<endl;
    }
};
int main(){
    Number num1(1,"GOD");
    Number num2(2.3,1);
    Number num3("Alpha",2.3333333);
}
*/
//generic function with multiple params
/*
template <class T, class G>
void number(T value , G var){
    cout<<"Entered value 1-> "<<value<<"\tEntered value 2->"<<var<<endl;
}
int main(){
    number("Abhinav","Human");
    number(1,1.2222222);
    number("Abhinav",1);
    number(1.2222,"Abhinav");
}
*/