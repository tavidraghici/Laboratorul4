#pragma once
#include "Controller.h"
class ApothekeUI{
private:
    Controller ctrl;
public:
    ApothekeUI(Controller controller);
    void UI();/// programul efectiv care include tot meniul si care este apelat in main
};

