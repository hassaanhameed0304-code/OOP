#include <iostream>
using namespace std;

class Base{
private:
    int privateInt;
protected:
    int protectedInt;
public:
    int publicInt;
	void setPrivateInt(int v){ 
		privateInt = v; 
	}
    int getPrivateInt() const{ 
		return privateInt; 
	}

    void setProtectedInt(int v){ 
		protectedInt = v; 
	}
    int getProtectedInt() const{ 
		return protectedInt; 
	}

    void setPublicInt(int v){ 
		publicInt = v; 
	}
    int getPublicInt() const{ 
		return publicInt; 
	}
};

class publicChild : public Base {
public:
    void setValues() {
        setPrivateInt(1);
        protectedInt = 2;
        publicInt = 3;
    }

    void showAccess() {
        cout << "publicChild access:" << endl;
        cout << "privateInt via getter: " << getPrivateInt() << endl;
        cout << "protectedInt directly: " << protectedInt << endl;
        cout << "publicInt directly: " << publicInt << endl;
    }
};

class protectedChild : protected Base{
public:
    void setValues(){
        setPrivateInt(4);
        protectedInt = 5;
        publicInt = 6;
    }

    void showAccess(){
        cout << "protectedChild access:" << endl;
        cout << "privateInt via getter: " << getPrivateInt() << endl;
        cout << "protectedInt directly: " << protectedInt << endl;
        cout << "publicInt directly: " << publicInt << endl;
    }
};

class privateChild : private Base{
public:
    void setValues(){
        setPrivateInt(7);
        protectedInt = 8;
        publicInt = 9;
    }

    void showAccess(){
        cout << "privateChild access:" << endl;
        cout << "privateInt via getter: " << getPrivateInt() << endl;
        cout << "protectedInt directly: " << protectedInt << endl;
        cout << "publicInt directly: " << publicInt << endl;
    }
};

int main(void){
    publicChild pc;
    pc.setValues();
    pc.showAccess();
    cout << "Accessing publicInt directly from object: " << pc.publicInt << endl;
    cout << "Accessing privateInt via getter: " << pc.getPrivateInt() << endl;

    cout << endl;

    protectedChild prc;
    prc.setValues();
    prc.showAccess();

    cout << endl;

    privateChild pvc;
    pvc.setValues();
    pvc.showAccess();

    return 0;
}
