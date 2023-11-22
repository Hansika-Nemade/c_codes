

void pattern1(void)
{
   int ole = 1, ile = 1;

    //   terminating condition
    for(ole = 1 ; ole <= 5 ; ole++)
    {
      for(ile = 1 ; ile <= 5 ; ile++)
      {
        printf("*   ");         // 3 spaces
      }

      ile = 1;
      printf("\n");
    }  

    return;
}

void pattern2(void)
{

    int ole = 1, ile = 1;
    int asciiA = 65;

    for(ole =1; ole <= 5 ; ole++)
    {
        for(ile =1 ; ile <= 5 ; ile++)
        {
           printf("%c   ",asciiA);     // 3 spaces
        }

        ile=1;
        asciiA++;            
        printf("\n");
    }

    return;
}

void pattern3(void)
{
    int ole = 1, ile = 1;

    int num1 = 5;

    for(ole = 1 ; ole <= 5 ; ole++)
    {
      for(ile = 1 ; ile <= 5 ; ile++)
      {
        printf("%d   ",num1);          // 3 spaces
        num1--;
      }

      ile = 1;
      num1 = 5;
      printf("\n");
    }

    return;
}

void pattern4(void)
{
    int ole = 1, ile = 1;
    int ascii_E = 69;

    for(ole = 1 ; ole <= 5 ; ole++) 
    {
       for(ile = 1 ; ile<=5 ; ile++)
       {
          printf("%c   ",ascii_E);   // 3 spaces
       }

       ile = 1;
       ascii_E--;
      printf("\n");
    }

    return;
}

void pattern5(void)
{
    
}

void pattern6(void)
{
  int ole = 1, ile = 1;

  //   terminating condition
  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("*   ");         // 3 spaces
      
    } 
    ile = 1;
    printf("\n");
  }

  return;
}

void pattern7(void)
{
  int ole = 1, ile = 1;
  int num1 = 1;

  //   terminating condition
  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("%d   ",num1);              // 3 spaces
      
      num1++;
      
    }
    num1 = 1;
    ile = 1;
    printf("\n");
  }

  return;
}

void pattern8(void)
{
  int ascii_A = 65;
  int ole = 1, ile = 1;

  //   terminating condition
  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("%c   ",ascii_A);        // 3 spaces

    }

    ile = 1;
    ascii_A++;
    printf("\n");
  }

  return;
}


void pattern9(void)
{
  int ole = 1, ile = 1;
  int ascii_A = 65;
  
  //   terminating condition
  for(ole = 5 ; ole <= 5 && ole > 0 ; ole--)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("%c   ",ascii_A);            // 3 spaces
      else
        printf("   ");                   // 4 spaces
    } 
    ile = 1;
    ascii_A++;
    printf("\n");
  }

  return;
}

void pattern10(void)
{
  int ole = 0, ile = 1;
  int num1 = 5;

  for(ole = 5 ; ole <= 5 && ole > 0; ole--)
  { 

    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
      {
        printf("%d   ",num1);           // 3 spaces
        num1--; 
      }
      else
      {
        printf("    ");             // 4 spaces
      }
      
    }
    printf("end");
    ile = 1;
    num1 = 5;
    printf("\n");

  }

  return;
}

void pattern11(void)
{
  int ole = 1, ile = 1;
  int space = 7;

  for(ole = 1 ; ole <= 7 ; ole++)
  {

    for(ile = 1  ; ile <= 4 ; ile++)
    {
      if(ile <= ole && ile <= space)
      {
        printf("*   ");                   // 3 spaces
      } 
      else
      {
        printf("    ");                   // 4 spaces
      }
      
    }
    printf("end");
    ile = 1;
    space--;
    
    
    printf("\n");
  }

  return;
}

void pattern12(void)
{
  int ole = 1, ile = 1;
  int ascii_D=68;
  int space=68;
  int sub_row=1;

  //   terminating condition
  while(ole <= 7)
  {
    while(ile<=sub_row)
    {
      printf("%c   ",ascii_D);
      ascii_D++;
      ile++;
    }

    ile = 1;

    if(ole > 3)
    {
      space++;
      sub_row--;
    }
    else
    {
      space--;
      sub_row++;
    }

    ascii_D = space;
    ole++;          //incrementing condition
    printf("\n");
  }

  return;
}

void pattern13(void)
{
   int ole=1,ile=1;
    int num1=1,sub_row=1;

  //  terminating condition
  while(ole<=9)
  {
    while(ile<=sub_row)
    {
        printf("%d   ",num1);
        if((ole % 2) == 0)
          num1--;
        else
          num1++;
          
        ile++;
    }
    ile=1;

    if(ole>4)
    {
      sub_row--;
    }
    else
    {
      sub_row++;
    }

    if((ole % 2) != 0)
       num1 = sub_row;
    else
       num1=1;


    ole++;   //incrementing condotion
    printf("\n");
  }

  return;
}

void pattern14(void)
{
  int ole = 1, ile = 1, space = 3;
  int asciiD = 68, ascii = 68;

  //    terminating condition
  while(ole <= 7)
  {
    while(ile <= 4)
    {
      if(ile <= space)
      {
        printf("    ");                     // 4 spaces
      }
      else
      {
        printf("%c   ",asciiD);              // 3 spaces
        asciiD++;
      }
      ile++;
    }

    ile = 1;

    if(ole > 3)
    {
      space++;
      ascii++;
    }
    else
    {
      space--;
      ascii--;
    }

    asciiD = ascii;
    ole++;      //incrementing condition
    printf("\n");
  }

  return;
}

void pattern15(void)
{
  int ole = 1, ile = 1;
  int num1 = 3, num = 3, space = 3;
           
  //   terminating condition
  while(ole <= 7)
  {
    while(ile <= 4)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("%d   ",num1);
        num1++;
      }
      ile++;
    }

    ile = 1;

    if(ole > 3)
    {
      space++;
      num++;
    }
    else
    {
      space--;
      num--;
    }

    num1 = num;
    ole++;         //incrementing condition
    printf("\n");

  }

  return;
}

void pattern16(void)
{
  int ole = 1, ile = 1;

  //   terminating condition
  for(ole = 5 ; ole <= 5 && ole > 0 ; ole--)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile >= ole)
      {
        printf("*   ");   // 3 space
      }
      else
      {
        printf("    ");   // 4 space
      }
      
    }
    ile = 1;
    printf("\n");
  }

  return;
}

void pattern17(void)
{
  int ile = 1;

  //   terminating condition
  for(int ole = 1 ; ole <= 5  ; ole++)
  {
    for(int ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile >= ole)
        printf("*   ");   // 3 spaces
      else
        printf("    ");   // 4 spaces
      
    }
    ile = 1;
    printf("\n");
  }

  return;
}

void pattern18(void)
{
  int ole = 0, ile = 1;
  int num1 = 1;

  //   terminating condition
  for(ole = 5 ; ole <= 5 && ole > 0 ; ole--)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile >= ole)
        printf("%d   ", num1);  // 3 spaces
      else
        printf("    ");   // 4 spaces

    }
    ile = 1;
    num1++;
    printf("\n");
  }

  return;
}

void pattern19(void)
{
  int ile = 1;
  int num1 = 1;

  //   terminating condition
  for(int ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile >= ole)
      {
        printf("%d   ", num1);  // 3 spaces
        num1++;
      }
      else
      {
        printf("    ");    // 4 spaces
      }
    }
    num1 = 1;
    ile = 1;
    
    printf("\n");
  }

  return;
}

void pattern20(void)
{

  int ole = 1, ile = 1, space = 1;
  int  ascii_D = 68;

  for(ole = 1 ; ole <= 7 ; ole++)
  {
    for(ile = 1 ; ile <= 4 ; ile++)
    {
      if(ile <= space)
      {
        printf("%c   ", ascii_D);  // 3 spaces
        ascii_D--;   
      }
      else
      {
        printf("    ");   // 4 spaces
      }
      
    }

    ile = 1;
    if(ole > 3)
    {
        space--;
    }
    else
    {
       space++;
    }
    ascii_D = 68; 
     
    printf("\n");

  } 

  return;
}

void pattern21(void)
{
  int ole = 1, ile = 1;
  int space = 4, i = 5;

  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= i ; ile++)
    {
      if(ile <= space)
      {
        printf("    ");    // 4 spaces
      }
      else
      {
        printf("*   ");   // 3 spaces
      }
    }

    ile = 1;
    space--;
    i++;

    printf("\n");
  }

  return;
}

void pattern22(void)
{
  int ole = 1, ile = 1;
  int ascii_A = 65, asciiA = 65, asciiB = 66;
  int space = 4, sub_col = 5;

  for(ole = 1 ; ole <= 5; ole++)
  {
    for(ile = 1 ; ile <= sub_col ; ile++)
    {
      if(ile <= space)
      {
        printf("    ");       //4 spaces
      }
      else   
      {
        if(ascii_A < 65)
        {
          printf("%c   ",asciiB);      //3 spaces
          asciiB++;
        }
        else
        {
          printf("%c   ",ascii_A);     //3 spaces
          ascii_A--; 
        }
      }
    }
    ile = 1;

    asciiB = 66;
    asciiA++;

    ascii_A = asciiA;
    space--;
    sub_col++;
    printf("\n");
  }

  return;
}

void pattern23(void)
{
  int ole = 1, ile = 1;
  int asciiA = 64, space = 4, i = 5;

  //   terminating condition
  while(ole <= 5)
  {
    while(ile <= i)
    {
      if(ile <= space)
      {
        printf("    ");     // 4 spaces
      }
      else
      {
        if(ile > 5)
        {
          asciiA--;
          printf("%c   ",asciiA);
        }
        else
        {
          asciiA++;
          printf("%c   ",asciiA); 
        }
      }
      ile++;
    }

    asciiA = 64;
    ile = 1;
    space--;
    i++;
    ole++;       //incrementing condition
    printf("\n");
  }

  return;
}

void pattern24(void)
{
  int ole = 1, ile = 1;
  int asciiA = 65, ascii = 65, space = 4, i = 5;

  while(ole <= 5)
  {
    while(ile <= i)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("%c   ",asciiA);
        asciiA--;
      }
      ile++;
    }

    ascii = ascii+2;
    asciiA = ascii; 

    ile = 1;

    space--; 

    i++;
    ole++;       //incrementing condition
    printf("\n");
  }

  return;
}

void pattern25(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 4, i = 5;

  while(ole <= 5)
  {
    while(ile <= i)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("%d   ",num1);
      }
      ile++;
    }

    ile = 1;
    num1 = num1 + 2;

    space--;
    i++;
    ole++; 

    printf("\n");
  }

  return;
}

void pattern26(void)
{
  int ole = 1, ile = 1, space = 0, space2 = 9;

  //   terminating condition
  while(ole <= 5)
  {
    while(ile <= space2)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("*   ");
      }

      ile++;
    }

    ile = 1;
    space++;
    space2--;
    ole++;

    printf("\n");
  }

  return;
}

void pattern27(void)
{
  int ole = 1, ile = 1;
  int ascii_A = 65, space = 9, i = 0;

  //    terminating condition
  while(ole <= 5)
  {
    while(ile <= space)
    {
      if(ile <= i)
      {
        printf("    ");
      }
      else
      {
        printf("%c   ",ascii_A);
        ascii_A++;
      }
      ile++;
    }

    ile = 1;

    space--;
    i++;

    ascii_A = 65;
    ole++;            //incrementing condition

    printf("\n");
  }

  return;
}

void pattern28(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 9, i = 0;

  while(ole <= 5)
  {
    while(ile <= space)
    {
      if(ile <= i)
      {
        printf("    ");
      }
      else
      {
        printf("%d   ",num1);
        num1++;
      }
      ile++;
    }

    ile = 1;
    space--;
    i++;

    num1 = 1;
    ole++;  

    printf("\n");
  }

  return;
}

void pattern29(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, space = 0, i = 9;

  while(ole <= 5)
  {
    while(ile <= i)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("%c   ",asciiE);
      }
      ile++;
    }

    ile = 1;

    asciiE--;
    space++;
    i--;

    ole++;  
    printf("\n");
  }

  return;
}

void pattern30(void)
{
  int ole = 1, ile = 1; 
  int asciiI = 73, space = 0, i = 9;
  
  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile <= space || ile > i)
      {
        printf("    ");
      }
      else
      {
        printf("%c   ",asciiI);
      }
      ile++;
    }

    ile = 1;
    asciiI = asciiI - 2;
    space++;

    i--;
    ole++;     

    printf("\n");
  }

  return;
}

void pattern31(void)
{
  int ole = 1, ile = 1;
  int space = 1, space2 = 9;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("*   ");
      }
      else
      {
        printf("    ");
      }

      ile++;
    }

    ile = 1;
    space2--;
    space++;

    ole++;
    printf("\n");
  }

  return;
}

void pattern32(void)
{
  int ole = 1, ile = 1;
  int space = 4, space2 = 5;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else if(ile == (space + 1) || ile == space2)
      {
        printf("*   ");
      }
      else
      {
        printf("    ");
      }
      ile++;
    }

    ile = 1;

    space2++;
    space--;

    ole++;
    printf("\n");
  }

  return;
}

void pattern33(void)
{
  int ole = 1, ile = 1;
  int num1 = 5, space = 1, space2 = 9;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%d   ",num1);
      }
      else
      {
        printf("    ");
      }
      ile++;
    }

    ile = 1;

    num1--;
    space2--;
    space++;

    ole++;
    printf("\n");
  }

  return;
}

void pattern34(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, space = 1, space2 = 9;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%c   ",asciiE);
      }
      else
      {
        printf("    ");
      }
      ile++;
    }
    ile = 1;

    asciiE--;
    space2--;
    space++;

    ole++;
    printf("\n");
  }

  return;
}

void pattern35(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 5, space2 = 5;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%d   ",num1);
      }
      else
      {
        printf("    ");
      }
      ile++;
    }

    ile = 1;

    space2++;
    num1++;
    space--;

    ole++;      
    printf("\n");
  }

  return;
}

void pattern36(void)
{
  int ole = 1, ile = 1;
  int asciiA = 65, space = 5, space2 = 5;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%c   ",asciiA);
      }
      else
      {
        printf("    ");
      }
      ile++;
    }
    ile = 1;

    space2++;
    asciiA++;
    space--;

    ole++;       
    printf("\n");
  }

  return;
}

void pattern37(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 4;

  while(ole <= 5)
  {
    while(ile <= 5)
    {
      if(ile <= space)
      {
        printf("    ");       // 4 spaces
      }
      else
      {
        printf("%d      ",num1);         // 6 spaces
      }

      ile++;
    }
    ile = 1;

    num1++;
    space--;

    ole++;     
    printf("\n");
  }

  return;
}

void pattern38(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 4;

  while(ole <= 5)
  {
    while(ile <= 5)
    {
      if(ile <= space)
      {
        printf("    ");         // 4 spaces
      }
      else
      {
        printf("%d      ",num1);      // 6 spaces
        num1++;
      }

      ile++;
    }

    ile = 1;
    num1 = 1;

    space--;
    ole++; 

    printf("\n");
  }

  return;
}

void pattern39(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, ascii = 69, space = 0;

  while(ole <= 5)
  {
    while(ile <= 5)
    {
      if(ile <= space)
      {
        printf("    ");         // 4spaces
      }
      else
      {
        printf("%c      ",asciiE);       // 6 spaces
        asciiE--;
      }

      ile++;
    }

    ascii--;
    asciiE = ascii;
    ile = 1;

    space++;

    ole++; 
    printf("\n");
  }

  return;
}

void pattern40(void)
{
  int ole = 1, ile = 1;
  int num1 = 5, space = 0;

  while(ole <= 5)
  {
    while(ile <= 5)
    {
      if(ile <= space)
      {
        printf("    ");                 // 4 spaces
      }
      else
      {
        printf("%d      ",num1);        // 6 spaces
      }

      ile++;
    }

    num1--;
    ile = 1;

    space++;

    ole++;  
    printf("\n");
  }

  return;
}

void pattern41(void)
{
  int ole = 1, ile = 1;
  int space = 5, space2 = 5;

  while(ole <= 9)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("*   ");               // 3 spaces
      }
      else
      {
        printf("    ");              // 4 spaces
      }

      ile++;

    }

    ile = 1;
    if(ole>4)
    {
      space++;
      space2--;
    }
    else
    {
      space--;
      space2++;
    }

    ole++;
    printf("\n");
  }

  return;
}

void pattern42(void)
{
  int ole = 1, ile = 1;
  int num1 = 5, space = 5, space2 = 5;

  while(ole <= 9)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%d   ",num1);
      }
      else
      {
        printf("    ");
      }
      ile++;
    }

    ile = 1;
    if(ole>4)
    {
      space++;
      num1++;
      space2--;
    }
    else
    {
      space--;
      num1--;
      space2++;
    } 

    ole++;  
    printf("\n");
  }

  return;
}

void pattern43(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, space = 5, space2 = 5;

  while(ole <= 9)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%c   ",asciiE);       // 3 spaces
      }
      else
      {
        printf("    ");        // 4 spaces
      }
      ile++;
    }

    ile = 1;
    if(ole>4)
    {
      space++;
      asciiE++;
      space2--;
    }
    else
    {
      space--;
      asciiE--;
      space2++;
    }

    ole++;    
    printf("\n");
  }

  return;
}

void pattern44(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 5, space2 = 5;

  while(ole <= 9)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%d   ",num1);      // 3 spaces
      }
      else
      {
        printf("    ");             // 4 spaces
      }
      ile++;
    }

    ile = 1;
    if(ole>4)
    {
      space++;
      num1--;
      space2--;
    }
    else
    {
      space--;
      num1++;
      space2++;
    }

    ole++;     
    printf("\n");
  }

  return;
}

void pattern45(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, num = 1, space = 3;

  while(ole <= 7)
  {
    while(ile <= 4)
    {
      if(ile <= space)
      {
        printf("    ");                      // 4 spaces
      }
      else
      {
        printf("%d      ",num1);            // 6 spaces
        num1++;
      }

      ile++;

    }

    ile = 1;
    if(ole>3)
    {
      space++;
      num++;
      num1=num;
    }
    else
    {
      space--;
      num1=1;
    }

    ole++;
    printf("\n");
  }

  return;
}

void pattern46(void)
{
  int ole = 1, ile = 1;
  int space = 6, space2 = 8;

  //   terminating condition
  while(ole <= 7)
  {
    while(ile <= 13)
    {
      if(ile <= space && ile >= space2)
      {
        printf("    ");
      }
      else
      {
        printf("*   ");
      }
      ile++;
    }

    ile = 1;
    space2--;
    space++;
    ole++;
    printf("\n");
  }
}

void pattern47(void)
{
  int ole = 1, ile = 1;
  int space = 2, space2 = 12;

  //   terminating condition
  while(ole <= 7)
  {
    while(ile <= 13)
    {
      if(ile >= space && ile <= space2)
      {
        printf("    ");
      }
      else
      {
        printf("*   ");
      }

      ile++;
    }

    ile = 1;
    space2--;
    space++;

    ole++;
    printf("\n");
  }

  return;
}

void pattern48(void)
{
  int ole=1,ile=1;
  int ascii = 65;
  int space1 = 2, space2 = 6;

  while(ole<=7)
  {
    while(ile<=13)
    {
      if(ile >= space1 && ile <= space2)
        printf("    ");
      else 
        printf("%c   ", ascii);
      
      if(ile > 6)
        ascii--;
      else
        ascii++;
      
      ile++;
    }

    ascii = 65;
    ile=1;

    space1++;
    space2++;

    ole++;
    printf("\n");
  }

  return;
}

void pattern49(void)
{
  int ole=1,ile=1;
  int ascii = 65;
  int space1 = 8, space2 = 12;

  while(ole<=7)
  {
    while(ile<=13)
    {
        if(ile >= space1 && ile <= space2)
           printf("    ");
        else 
           printf("%c   ", ascii);
      
        if(ile > 6)
          ascii--;
        else
          ascii++;
      
        ile++;
    }

    ascii = 65;
    ile=1;

    space1--;
    space2--;

    ole++;
    printf("\n");
  }

  return;
}

void pattern50(void)
{
  int ole = 1, ile = 1;
   int ascii = 65;
   int space1 = 2, space2 = 6;

  while(ole <= 13)
  {
    while(ile <= 13)
    {
        if(ile >= space1 && ile <= space2)
           printf("    ");
        else 
           printf("%c   ", ascii);
      
        if(ile > 6)
          ascii--;
        else
          ascii++;
      
        ile++;
    }

    ascii = 65;
    ile = 1;

    if(ole >= 7)
    {
       space1--;
       space2--;
    }
    else
    {
       space1++;
       space2++;
    }

    ole++;
    printf("\n");
  }

}
