#pragma once
#include "UI.h"
#include "Tests.h"
#include <iostream>
int main() {
	std::cout << "Testing!!\n\n";
    Tests().FULLTEST();
	std::cout << "Tests Over!!\n\n";
	Repository repo;
	Medikament m1 = Medikament("Paracetamol", 300, 10, 22);
	Medikament m2 = Medikament("Nurofen", 500, 15, 32.5);
	repo.einfugen(m1);
	repo.einfugen(m2);
	Controller ctrl = Controller(repo);
    ApothekeUI au = ApothekeUI(ctrl);
	au.UI();
	return 0;
}
