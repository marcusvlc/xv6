#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main (int argc, char *argv[]) {
	int id = atoi(argv[1]);
	if(id > 0){
		getusage(id);
	} else {
		printf(1, "Insira um número inteiro como id maior do que 0 \n", id);
	}
	exit();
}
