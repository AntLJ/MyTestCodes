#include <iostream>
using namespace std;

class File
{
private:
	int m_int;
public:
	File():m_int(0)
	{
		std::cout << "File Constructor" << std::endl;
		open(); // bad !! open function overrided in sub class has not been called
	}
	~File()
	{
		std::cout << "File Destructor" << std::endl;
		close(); // bad !! close function overrided in sub class has not been called
	}
	virtual void open()  {}
	virtual void close() {}

};
class SubFile:public File
{
public:
	void open()  override { std::cout << "SubFile open"  << std::endl; }
	void close() override { std::cout << "SubFile close" << std::endl; }
};
