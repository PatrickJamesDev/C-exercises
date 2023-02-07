#include "bits.h"
#include <stdio.h>
#include <stdlib.h>

/* DESCRIPTION:
 * ------------
 * The function clears a bit with index i (makes the bit active (1)) in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: an array of binary data.
 * int i: the index of the bit.
 *
 * RETURNS:
 * ------------
 * modified data.
 *
 */
uint32_t op_bit_set(uint32_t data, int i) //works
{
    
    int bit_mask= (1<<i); // ith bit from the right is set as the mask  (000000.....1....(i-1)*0)
    data = data | bit_mask; //sets ith bit as 1 using OR, because ith bit is set in mask, so naturally OR will cause the bit to be set in data, if it already wasn't 
    return data;
}

/* DESCRIPTION:
 * ------------
 * The function clears a bit with index i (makes the bit inactive (0)) in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit.
 *
 * RETURNS:
 * ------------
 * modified.
 *
 */

uint32_t op_bit_clear(uint32_t data, int i) //works!

{
    //int i;
    int bit_mask= (1<<i);
    data = data & ~bit_mask;  //Inverse AND so AND NOT   so because ith bit is set as 1 in mask, if ith bit is set as 1 in data, it becomes 0 due to AND NOT. 
    return data;
}

/* DESCRIPTION:
 * ------------
 * The function toggles a bit with index i in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit which to set as inactive (0).
 *
 * RETURNS:
 * ------------
 * modified data.
 *
 */

uint32_t op_bit_toggle(uint32_t data, int i) //works
{
    //int i;
    int value = op_bit_get(data, i);
    int bit_mask= (1<<i);
    if (value == 1)
    {
        data = data & ~bit_mask;
    } 
    else 
    {
        data = data | bit_mask; // using OR, because mask has 1 at ith bit, even if data doesn't yet, data's ith bit will become 1
    }
    
    return data;
}

/* DESCRIPTION:
 * ------------
 * The functions returns 1 or 0 depending on whether the bit with index i in
 * the binary data is set or not.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit which value to return.
 *
 * RETURNS:
 * ------------
 * 0: if the bit was not set.
 * 1: if the bit was set.
 */

int op_bit_get(uint32_t data, int i)
{

 /*    int counter = 0;
    
    //data = ((ith==1) ? 1: 0 );
    for (;counter<32;counter++)
        {
            data = ((counter == i) ? 1:0);
            if (counter == i)
            {
                data = 1;
            }
                
        }
    return data;  */

    data = (data >> i) & 1;

    //data = (data >> i) & 1? 1:0;
    return data;
}

/* DESCRIPTION:
 * ------------
 * The function prints the binary representation of the parameter unsigned char
 * to the standard output as 1s and 0s. Note that one unsigned char is 8 bits.
 * There is no newline at the end of the print.
 *
 * For example:
 *
 * unsigned char b = 0xF8;
 * print_byte(b);
 *
 * Would print out:
 *
 * 11111000
 *
 * PARAMETERS:
 * ------------
 * unsigned char b: the binary sequence.
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */

void op_print_byte(unsigned char b) // works
{
    int binary[9];
    //int b;
    
    for (int i=0; i < 8; i++)
    {
        binary[7-i] = (b & (1<<i)  ? '1' : '0'); 
        
    }
    binary[8] = '\0';
    for (int i=0; i < 8; i++)
    {
        printf("%c", binary[7-i]);
    }
    

    //printf("%c", binary);
    
}
