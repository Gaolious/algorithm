// 128 - Software CRC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

 * The message to be transmitted is viewed as a long positive binary number. 
 * 
 * The first byte of the message is treated as the most significant byte of the binary number. 
 * The second byte is the next most significant, 
 * 
 * etc. This binary number will be called “m” (for message).
 * 
 * Instead of transmitting “m” you will transmit a message, “m2”, consisting of “m” followed by a two-byte CRC value.
 * 
 * The CRC value is chosen so that “m2” when divided by a certain 16-bit value “g” leaves a remainder of 0. 
 * 
 * 
 * This makes it easy for the receiving program to determine whether the message has been corrupted by transmission errors. 
 * It simply divides any message received by “g”. 
 * If the remainder of the division is zero, it is assumed that no error has occurred.
 * You notice that most of the suggested values of “g” in the book are odd, but don’t see
 * any other similarities, so you select the value 34943 for “g” (the generator value). 
 * 
 * 
 * m2 % g == 0, ( m + CRC ) % g == 0.
 * 
 * what is CRC ?
 *      - crc is 2 byte.
 *      - 
 * 
 */

#define MAX_N (1024)
#define G (34943)
char *trim(char *str)
{
    for ( int i = strlen(str)-1 ; i >= 0 ; i -- )
    {
        if ( str[i] == '\r' || str[i] == '\n')
            str[ i ] = 0x00;
        else
            break;
    }
    return str;
}
void process( FILE *fp )
{
    char in[MAX_N+1];
    
    while ( fgets(in, sizeof(in)-1, fp) && trim(in) && strcmp(in, "#") )
    {
        unsigned long m = 0 ;
        for ( int i = 0 ; i < strlen(in) && in[i] != '\n' && in[i] != '\r' ; i ++ )
            m = ( (m << 8) + in[ i ] ) % G;

        /// crc 2byte
        m = (m << 8) % G;
        m = (m << 8) % G;
        
        // ( m + CRC ) % g == 0.
        int crc = ( G - m ) % G;
        
        printf("%02X %02X\n", ( crc >> 8 ) & 0xFF , crc & 0xFF );
    }
}

int main() 
{ 
#ifdef ONLINE_JUDGE  
    FILE *fp = stdin; 
#else 
    FILE *fp = fopen("input.txt", "rt"); 
#endif 
 
    process(fp); 
 
#ifdef ONLINE_JUDGE  
#else 
    if ( fp ) fclose(fp); 
#endif 
 
    return 0; 
} 