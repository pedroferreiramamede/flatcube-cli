#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <termios.h>

int drawBox(int lines, int col, int lpos, int cpos, int cursor);
void *init(void *arg);
void *readInput(void *arg);

char c = 0;

int main(int argc, char** argv){
	pthread_t thread_id;
    	pthread_create(&thread_id, NULL, init, NULL);
        pthread_create(&thread_id, NULL, readInput, NULL);
        pthread_join(thread_id, NULL);

	exit(0);
}	

/* getch() foi presente de:
 * https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
 */
char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);
    return buf;
 }

void *readInput(void *arg){
	char temp;
	while(1){      
		temp = getch();
		if(temp == 'w')
			c = -1;
		if(temp == 's')		
			c = 1;
	}
} 

void *init(void *arg)
{ 
        int col = 75;//atoi(argv[2]);
	int lines = 15;//atoi(argv[1]);
	int cpos = 0; //atoi(argv[4]);
	int lpos = 0; //atoi (argv[3]);	
	bool going = true;
	bool upping = true;
        int cursor = lines/2;
	bool cursor_upping = true;

	while(1){
		
		printf("\033[2J");
    		printf("\033[%d;%dH", 0, 0);

		going ? cpos+=3 : cpos-=3;
		upping ? lpos++ : lpos--;
		//cursor_upping ? cursor++ : cursor--;	
		if(cpos >= col-1 || cpos == 0){
			going = !going;
		}
		if(lpos == lines-1 || lpos == 0){
			upping = !upping;
		}
		/*if(cursor == lines-1 || cursor == 0){
			cursor_upping = !cursor_upping;
		}*/


		usleep(70000);
		//drawBox(lines, col, lpos, cpos, lpos);
		drawBox(lines, col, lpos, cpos, cursor += c);
		c = 0;
	}
}

int drawBox(int lines, int col, int lpos, int cpos, int cursor){	
	printf("+");
	for(int i = 0; i < col; i++)
		printf("-");
	printf("+\n");

	for(int i = 0; i < lines; i++)
	{
		printf("|");
		for(int j = 0; j < col; j++)
		{
			if(j == 0 && (i == cursor || i == cursor+1 || i == cursor-1 )){
				printf("#");
			}else if(i == lpos && j == cpos){
				printf("o");
			}else{
				printf(" ");
			}
		}
		printf("|\n");
	}

        printf("+");
        for(int i = 0; i < col; i++)
                printf("-");
        printf("+\n");
}

