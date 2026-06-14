#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

int child_pid;	//globally declared 

void timeout_handler(int sig){		//if child stucks then it will kill that child process
	printf("Heartbeat missed!\n");
	kill(child_pid, SIGKILL);
}

void heartbeat_handler(int sig){	//used when received signal
	printf("Heartbeat Received\n");
	alarm(5);	//Reset timer
}


int main(){
	printf("Starting of project..\n");

	signal(SIGUSR1, heartbeat_handler);	//initialization of SIGUSR1
	signal(SIGALRM, timeout_handler);	//initialization of SIGALRM
	while(1){
		child_pid = fork();
		if(child_pid == 0){	//child
			printf("CHILD PID: %d\n",getpid());
			
			execl("./worker","work",NULL);	//goes in perticular file and executes
			perror("execl failed");
			
			exit(1);
		}
		else{			//parent
			int status;
			printf("PARENT PID: %d\n",getpid());
			alarm(5);
			waitpid(child_pid, &status, 0);		//collecting childs status
			alarm(0);
			printf("Child Terminated\n");

			sleep(1);
			if(WIFEXITED(status)){
				printf("Child exited normally\n");
				printf("Exit Status = %d\n",WEXITSTATUS(status));
			}
			else if(WIFSIGNALED(status)){
				int sig = WTERMSIG(status);
				if(sig == SIGKILL)
					printf("Worker killed by watchdog\n");
				else
					printf("Worker crashed by signal %d\n", sig);
			}
		}	
	}
	return 0;
}
