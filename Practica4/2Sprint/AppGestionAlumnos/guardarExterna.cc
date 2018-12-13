#include "BD.h"
#include <unistd.h>//sleep
#include "consoleLinux.h"
#include "consoleLinux.h"
#include <iomanip>//formato cout
#include <stdio.h>
#include <iostream>


bool BD::guardarBackup(){
	system("chmod +x guardarExterna.sh");
	system("./guardarExterna.sh");
	return 1;

}


