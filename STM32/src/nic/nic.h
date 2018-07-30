/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * nic.h - common declarations for nic compiler and interpreter
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_EXPR_EXPRESSION_STACK_DEPTH     32
#define MAX_POSTFIX_DEPTH                   (2 * (MAX_EXPR_EXPRESSION_STACK_DEPTH) + 1)

enum
{
    DEC_FORMAT,
    DEC0_FORMAT,
    HEX_FORMAT,
    BIN_FORMAT,
    STR_FORMAT
};

typedef enum
{
    EXPRESSION_NO_ERROR,
    EXPRESSION_ERROR,
    NO_COMPARE_OPERATOR,
    EQUAL_COMPARE_OPERATOR,
    NOT_EQUAL_COMPARE_OPERATOR,
    LESS_COMPARE_OPERATOR,
    LESS_EQUAL_COMPARE_OPERATOR,
    GREATER_COMPARE_OPERATOR,
    GREATER_EQUAL_COMPARE_OPERATOR,
    FUNCTION_RETURNING_VOID
} HANDLE_EXPRESSION_RTC;

enum
{
    OPERATOR,
    OPERAND_INT_CONSTANT,
    OPERAND_STRING_CONSTANT,
    OPERAND_TEMP_STRING_CONSTANT,
    OPERAND_LOCAL_INT_VARIABLE,
    OPERAND_LOCAL_INT_ARRAY_VARIABLE,
    OPERAND_GLOBAL_INT_VARIABLE,
    OPERAND_GLOBAL_INT_ARRAY_VARIABLE,
    OPERAND_LOCAL_BYTE_VARIABLE,
    OPERAND_LOCAL_BYTE_ARRAY_VARIABLE,
    OPERAND_LOCAL_BYTE_ARRAY_PTR,
    OPERAND_GLOBAL_BYTE_VARIABLE,
    OPERAND_GLOBAL_BYTE_ARRAY_VARIABLE,
    OPERAND_GLOBAL_BYTE_ARRAY_PTR,
    OPERAND_LOCAL_STRING_VARIABLE,
    OPERAND_LOCAL_STRING_ARRAY_VARIABLE,
    OPERAND_GLOBAL_STRING_VARIABLE,
    OPERAND_GLOBAL_STRING_ARRAY_VARIABLE,
    OPERAND_INTERN_FUNCTION,
    OPERAND_EXTERN_FUNCTION,
    OPERAND_UNDEFINED_FUNCTION,
    END
};

enum
{
    OPTIMIZER_HINT_NONE,                                                            // no optimizer hints
    OPTIMIZER_HINT_CONST_NO_OP,                                                     // postfix contains only const or string or string-var, but no operator
    OPTIMIZER_HINT_LOC_INT_NO_OP,                                                   // postfix contains only local int variable, but no operator
    OPTIMIZER_HINT_GLOB_INT_NO_OP,                                                  // postfix contains only global int variable, but no operator
    OPTIMIZER_HINT_LOC_BYTE_NO_OP,                                                  // postfix contains only local int variable, but no operator
    OPTIMIZER_HINT_GLOB_BYTE_NO_OP,                                                 // postfix contains only global int variable, but no operator
    OPTIMIZER_HINT_LOC_INT_LOC_INT_OP,                                              // postfix contains local-int-var op local-int-var
    OPTIMIZER_HINT_LOC_INT_CONST_INT_OP,                                            // postfix contains local-int-var op const
    OPTIMIZER_HINT_GLOB_INT_GLOB_INT_OP,                                            // postfix contains global-int-var op global-int-var
    OPTIMIZER_HINT_GLOB_INT_CONST_INT_OP,                                           // postfix contains global-int-var op const
    OPTIMIZER_HINT_INT_FUNC_NO_OP,                                                  // postfix contains only call of intern function, but no operator
    OPTIMIZER_HINT_EXT_FUNC_NO_OP,                                                  // postfix contains only call of extern function, but no operator
};

enum
{
    VARIABLE_TYPE_LOCAL_INT,
    VARIABLE_TYPE_LOCAL_INT_ARRAY,
    VARIABLE_TYPE_LOCAL_BYTE,
    VARIABLE_TYPE_LOCAL_BYTE_ARRAY,
    VARIABLE_TYPE_LOCAL_STRING,
    VARIABLE_TYPE_LOCAL_STRING_ARRAY,
    VARIABLE_TYPE_GLOBAL_INT,
    VARIABLE_TYPE_GLOBAL_INT_ARRAY,
    VARIABLE_TYPE_GLOBAL_BYTE,
    VARIABLE_TYPE_GLOBAL_BYTE_ARRAY,
    VARIABLE_TYPE_GLOBAL_STRING,
    VARIABLE_TYPE_GLOBAL_STRING_ARRAY,
};

enum
{
    FUNCTION_TYPE_VOID,
    FUNCTION_TYPE_INT,
    FUNCTION_TYPE_BYTE,
    FUNCTION_TYPE_STRING
};

enum
{
    ARGUMENT_TYPE_INT,
    ARGUMENT_TYPE_BYTE,
    ARGUMENT_TYPE_STRING
};


typedef struct
{
    int                     stack[MAX_EXPR_EXPRESSION_STACK_DEPTH];
    int                     type[MAX_EXPR_EXPRESSION_STACK_DEPTH];
    int                     postfix_slot[MAX_EXPR_EXPRESSION_STACK_DEPTH];
    int                     stack_pointer;
} EXPRESSION_STACK;

typedef struct
{
    unsigned int            type;
    int                     value;
    int                     postfix_slot;                // e.g. for index of an array
} POSTFIX_ELEMENT;

enum
{
    EXPRESSION_CONTENT_TYPE_INT_CONSTANT,
    EXPRESSION_CONTENT_TYPE_STRING_CONSTANT,
    EXPRESSION_CONTENT_TYPE_LOCAL_INT_VARIABLE,
    EXPRESSION_CONTENT_TYPE_LOCAL_INT_ARRAY_VARIABLE,
    EXPRESSION_CONTENT_TYPE_LOCAL_BYTE_VARIABLE,
    EXPRESSION_CONTENT_TYPE_LOCAL_BYTE_ARRAY_VARIABLE,
    EXPRESSION_CONTENT_TYPE_LOCAL_STRING_VARIABLE,
    EXPRESSION_CONTENT_TYPE_LOCAL_STRING_ARRAY_VARIABLE,
    EXPRESSION_CONTENT_TYPE_GLOBAL_INT_VARIABLE,
    EXPRESSION_CONTENT_TYPE_GLOBAL_INT_ARRAY_VARIABLE,
    EXPRESSION_CONTENT_TYPE_GLOBAL_BYTE_VARIABLE,
    EXPRESSION_CONTENT_TYPE_GLOBAL_BYTE_ARRAY_VARIABLE,
    EXPRESSION_CONTENT_TYPE_GLOBAL_STRING_VARIABLE,
    EXPRESSION_CONTENT_TYPE_GLOBAL_STRING_ARRAY_VARIABLE,
    EXPRESSION_CONTENT_TYPE_INTERN_FUNCTION,
    EXPRESSION_CONTENT_TYPE_EXTERN_FUNCTION,
    EXPRESSION_CONTENT_TYPE_UNDEFINED_FUNCTION,
};

typedef struct
{
    uint_fast8_t            type;                               // expression type
    uint_fast8_t            obr;                                // number of open brackets (preceding value)
    int                     value;                              // constant value, or index to variable, or index to function
    uint_fast8_t            cbr;                                // number of close brackets (following value, preceding operator)
    uint_fast8_t            op;                                 // operator following
    int                     fipslot;                            // interface to functions
} EXPRESSION_CONTENT;

typedef struct
{
    int                     func_idx;
    int                     argc;                               // argc
    int                     type;                               // return type TODO
    int                     reti;                               // filled at runtime: return value of function
    int *                   postfix_slotp;                      // arguments to function as a list of postfix slots
} FIP_RUN;

typedef struct
{
    EXPRESSION_CONTENT **   argvp;                              // arguments as expressions
} FIP_EXPR;

extern FIP_RUN **           fip_run_slots;
extern FIP_EXPR **          fip_expr_slots;
extern int                  fipslots_used;                      // commonly used for fip_run_slots & fip_expr_slots
extern int                  fipslots_allocated;

extern POSTFIX_ELEMENT **   postfix_slots;
extern int                  postfix_slots_used;
extern int                  postfix_slots_allocated;

typedef struct
{
    int                     postfix_slot1;
    int                     operator;
    int                     postfix_slot2;
    int                     false_idx;                          // statement idx if condition is false
} STATEMENT_IF;

typedef struct
{
    int                     postfix_slot1;
    int                     operator;
    int                     postfix_slot2;
    int                     endwhile_idx;                       // statement idx of endwhile statement
} STATEMENT_WHILE;

typedef struct
{
    int                     while_idx;                          // statement idx of while statement
} STATEMENT_ENDWHILE;

typedef struct
{
    int                     for_variable_idx;
    int                     for_variable_type;
    int                     postfix_slot_start;
    int                     postfix_slot_stop;
    int                     postfix_slot_step;
    int                     endfor_idx;                         // statement idx of endfor statement
} STATEMENT_FOR;

typedef struct
{
    int                     for_idx;                            // statement idx of for statement
    int                     stop_value;                         // runtime value
    int                     step_value;                         // runtime value
} STATEMENT_ENDFOR;

typedef struct
{
    int                     postfix_slot;
    int                     endrepeat_idx;                      // statement idx of endrepeat statement
} STATEMENT_REPEAT;

typedef struct
{
    int                     repeat_idx;                         // statement idx of repeat statement
    int                     value;                              // runtime value
} STATEMENT_ENDREPEAT;

typedef struct
{
    int                     endloop_idx;                        // statement idx of endloop statement
} STATEMENT_LOOP;

typedef struct
{
    int                     loop_idx;                           // statement idx of loop statement
} STATEMENT_ENDLOOP;

typedef struct
{
    int                     variable_idx;                       // variable index
    int                     variable_type;                      // variable type
    int                     step;                               // step
} STATEMENT_INCREMENT;

typedef struct
{
    int                     assignment_variable_idx;            // assignment variable index
    int                     assignment_variable_type;           // assignment variable type
    int                     assignment_variable_pslot;          // postfix slot to evaluate array index, if array variable
    int                     postfix_slot;
} STATEMENT_INTERN_FUNCTION;

typedef struct
{
    int                     assignment_variable_idx;            // assignment variable index
    int                     assignment_variable_type;           // assignment variable type
    int                     assignment_variable_pslot;          // postfix slot to evaluate array index, if array variable
    int                     postfix_slot;
} STATEMENT_EXTERN_FUNCTION;

typedef struct
{
    int                     postfix_slot;
} STATEMENT_RETURN;

enum
{
    STATEMENT_TYPE_IF,                                          // if
    STATEMENT_TYPE_ENDIF,                                       // endif
    STATEMENT_TYPE_WHILE,                                       // while
    STATEMENT_TYPE_ENDWHILE,                                    // endwhile
    STATEMENT_TYPE_FOR,                                         // for
    STATEMENT_TYPE_ENDFOR,                                      // endfor
    STATEMENT_TYPE_LOOP,                                        // loop
    STATEMENT_TYPE_ENDLOOP,                                     // endloop
    STATEMENT_TYPE_REPEAT,                                      // repeat
    STATEMENT_TYPE_ENDREPEAT,                                   // endrepeat
    STATEMENT_TYPE_BREAK,                                       // break
    STATEMENT_TYPE_CONTINUE,                                    // continue
    STATEMENT_TYPE_INCREMENT,                                   // increment
    STATEMENT_TYPE_INTERN_FUNCTION,                             // intern command
    STATEMENT_TYPE_RETURN,
    STATEMENT_TYPES,
};

typedef struct statement_st STATEMENT;

struct statement_st
{
    int                     line;                               // line number
    int                     type;                               // type of script line
    int                     next;                               // next line to execute

    union
    {
        STATEMENT_IF                st_if;
        STATEMENT_LOOP              st_loop;
        STATEMENT_ENDLOOP           st_endloop;
        STATEMENT_WHILE             st_while;
        STATEMENT_ENDWHILE          st_endwhile;
        STATEMENT_FOR               st_for;
        STATEMENT_ENDFOR            st_endfor;
        STATEMENT_REPEAT            st_repeat;
        STATEMENT_ENDREPEAT         st_endrepeat;
        STATEMENT_INCREMENT         st_increment;
        STATEMENT_INTERN_FUNCTION   st_intern_function;
        STATEMENT_EXTERN_FUNCTION   st_extern_function;
        STATEMENT_RETURN            st_return;
    } st;
};
