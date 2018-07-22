/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x|~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {

  return (x>>(n<<3))&0xFF;

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {

  //return (~((((1<<n)-1)<<(31-n))<<1))&(x>>n);
  //~((~(1<<n)<<(32+~n))<<1);
  return (~((~(1<<n)<<(32+~n))<<1))&(x>>n);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int mask=(((((0x01<<8)+0x01)<<8)+0x01)<<8)+0x01;
  //printf("%.x\n",mask);
  int tmp=(x&mask)+(x>>1&mask)+(x>>2&mask)+(x>>3&mask)+(x>>4&mask)+(x>>5&mask)+(x>>6&mask)+(x>>7&mask);
 // printf("%.x\n",tmp);
  int z=(tmp&0xFF)+(tmp>>8&0xFF)+(tmp>>16&0xFF)+(tmp>>24&0xFF);
  return z;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  //return !x;
  //0的逆元还是0，
  return !((((~x+1)>>31)&0x01)|((x>>31)&0x01));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  
  return (1<<31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {

  //return !((x>>(n+(~1+1)))&(x>>(n+(~1+1))));
  /*
  int z=x>>(n-1);
  return (!z|(!(z+1)));
  */
  //return !(((x>>(n-1)+((x>>31)&0x01))));
  //return !(((x>>(n+(~1+1)))+1)&(x>>(n+(~1+1))));
  int shiftNumber= 32 + (~n + 1);// 32 - n
  return !(x^((x<<shiftNumber)>>shiftNumber));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {

    int zero=x>>31&0x01;
    return (x+(zero<<n)+~zero+1)>>n;//bias
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !(((x>>31)&0x01)|!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int z=x-y;
  int xleading=x>>31&0x01;
  int yleading=y>>31&0x01;
  int zleading=z>>31&0x01;
  return (((!xleading)&(!yleading)&(zleading))|(xleading&(!yleading))|(xleading&yleading&zleading))|!z;
  //return !(((!xleading)&((!zleading)|yleading))|(xleading&yleading&(!zleading)));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {

  int i=32;
  for(i=31;i>=0;i--)
  {
    if(x&0x8000000000)
      break;
    x=(x<<1);
  }
  return i;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  if((uf&~(0x80000000))>0x7f800000)
  {
    //printf("err%8.x",uf&~0x);
      return uf;
  }
    else
      return uf^0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int xsign=(x>>31)&0x01;
  //printf("%.8x\n",xsign);
  int z=x;
  xsign&&(z=~x+1);
  //  printf("%.8x\n",z);

  int M;
  int k;
  
  if(!z)
    return 0;
  else
  {
    int i=0;
    int j=z;
    int round=0;

    if(j&0xff000000)
      round=1;


    for(i=0;i<=32;i++)
    {
      if(j&0x80000000)
        break;
      j=j<<1;
    }
    if(round)
    {
      int roundmask=0xff;
      if((j&roundmask)==0x80)
      {
        if(j&0x100)
          j=j+0x100;
      }
      else
      {
        if((j&roundmask)>0x80)
          j=j+0x100;
      }
      if(!(j&~(0xff)))
        i=i-1;

    }

    int k=127+31-i;
 //   printf("%.8x\n",k);
    k=k<<23;
  //  printf("%.8x\n", k|(xsign<<31));
    M=(j>>8)&(~(0xff800000));
    return (M|k|(xsign<<31));
  }




  return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  if((uf&~(0x80000000))>0x7f800000)
  {
    //printf("err%8.x",uf&~0x);
      return uf;
  }

  int kmask=0x7f800000;
  int mmask=0x007fffff;
  int M=uf&mmask;
  int k=uf&kmask;
  int s=uf&0x80000000;
 // printf("%.8x\n",M);
 // printf("%.8x\n",k);
 // printf("%.8x\n",s);
  if(!k)
  {
    
    M=M<<1;

    if(uf&0x00400000)
      k=0x00800000;
    return s|(M&mmask)|k;
  }
  else
  {

    if(k<0x7f800000)
      k+=0x00800000;
    //printf("%.8x\n",k);
    if(k==0x7f800000)
      return s|k;
    
    return s|(M&mmask)|k;
  }


}
#if 0
int main()
{
  
  printf("%.8x\n",ilog2(0x01));

}
#endif

