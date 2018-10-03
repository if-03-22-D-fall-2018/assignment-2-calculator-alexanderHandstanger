/*----------------------------------------------------------
 *				HTBLA-Leonding / 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 2
 * Title:			Calculator
 * Author:			Alexander Handstanger
 * ----------------------------------------------------------
 * Description:
 * The goal of this assignment is to make you familiar with
 * primitive data types and functions in C. We do this by
 * implementing a very primitive and text based calculator
 * which asks for an operation and one or two operand(s).
 * The operation is then applied to the operand(s) and the
 * result is finally printed.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <float.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
  printf("Simple Calculator\n");
  printf("Choose one of the following operations:\n");
  printf("  Add (1)\n");
  printf("  Subtract (2)\n");
  printf("  Multiply (3)\n");
  printf("  Divide (4)\n");
  printf("  Stop program (-1)\n");
  double firstOperand;
  double secondOperand;
  double result;
  int userChoice = 0;
  bool alreadyOverflow = false;
  while(userChoice != -1){
    alreadyOverflow = false;
    printf("Enter your choice: \n");
    scanf("%d", &userChoice);
    switch (userChoice) {
      case 1:
      printf("Please enter the first operand: ");
      scanf("%lf", &firstOperand);
      printf("\n");
      printf("Please enter the second operand: ");
      scanf("%lf", &secondOperand);
      printf("\n");

      if (firstOperand < secondOperand) {
        if((DBL_MAX - secondOperand) < firstOperand){
          printf("Number overflow\n");
          alreadyOverflow = true;
        }
      }
      else if(secondOperand < firstOperand){
        if((DBL_MAX - firstOperand) < secondOperand){
          printf("Number overflow\n");
          alreadyOverflow = true;
        }
      }

      if(alreadyOverflow == false){
        result = firstOperand + secondOperand;
        printf("%.2lf\n", result);
        printf("\n");
      }
      break;
      case 2:
      printf("Please enter the first operand: ");
      scanf("%lf", &firstOperand);
      printf("\n");
      printf("Please enter the second operand: ");
      scanf("%lf", &secondOperand);
      printf("\n");

      if(alreadyOverflow == false){
        result = firstOperand - secondOperand;
        printf("%.2lf\n", result);
        printf("\n");
      }
      break;
      case 3:
      printf("Please enter the first operand: ");
      scanf("%lf", &firstOperand);
      printf("\n");
      printf("Please enter the second operand: ");
      scanf("%lf", &secondOperand);
      printf("\n");

      if(alreadyOverflow == false){
        result = firstOperand * secondOperand;
        printf("%.2lf\n", result);
        printf("\n");
      }
      break;
      case 4:
      printf("Please enter the first operand: ");
      scanf("%lf", &firstOperand);
      printf("\n");
      while(true){
        printf("Please enter the second operand: ");
        scanf("%lf", &secondOperand);
        printf("\n");
        if(secondOperand != 0){
          break;
        }
        if(secondOperand == 0){
          printf("Division by zero\n");
        }
      }
      if(alreadyOverflow == false){
        result = firstOperand / secondOperand;
        printf("%.2lf\n", result);
        printf("\n");
      }
      break;
      case -1:
      return 0;
      default:
      printf("Input not allowed, please try again\n");
      break;
  }

  }
  return 0;
}
