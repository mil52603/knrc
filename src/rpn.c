#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> // for atof
#include <string.h>

#define MAXOP 100    // max size of operand or operator
#define NUMBER '0'   // signal that a number was found
#define ALPHA_OP 'a' // signal that an alphabetic operator was found

int getop(char[]);
void push(double);
double pop(void);
int size(void);

// reverse Polish calculator
int main(void)
{
  int type;
  double x, y;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      y = pop();
      push(pop() - y);
      break;
    case '/':
      y = pop();
      if (y != 0.0)
      {
        push(pop() / y);
      }
      else
      {
        printf("error: zero divisor\n");
      }
      break;
    // Exercise 4-3. (part 1) page 79
    case '%':
      y = pop();
      if (y != 0.0)
      {
        x = pop();
        push((int)x % (int)y);
      }
      else
      {
        printf("error: zero divisor for modulus\n");
      }
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    case ALPHA_OP:
      // Exercise 4-4. page 79
      if (strcmp(s, "show") == 0) // print the top element
      {
        x = pop();
        printf("\t%.8g\n", x);
        push(x);
        break;
      }
      if (strcmp(s, "dup") == 0) // duplicate the top element
      {
        x = pop();
        push(x);
        push(x);
        break;
      }
      if (strcmp(s, "swap") == 0) // swap the top two elements
      {
        y = pop();
        x = pop();
        push(y);
        push(x);
        break;
      }
      if (strcmp(s, "clr") == 0) // clear the stack
      {
        while (size() > 0)
        {
          pop();
        }
        break;
      }
      // Exercise 4-5. page 79
      if (strcmp(s, "sin") == 0)
      {
        push(sin(pop()));
        break;
      }
      if (strcmp(s, "exp") == 0)
      {
        push(exp(pop()));
        break;
      }
      if (strcmp(s, "pow") == 0)
      {
        y = pop();
        push(pow(pop(), y));
        break;
      }
      // fallthrough if none of the strcmp's find a match
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100 // maximum depth of val stack

static int sp = 0;         // next free stack position
static double val[MAXVAL]; // value stack

// push: push f onto value stack
void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("error: stack full, can't push %g\n", f);
  }
}

// pop: pop and return top value from stack
double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int size(void)
{
  return sp;
}

int getch(void);
void ungetch(int);

// getop: get next operator or numeric operand
int getop(char s[])
{
  int c;
  while ((s[0] = (char)(c = getch())) == ' ' || c == '\t')
  {
  }
  s[1] = '\0';
  int i = 0;
  // Exercise 4-3. (part 2) page 79
  if (c == '-')
  {
    // after reading a '-', peek at the next character
    // if it isn't a digit, return the '-' as an op
    // otherwise continue reading the number
    ungetch(c = getch());
    if (!isdigit(c))
    {
      return '-';
    }
  }
  else if (isalpha(c))
  {
    // read the other alpha characters
    while (isalpha(s[++i] = (char)(c = getch())))
    {
    }
    s[i] = '\0';
    ungetch(c);
    return ALPHA_OP;
  }
  else if (!isdigit(c) && c != '.')
  {
    return c; // single character operator
  }
  if (isdigit(c)) // collect integer part
  {
    while (isdigit(s[++i] = (char)(c = getch())))
    {
    }
  }
  if (c == '.') // collect fraction part
  {
    while (isdigit(s[++i] = (char)(c = getch())))
    {
    }
  }
  s[i] = '\0';
  if (c != EOF)
  {
    ungetch(c);
  }
  return NUMBER;
}

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

// get a (possibly pushed back) character
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = (char)c;
  }
}
