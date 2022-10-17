
# pattern_05.s

# Read only memory
.section .rodata
         msg_symbol:
                     .string "*\t"
 
         msg_newline:
                     .string "\n"

         msg_space:
                     .string "\t"


# Block started with symbol 
.section  .bss
         .comm    column , 4, 4
         .comm    row    , 4, 4

    
# Data Section
.section .data 
         .globl   space
         .align   4
         .type    space , @object
         .size    space , 4
space:
         .long    7

        
# Text Section
.section    .text

# Entry point : _start
         .globl      _start
         .type       _start , @function

_start:
         #PROLOGUE
         pushl     %ebp
         movl      %esp , %ebp

         # Main Code
         # 1. Initialization   (outer loop)
         movl      $1   , column

         # 2. Terminating condition  (outer loop)
.loop:
         movl      column, %eax
         cmpl      $7  , %eax
         jg        .epilogue

         # 3. Loop body  (outer loop)    
         
         # Initialization (inner loop)
         movl      $1    , row

         # Terminating condition (inner loop)
.inner_loop:
    
         # loop body  (inner loop)
         movl      row   , %eax
         cmpl      $4  , %eax
         jg        .outer

         movl      row  , %eax
         movl      column , %ebx
         cmpl      %ebx , %eax
         jg        .space

         movl      row , %eax
         movl      space , %ebx
         cmpl      %ebx , %eax
         jg        .space

        
         # printing message
         pushl     $msg_symbol
         call      printf
         addl      $8    , %esp
         jmp       .out

.space:
         # printing messagr
         pushl     $msg_space
         call      printf
         addl      $8  , %esp
         jmp       .out    

.out:         
         # Incrementing steps (inner loop)
         # row++
         incl       row
         jmp       .inner_loop

.outer:
         # row=1
         movl      $1    , row
      
         # space--
         decl     space

.continue:
         # Message printing
         pushl     $msg_newline
         call      printf
         addl      $8    , %esp

         # 4. Incrementing steps (outer loop)
         #column++
         incl      column
         jmp       .loop

.epilogue:         
         pushl     $0
         call      exit

