#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/**
 * struct GlobalStruct - contains all globals
 * @data: int for push
 * @monty_stream: file stream for monty
 * @lineptr: pointer to the string allocated by getline function
 */
struct GlobalStruct
{
	int data;
	FILE *monty_stream;
	char *lineptr;
} global;


/*function prototypes*/
int main(int argc, char **argv);
void opcode_error(stack_t **stack, int line_number, char *opcode);
void opcmp(stack_t **stack, int line_number, char *opcode);
/*void push(stack_t **stack, unsigned int line_number);*/
void push(stack_t **stack, unsigned int line_number __attribute__((unused)));
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/*helper function prototypes*/
int _iswhitespace(void);
void free_stack(stack_t *stack);
void exit_free(stack_t *stack);

/*errors prototytpes*/
void args_error(void);
void malloc_error(stack_t **stack);
void file_error(char *filename);
void push_error(stack_t *stack, int line_number);
void pint_error(stack_t **stack, int line_number);
void pop_error(stack_t **stack, int line_number);
void swap_error(stack_t **stack, int line_number);
void add_error(stack_t **stack, int line_number);
void sub_error(stack_t **stack, int line_number);
void div_error1(stack_t **stack, int line_number);
void div_error2(stack_t **stack, int line_number);
void mul_error(stack_t **stack, int line_number);
void mod_error(stack_t **stack, int line_number);
void opcode_error(stack_t **stack, int line_number, char *opcode);
void pchar_error1(stack_t **stack, int line_number);
void pchar_error2(stack_t **stack, int line_number);

#endif /*_MONTY_H*/
