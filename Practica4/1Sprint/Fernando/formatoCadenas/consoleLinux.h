#include <stdio.h>
/**
	See http://ascii-table.com/ansi-escape-sequences.php for escape sequences
 */

#define ANSI_COLOR_NORMAL  "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BRIGHTRED    "\x1b[91m"
 
enum consoleColor {
	COL_NORMAL=0,
	COL_RED,
	COL_GREEN,
	COL_YELLOW,
	COL_BLUE,
	COL_MAGENTA,
	COL_CYAN,
	COL_BRITHRED,
};

class consoleLinux {
public:
	consoleLinux() {
		printf("\033[r");
	}
	~consoleLinux() {}
	
	void setCursorPosition(int row, int col) {
		printf("\033[%d;%dH", row, col);
	}
	
	void clearScreen() {
		printf("\033[2J");
		fflush(stdout);
	}
	
	void clearLine() {
		printf("\033[K");
		fflush(stdout);
	}
	
	const char *codeToColor(consoleColor col) {
		switch(col) {
			default:
			case COL_NORMAL:
				return ANSI_COLOR_NORMAL;
			case COL_RED:
				return ANSI_COLOR_RED;
			case COL_GREEN:
				return ANSI_COLOR_GREEN;
			case COL_YELLOW:
				return ANSI_COLOR_YELLOW;
			case COL_BLUE:
				return ANSI_COLOR_BLUE;
			case COL_MAGENTA:
				return ANSI_COLOR_MAGENTA;
			case COL_CYAN:
				return ANSI_COLOR_CYAN;
			case COL_BRITHRED:
				return ANSI_COLOR_BRIGHTRED;
		}
	}
	
	void setColor(consoleColor col) {
		printf("%s", codeToColor(col));
	}
	
	void updateScreen(void) {
		printf("\033[H");
		fflush(stdout);
	}
};
