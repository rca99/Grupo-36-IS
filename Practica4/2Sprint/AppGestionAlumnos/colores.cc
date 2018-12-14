#include <iostream>

#include "consoleLinux.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << COLOR_NORMAL << "NORMAL:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_RED << "RED:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_GREEN << "GREEN:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << BOLD_GREEN << "GREEN:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << BOLD_BRIGHTGREEN << "GREEN:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_BRIGHTGREEN << "BRIGHTGREEN:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_YELLOW << "YELLOW:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_BRIGHTYELLOW << "BRIGHTYELLOW:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_MAGENTA << "MAGENTA:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_BRIGHTRED << "BRIGHTRED:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_BRIGHTBLUE << "BRIGHTBLUE:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_DARKGREY << "DARKGREY:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_LIGHTGREY << "LIGHTGREY:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << BOLD_ON << COLOR_BLUE << "BLUE\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_CYAN << "CYAN:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_LIGTHCYAN << "LIGHTCYAN:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << COLOR_BLACK << "BLACK:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << UNDERLINE_ON << "UNDERLINE_ON:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << UNDERLINE_OFF << "UNDERLINE_OFF:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << BLINK << "BLINK:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	//cout << FAST_BLINK << "FAST BLINK:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	//cout << FAINT << "FAINT:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << BOLD_ON << "BOLD_ON:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << GRIS_CLARO << "GRISCLARO:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << GRIS_OSCURO << "GRISOSCURO:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << INVERTIDO << "INVERTIDO:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << OCULTO << "OCULTO:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << CONGELADO << "CONGELADO:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	//cout << CROSSED_ON << "CROSSED_ON:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	//cout << CROSSED_OFF << "CROSSED_OFF:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	//cout << ITALIC << "ITALIC:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	//cout << NO_ITALIC << "NO ITALIC:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << BOLD_RED << "BOLDRED:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << ON_BLACK << "ONBLACK:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << ON_RED << "ONRED:\t\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << ON_WHITE << "ONWHITE:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << ON_GREEN << "ONGREEN:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << ON_ORANGE << "ONORANGE:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;
	cout << ON_LIGHTGREY << "ONLIGHTGREY:\t\tHOLA, Hola, hola, 1234567890,!$%&/()" << RESET <<endl;

	return 0;
}