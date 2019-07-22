#include "stdafx.h"

struct employee {
	unsigned id;
	std::string name;
	std::string role;
	unsigned salary;
};

int main() {
	std::vector<employee> employees {
		{0, "User1", "Test1", 100},
		{1, "User2", "Test2", 101},
		{2, "User3", "Test3", 102},
		{3, "User4", "Test4", 103}
	};
	
	for (auto& [id, name, role, salary] : employees) {
		std::cout << "Name: " << name << "\t"
			      << "Role: " << role << "\t"
			      << "Salary: " << salary << '\n';
	}

	return 0;
}