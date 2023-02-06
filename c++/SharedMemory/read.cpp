// ShareMemory Reader
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
using namespace std; 

int main() 
{ 
	int ch = '1';
	// ftok to generate unique key 
	key_t key = ftok("shmfile",65); 

	// shmget returns an identifier in shmid 
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	while(ch != 'e')
	{
		printf("Press ENTER key to Read...");
		printf("or Press 'e' key to Exist...\n");
		ch = getchar();
		if (ch == 'e')
		{
			continue;
		}
		// shmat to attach to shared memory 
		char *str = (char*) shmat(shmid,(void*)0,0); 

		printf("Data read from memory: %s\n",str); 
		// detach from shared memory 
		shmdt(str);
		// printf("Press ENTER key to Continue...");
		// printf("or Press 'e' key to Exist...\n");
		// ch = getchar();                //get the char and set ch to 'e'
	}
	// destroy the shared memory 
	shmctl(shmid,IPC_RMID,NULL); 
	return 0; 
}