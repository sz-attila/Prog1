#include "std_lib_facilities.h"

class B1{
public:
	virtual void pvf() = 0;
	virtual void vf() {cout<<"B1::vf()\n";}
	void f() {cout<<"B1::f()\n";}
};

class D1 : public B1 {
public:
	void pvf() override {cout<<"D1::pvf()\n";}
	void vf() override {cout<<"D1::vf()\n";}
	void f() {cout<<"D1::f()\n";}
};

class D2 : public D1{
public:
	void pvf() override {cout<<"D2::pvf()\n";}
};

class B2{
public:
	virtual void pvf() = 0;
};

class D21 : public B2{
public:
	string str = "Hello";
	void pvf() override {cout<<str<<endl;}
};

class D22 : public B2{
public:
	int i = 0;
	void pvf() override {cout<<i<<endl;}
};

void f(B2& b1){
	b1.pvf();
};


int main(){
	B1 b1;
	b1.vf();
	b1.f();
	cout<<endl;

	D1 d1;
	d1.vf();
	d1.f();
	cout<<endl;

	B1& B1Ref = d1;
	B1Ref.f();
	B1Ref.pvf();
	B1Ref.vf();
	cout<<endl;

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	cout<<endl;

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

	return 0;


}