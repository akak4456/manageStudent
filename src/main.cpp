#include <iostream>
#include "model.h"
#include "view.h"
#include "controller.h"
using namespace std;

int main() {
	Model* model = new Model();
	View* view = new View();
	Controller* controller = new Controller();
	model->init(controller);
	view->init(controller);
	controller->init(model, view);
	controller->loadData();
	view->showLogin();
	delete model;
	delete view;
	delete controller;
	return 0;
}