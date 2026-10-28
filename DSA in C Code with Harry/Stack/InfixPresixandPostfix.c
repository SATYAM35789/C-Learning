/* 
Thses are the notations to write an expression
1.Infix- operend1<operator>operend2
 ex a+b  , a/b
2.prefix-> <operator>operand1 operand2
ex +ab,-ab
3.Postfix  operand1 operand2 <operator>
  ab*, ab+ , ab-

Infix: a*(b+c)*d
Infix to postfix:- abc+*d*
It is easy use compairing to the Infix as we pass only one time.  
Operator precedence:- Needed to complier to evulate the expression while converting. 
Q1 x-y*z to prefix and postfix.
Converting it to Prefix 
step1:- Parenthesize the expression. 
  (x-(y*z)) 

step2:- Go to the innermost parenthesis and solve
   (x-[*yz])
   -x*yz    Prefix done
Converting it to Postfix
step1:- Parenthesize the expression. 
  (x-(y*z)) 
step2:- Go to the innermost parenthesis and solve
   (x-[yz*])
   xyz*-

*/