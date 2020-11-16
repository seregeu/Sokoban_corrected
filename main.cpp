#include "sokoban.h"

int main(void) {
	//Character character(0, 0);
	Field field;
	field.LoadLevel(0);
	field.Game();
	return 0;
}