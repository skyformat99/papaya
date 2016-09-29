#include "syscall.h"
#include "../src/include/linux/wait.h"

char *__argv[] = {
	"this is arg1",
	"and arg2",
	"arg3",
	0
};

char * __envp[] = {
	"HOME=/wws",
	"PATH=/wws/lab/yanqi/cmd:/wws/software",
	0
};

#define __argc (sizeof(__argv) / sizeof(char *))

static char g_array[10] = {1, 2, 3, 4, 5, 6};
int static_array[1024];
void init(int argc, char *argv[], char *envp[]){
	int x;
	for(int i = 0; i < 10; i++) printf("%u\n", g_array[i]);
	int ret = fork();
	printf("I am back ! %u\n", ret);
	if(ret == 0){		//子进程演变成cat
		execve("/home/cat", __argv, __envp);	
	}
	int exit_code;
	int got;
	while( (got = wait4(ret, &exit_code, WNOHANG, 0)) <= 0){
		if(got == 0) ;
			//printf("saw ");
			//printf("i saw her, she haven't exited yet\n");
		else if(got == -1){
			printf("pid %u is not your child!", ret);
			while(1);
		}
		else {
			printf("wait4 return bad value\n");
			while(1);
		}
	}
	printf("task %u exit! %u\n", got, exit_code);
	while(1){
		static_array[1023] = 3;
		char c = ret == 0 ? '+' : '-';
		//printf("%c ", c);
	}
}









