#include <iostream>
#include <initializer_list>
#include <string>
#include <tuple>
#include <vector>
#include "Sales_data.h"

using matches = std::tuple<std::vector<Sales_data>::size_type,
                           std::vector<Sales_data>::const_iterator,
					       std::vector<Sales_data>::const_iterator>;

std::vector<std::vector<Sales_data>> createFiles(
		std::initializer_list<std::string>);
std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &,
		const std::string &);
void reportResults(std::istream &, std::ostream &,
		const std::vector<std::vector<Sales_data>> &);
