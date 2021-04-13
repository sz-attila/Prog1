#include "std_lib_facilities.h"

template<typename T>
struct S
{

	S() {}
	
	S(T t)
	: val(t)
	{}


	S& operator=(const T& newValue) { val = newValue; return *this; }
	//istream operator>>(T t) { cin >> val; }

	void set(T t) { val = t; }
	const T& get() const { return val; }
	T& getRef() {return val;}

private:

	T val;
};

template<typename T>
const T& get(S<T>& s)
{
	return s.get();
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
{
	S<int> i;
	cout << "Enter int: "; read_val(i.getRef());
	cout << i.get() << endl;

	S<char> ch;
	cout << "Enter char: "; read_val(ch.getRef());
	cout << ch.get() << endl;

	S<double> db;
	cout << "Enter double: "; read_val(db.getRef());
	cout << db.get() << endl;

	S<string> st;
	cout << "Enter string: "; read_val(st.getRef());
	cout << st.get() << endl;

	S<vector<int>> ve(vector<int>(10, 19));
	cout << "Enter 10 ints: ";
	for (int i = 0; i < 10; ++i)
		read_val(ve.getRef()[i]);
	for (int i : ve.get())
		cout << i << ", ";

	cout << endl;

	keep_window_open();
	return 0;
}