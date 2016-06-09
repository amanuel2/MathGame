#include "./MainGame.cpp"
#include <stdlib.h>

int main() {
	srand(time(0));
	MainGame mg;
	mg.run();
}