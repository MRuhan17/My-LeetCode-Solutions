from typing import List
import operator


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
    
        operators = {
            "+": operator.add,
            "-": operator.sub,
            "*": operator.mul,
            "/": operator.truediv,
        }
      
        stack = []
      
        for token in tokens:
            if token in operators:
                second_operand = stack.pop()
                first_operand = stack.pop()
              
                result = int(operators[token](first_operand, second_operand))
                stack.append(result)
            else:
                stack.append(int(token))
      
        return stack[0]
