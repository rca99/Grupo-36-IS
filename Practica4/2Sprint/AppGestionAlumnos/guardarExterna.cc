#include "BD.h"
#include <unistd.h>//sleep
#include "consoleLinux.h"
#include "consoleLinux.h"
#include <iomanip>//formato cout
#include <stdio.h>
#include <iostream>


bool BD::guardarBackup(){
	system("chmod +x guardarExterna.sh");
	cout<<BOLD_ON<<"\tPreparando el sistema para realizar la copia externa"<<RESET<<endl;
	sleep(1);
	

	system("./guardarExterna.sh");
	return 1;

}


