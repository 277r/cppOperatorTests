#include <iostream>
#include <string>

class Thing {
public:
	char *data;
	int size = 0;

	// thing is normally exists
	// thing appending 
	Thing &operator += (Thing& rhs)
	{
		for (int i = size; i < (size + rhs.size); i++){
			data[i] = rhs.data[i - size];
		}
		size += rhs.size;
		return *this;
	}
	// string 
	Thing &operator = (std::string &rhs)
	{
		for (int i = 0; i <  rhs.size(); i++)
		{
			data[i] = rhs[i];
		}
		size = rhs.size();
		return *this;
	}
	// string appending
	Thing &operator+=(std::string &rhs)
	{
		for (int i = size; i < (size + rhs.size()); i++)
		{
			data[i] = rhs[i - size];
		}
		size += rhs.size();
		return *this;
	}
	// no pointer string
	Thing &operator=(std::string rhs)
	{
		for (int i = 0; i < rhs.size(); i++)
		{
			data[i] = rhs[i];
		}
		size = rhs.size();
		return *this;
	}
	// no pointer string appending
	Thing &operator+=(std::string rhs)
	{
		for (int i = size; i < (size + rhs.size()); i++)
		{
			data[i] = rhs[i - size];
		}
		size += rhs.size();
		return *this;
	}


	// char 
	Thing &operator=(char &rhs)
	{
		data[0] = rhs;
		size = 1;
		return *this;
	}

	// char appending
	Thing &operator+=(char &rhs)
	{
		
		data[size] = rhs;
		size++;
		return *this;
	}

	// no pointer char
	Thing &operator=(char rhs)
	{
		data[0] = rhs;
		size = 1;
		return *this;
	}

	// no pointer char appending
	Thing &operator+=(char rhs)
	{

		data[size] = rhs;
		size++;
		return *this;
	}


	// multiply string
	Thing &operator*(const int &rhs)
	{
		Thing x = *this;
		for (int i = 0; i < rhs; i++)
		{
			*this += x;
		}
		return *this;
	}
	// multiply appending??
	Thing &operator*=(const int &rhs)
	{
		Thing x = *this;
		for (int i = 0; i < rhs; i++)
		{
			*this += x;
		}
		return *this;
	}
	

	void init(){
		data = new char[512];
		size = 0;
		return;
	}
};

int main(){
	Thing a, b, c, d;
	c.init();
	d.init();
	c = std::string("haha, string multiplication in c++ goes b");
	d = 'r';
	d *= 10;
	c += d;
	std::cout << std::string(c.data, c.size) << '\n';
}