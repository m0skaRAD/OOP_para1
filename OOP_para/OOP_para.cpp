#include <iostream>
using namespace std;

class Person {
private:
	char* _name;
	int _age;
	int _id;
	const int _temp;
public:
	static int totalPeopleCount;
	Person(const char* name, int age, int id, int temp) : _name{ name ? new char[strlen(name) + 1] : nullptr },
		_age{ age }, _id{ id }, _temp{ temp }
	{
		this->_id = id; //This sberigae adresu na object. Vin constantniy, i dla inshogo vikoristanna potribno pochistit pamyat (deconstructor)
		
		if (name) {
			strcpy_s(_name, strlen(name) + 1, name);
		}
		cout << "Person constructor" << endl;
		totalPeopleCount++;
	}
	Person() : Person(nullptr, 0, 0, 0){}
	Person(const char* name) : Person(name, 0, 0, 0){}
	Person(const char* name, int age) : Person(name, age, 0, 0){}

	~Person() {
		totalPeopleCount--;
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
	

	//V seredini statichnogo metoda mayut buti tilki statichni pola
	static int power(int x) {
		return x*x;
	}

};

//Statichni pola potribno initializuvati poza clasom i main
int Person::totalPeopleCount = 0;
int main()
{
	int Result = Person::power(5);
	Person p1; //default constructor;
	p1.Print(); //Print zberigae adresu na p1
	Person p2("Alex");
	p2.Print();//Tut na p2
	Person p3("Alex", 10);
	p3.Print();
	Person p4("Alex", 10, 1977, 13);
	p4.Print();
	cout << Person::totalPeopleCount << endl;

	 
	//new 
}
