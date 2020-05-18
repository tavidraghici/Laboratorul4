#pragma once
#include "Controller.h"
#include <string>
#include <iostream>

using namespace std;


Controller::Controller() {
	Repository repository;
	this->repo = repository;
}


Controller::Controller(Repository repository) : repo(repository) {

}
