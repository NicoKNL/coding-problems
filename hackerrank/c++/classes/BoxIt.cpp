#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
private:
    int l, b, h;
public:
    Box() {
        l = b = h = 0;
    }

    Box(int l, int b, int h){
        this->l = l;
        this->b = b;
        this->h = h;
    }

    Box(Box& box) {
        this->l = box.getLength();
        this->b = box.getBreadth();
        this->h = box.getHeight();
    }

    int getLength() {
        return l;
    }

    int getBreadth () {
        return b;
    }
    int getHeight (){
        return h;
    }
    long long CalculateVolume(){
        long long volume = (long long) l * (long long) b * (long long) h;
        return volume;
    }

    bool operator<(Box& box) {
        if (this->l < box.getLength()) {
            return true;
        } else if (this->b < box.getBreadth() && this->l == box.getLength()) {
            return true;
        } else if (this->h < box.getHeight() && this->b == box.getBreadth() && this->l == box.getLength()) {
            return true;
        } else {
            return false;
        }
    }

    string to_string() {
        stringstream ss;
        ss << l << " " << b << " " << h;
        return ss.str();
    }
};

ostream& operator<<(ostream& out, Box& box) {
    out << box.to_string();
    return out;
}


void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}