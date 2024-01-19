#include "monty.h"
/**                                                                                                                                                                                       
* execute - executes the opcode                                                                                                                                                           
* @stack: head linked list - stack                                                                                                                                                        
* @counter: line_counter                                                                                                                                                                  
* @file: poiner to monty file                                                                                                                                                             
* @content: line content                                                                                                                                                                  
* Return: no return                                                                                                                                                                       
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
        instruction_t opst[] = {
                                {"push", mrkd_push}, {"pall", mrkd_pall}, {"pint", mrkd_pint},
                                {"pop", mrkd_pop},
                                {"swap", mrkd_swap},
                                {"add", mrkd_add},
                                {"nop", mrkd_nop},
                                {"sub", mrkd_sub},
                                {"div", mrkd_div},
                                {"mul", mrkd_mul},
                                {"mod", mrkd_mod},
                                {"pchar", mrkd_pchar},
                                {"pstr", mrkd_pstr},
                                {"rotl", mrkd_rotl},
                                {"rotr", mrkd_rotr},
                                {"queue", mrkd_queue},
                                {"stack", mrkd_stack},
                                {NULL, NULL}
                                };
        unsigned int i = 0;
        char *op;

        op = strtok(content, " \n\t");
        if (op && op[0] == '#')
                return (0);
        bus.arg = strtok(NULL, " \n\t");
        while (opst[i].opcode && op)
         {
                if (strcmp(op, opst[i].opcode) == 0)
                {       opst[i].f(stack, counter);
                        return (0);
                }
                i++;
        }
        if (op && opst[i].opcode == NULL)
        { fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
                fclose(file);
                free(content);
                free_stack(*stack);
                exit(EXIT_FAILURE); }
        return (1);
}
