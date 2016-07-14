#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

const std::vector<std::string> MonthName{ "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", 
										"Sept", "Oct", "Nov", "Dec" };
const std::string numbers{"0123456789"};

class Data {
public:
	Data() : year(1970), month(1), day(1) { };
	Data(std::string);
private:
	unsigned year;
	unsigned month;
	unsigned day;
};

bool valid_day(unsigned, unsigned, unsigned);

Data::Data(std::string str) 
{
	unsigned y(0), m(0), d(0);
	decltype(str.size()) pos(0);
	for (decltype(MonthName.size()) i = 1; i != 13; ++i)
		if (str.find(MonthName[i]) != std::string::npos)
		{
			m = i;
			break;
		}
	if (m == 0)
	{
		m = stoi(str = str.substr(str.find_first_of(numbers)), &pos);
		if (m > 12)
			return;
	}

	d = stoi(str = str.substr(str.find_first_of(numbers, pos)),&pos);
	
	y = stoi(str.substr(str.find_first_of(numbers, pos)));
	
	if (!valid_day(d, m, y))
		return;

	year = y;
	month = m;
	day = d;
}

bool valid_day(unsigned d, unsigned m, unsigned y)
{
	if (d == 0 || d > 31)
		return false;
	switch (m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return true;
		case 4: case 6: case 9: case 11:
			return d != 31;
		case 2:
			if (y % 4)
				return d < 29;
			else if (y % 100)
				return d < 30;
			else if (y % 400)
				return d < 29;
			else
				return d < 30;
	}
}

#endif
