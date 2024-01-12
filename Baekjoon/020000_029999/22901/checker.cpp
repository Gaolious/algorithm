#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

const char *execute_path = "./cmake-build-debug/boj";

int	outfd[2];
int	infd[2];

void run_child() {
    close(STDOUT_FILENO);
    close(STDIN_FILENO);
    
    dup2(outfd[0], STDIN_FILENO);
    dup2(infd[1], STDOUT_FILENO);

    close(outfd[0]);
    close(outfd[1]);
    close(infd[0]);
    close(infd[1]);

	system(execute_path);
}

void send(int n) {
    char s[1024];
    int len ;

    sprintf(s, "%d", n);
    len = strlen(s);
    write(outfd[1], s, len );
    write(outfd[1], "\n", 1);

//    printf("[S] Send %d\n", n);
//    fflush(stdout);

}

bool receive(char &c, int &n) {
	char input[100]={0,};

	int len = read(infd[0],input,100) ;
    input[ len >= 100 ? 100 : len ] = 0x00;
    sscanf(input, "%c %d", &c, &n);
//    printf("[S] Received : %c %d\n", c, n);
//    fflush(stdout);

    return true;
}

void logic() {
    int n = 0 ;
    int ans;
    char c ;
    bool fake;
    send(300);

    for ( ans = 2100 ; ans <= 2399 ; ans ++ ) {
        fake = false ;
        for ( int i = 1 ; i <= 30 ; i ++ ) {

            receive(c, n);
            if ( c == '!' )
            {
                if ( n == ans ) {
                    if ( i > 13 ) printf("correct ans=%d, iter=%d\n", ans, i);
                }
                else {
                    printf("Incorrect ans=%d, iter=%d\n", ans, i);
                }
                fflush(stdout);
                break;
            }
            if ( n <= ans)
                send(1);
            else
            {
                if ( !fake && random() % 2 == 0 )
                {
                    send(1);
                    fake = true ;
                }
                else
                    send(0);
            }
        }
    }

}

int main()
{
	pipe(outfd);
	pipe(infd);
	
	if(!fork())
	{
	    run_child();
        return 0;
	}
		
	close(outfd[0]);
	close(infd[1]);
    
    logic();
	
	close(outfd[1]);
	close(infd[0]);
}
