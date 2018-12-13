#include "BD.h"
#include <cstdlib>


bool BD::guardarBackup(){
	system("chmod +x guardarExterna.sh");
	system("./guardarExterna.sh");
	return 1;

}


