#include <iostream>
#include "app.hpp"

// THIS IS THE BASE PROJECT - the template for all others.
using namespace std;

int main(int argc, char *argv[]) {
	main_app app;

	return app.run();
}