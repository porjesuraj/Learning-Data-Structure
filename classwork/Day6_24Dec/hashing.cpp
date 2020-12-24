#include<iostream>
#include<string>
#include<list>

using namespace std;

class Exception
{
private:
	string message;
public:
	Exception( string message )
	{
		this->message = message;
	}
	string getMessage( )
	{
		return this->message;
	}
};
class Employee
{
private:
	string name;
	int empid;
	float salary;
public:
	Employee(  int empid )
	{
		this->empid = empid;
	}
	Employee( string name = "", int empid = 0, float salary = 0 )
	{
		this->name = name;
		this->empid = empid;
		this->salary = salary;
	}
	int hashCode( void )
	{
		const int PRIME = 31;
		int result = 1;
		result = result * this->empid + PRIME;
		return result;
	}
	bool operator==( Employee &other )
	{
		return this->empid == other.empid;
	}
	friend ostream& operator<<( ostream &cout, Employee &other )
	{
		cout<<other.name<<"	"<<other.empid<<"	"<<other.salary;
		return cout;
	}
};
class Department
{
private:
	string name;
	string location;
public:
	Department( string name = "", string location = "" )
	{
		this->name = name;
		this->location = location;
	}
	friend ostream& operator<<( ostream &cout, Department &other )
	{
		cout<<other.name<<"	"<<other.location;
		return cout;
	}
};
class HashTable
{
private:
		int size;
		list< pair<Employee, Department > > *arr;
public:
		HashTable( void )
		{
			this->size = 7;
			this->arr = new list< pair<Employee, Department > >[ this->size ];
		}
		void put( Employee key, Department value )
		{
			int hashCode = key.hashCode();
			int slot = hashCode % this->size;
			pair<Employee, Department> data( key, value );
			this->arr[ slot ].push_back(data);
		}
		Department find( Employee key )
		{
			int hashCode = key.hashCode();
			int slot = hashCode % this->size;
			list< pair<Employee, Department> >::iterator itrStart = this->arr[ slot ].begin();
			list< pair<Employee, Department> >::iterator itrEnd = this->arr[ slot ].end();
			while( itrStart != itrEnd )
			{
				if( (*itrStart).first == key  )
					return (*itrStart).second;
				++ itrStart;
			}
			throw Exception("Employeee not found");
		}
		~HashTable( void )
		{
			if( this->arr != NULL )
			{
				delete[] this->arr;
				this->arr = NULL;
			}
		}
};
int main( void )
{
	HashTable ht;
	ht.put(Employee("Yogesh", 23, 56000), Department("TCT","PUNE"));
	ht.put(Employee("Akash", 24, 57000), Department("TCT","Karad"));
	ht.put(Employee("Sanjay",25, 40000), Department("SAN","PUNE"));
	ht.put(Employee("Rupesh",26, 35000), Department("SAN","Karad"));
	ht.put(Employee("Prashant",22, 45000), Department("ACCOUNT", "PUNE"));


	Employee key( 25 );
	Department d = ht.find(key);
	cout<<d<<endl;
	return 0;
}
