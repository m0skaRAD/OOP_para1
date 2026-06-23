#include <iostream>
using namespace std;

class Person {
private:
	char* _name;
	int _age;
	int _id;
	const int _temp;
public:
	Person(const char* name, int age, int id, int temp) : _name{ name ? new char[strlen(name) + 1] : nullptr },
		_age{ age }, _id{ id }, _temp{ temp }
	{
		this->_id = id; //Зис зберігає адресу на об'єкт.
		
		if (name) {
			strcpy_s(_name, strlen(name) + 1, name);
		}
		cout << "Person constructor" << endl;
	}
	Person() : Person(nullptr, 0, 0, 0){}
	Person(const char* name) : Person(name, 0, 0, 0){}
	Person(const char* name, int age) : Person(name, age, 0, 0){}

	~Person() {
		delete[] _name;
	}
	void Print() {
		if (_name) {
			cout << "Name: " << _name << endl;
			cout << "Age: " << _age << endl;
			cout << "Id: " << _id << endl;
			cout << "Temp: " << _temp << endl;
		}
	}

};

int main()
{
	Person p1; //default constructor;
	p1.Print(); //Прінт зберігає адресу на П1
	Person p2("Alex");
	p2.Print();//Тут, на п2
	Person p3("Alex", 10);
	p3.Print();
	Person p4("Alex", 10, 1977, 13);
	p4.Print();

	 

}