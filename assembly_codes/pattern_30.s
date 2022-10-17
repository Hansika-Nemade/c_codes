
# Pattern30.s

# section: Read only data
.section   .rodata
     msg_char:
     .string "%c\t"

     msg_space:
     .string "\t"

     msg_newline:
     .string "\n"

# section: Block started with symbol
.section   .bss
     .comm    column, 4, 4
     .comm    row   , 4, 4

# section: data
.section   .data
     .globl    asciiE
     .align    4
     .type     asciiE , @object
     .size     asciiE , 4
asciiE:
     .long     69
     .globl    space
     .align    4
     .type     space , @object
     .size     space , 4
space:
     .zero     4

# section: Text
.section    .text
     
# Entry point: _start
      .globl   _start
      .type    _start , @function
_start:
      
      # PROLOGUE
      pushl    %ebp
      movl     %esp , %ebp

      # 1. Initialization       (outer loop)
      movl      $1  , column

      # 2. Terminating steps       (outer loop)
.loop:
      movl      column, %eax
      movl      $5    , %ebx
      cmpl      %ebx  , %eax
      jg        .epilogue

      # 3. Loop body      (outer loop)

      # Initialization       (inner loop)
      movl     $1  , row
      
      # Terminating condition    (inner loop)
.inner_loop:
      movl     row  , %eax
      movl     $5   , %ebx
      cmpl     %ebx , %eax
      jg       .outer

      # Loop   body       (inner loop)
      
      movl    row  , %eax
      movl    space, %ebx
      cmpl    %ebx , %eax
      jg      .false_block
      jmp     .true_block

.true_block:
      # message printing
      pushl   $msg_space
      call    printf
      addl    $8  , %esp
      jmp     .out

.false_block:
      # message printing
      pushl   asciiE
      pushl   $msg_char
      call    printf
      addl    $8   , %esp
      jmp     .out

.out:
      # Incrementing steps        (inner loop)
      # row++
      movl    row , %eax
      addl    $1  , %eax
      movl    %eax, row
      jmp     .inner_loop

.outer:
      # row=1
      movl    $1 , row

      # space++
      movl    space , %eax
      addl    $1    , %eax
      movl    %eax  , space

      # asciiE--
      movl    asciiE , %eax
      subl    $1     , %eax
      movl    %eax   , asciiE

      # Printing message
      pushl   $msg_newline
      call    printf
      addl    $8    , %esp
   
      # 4.   Incrementing steps     (outer loop)
      # column++
      movl    column , %eax
      addl    $1     , %eax
      movl    %eax   , column
      jmp     .loop

.epilogue:
      pushl   $0
      call    exit

