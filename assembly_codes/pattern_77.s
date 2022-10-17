
# pattern77.s

# Read only data
.section .rodata
     msg_char:
     .string "%c\t"

     msg_newline:
     .string "\n"

# Block started with symbol
.section .bss
      .comm      column ,4 ,4
      .comm      row    ,4 ,4

# Text section
.section .data
      .globl     asciiD
      .align     4
      .type      asciiD , @object
      .size      asciiD , 4
asciiD:
      .long      68
      .globl     ascii
      .align     4
      .type      ascii , @object
      .size      ascii , 4
ascii:
      .long      68
      .globl     space
      .align     4
      .type      space , @object
      .size      space , 4
space:
      .long      1

# section: text
.section    .text

# Entry point: _start
      .globl      _start
      .type       _start , @function
_start:
       #PROLOGUE
       pushl      %ebp
       movl       %esp , %ebp
       
       # Main code
       
       # 1. Initialization (outer loop)
       movl     $1 , column
  
       # 2. Terminating condition  (outer loop)
.loop:
       movl     column , %eax
       movl     $7     , %ebx
       cmpl     %ebx   , %eax
       jg       .epilogue
       
       #  3. Loop body (outer loop)

       #  Initialization (inner loop)
       movl     $1 , row
      
       #  Terminating condition (inner loop) 
.inner_loop:
       movl     row   , %eax
       movl     space , %ebx
       cmpl     %ebx  , %eax
       jg       .outer
       
       #  Loop body (inner loop)
       
       #  Printing message
       pushl     asciiD
       pushl     $msg_char
       call      printf
       addl      $8   , %esp
       
       # asciiD++
       movl      asciiD, %eax
       addl        $1 , %eax
       movl      %eax , asciiD

       #  incrementing steps (inner loop)
       #  row++
       movl      row  , %eax
       addl       $1  , %eax
       movl      %eax , row
       jmp      .inner_loop

.outer:
       # row=1
       movl      $1   , row
         
       movl      column,%eax
       movl      $3   , %ebx
       cmpl      %ebx , %eax
       jg        .true_block
       jmp       .false_block
    
.true_block:
       # ascii++
       movl      ascii, %eax
       addl       $1  , %eax
       movl      %eax , ascii

       # space--
       movl      space , %eax
       subl        $1 , %eax
       movl      %eax , space
       jmp       .out

.false_block:
       # ascii--
       movl      ascii, %eax
       subl       $1  , %eax
       movl      %eax , ascii

       # space++
       movl       space , %eax
       addl        $1 , %eax
       movl      %eax , space
       jmp       .out

.out:
       # asciiD=ascii
       movl      ascii , %eax
       movl      %eax , asciiD

       # Printing message
       pushl     $msg_newline
       call      printf
       addl      $8   , %esp
     
       # 4. incrementing condition (outer loop)
       # column++
       movl      column , %eax
       addl       $1   , %eax
       movl      %eax   , column
       jmp       .loop

.epilogue:
       pushl     $0
       call      exit
