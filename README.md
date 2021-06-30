# **sudokuSolver**
This program uses plain c++ to solve sudoku puzzles using non-learning algorithms.

### Problem Formulation by AI Search Methods consists of the following key concepts
– Configuration or State<br />
– Constraints or Definitions of Valid Configurations<br />
– Rules for Change of State and their Outcomes<br />
– Initial or Start Configurations<br />
– Goal Satisfying Configurations<br />
– An Implicit State or Configuration Space<br />
– Valid Solutions from Start to Goal in the State Space<br />
– General Algorithms which SEARCH for Solutions in this State Space<br />

## Constraint Satifaction Tree Problem:
### Constraints
• Unary constraints or node constraints (eg. xi , 9) <br />
• Binary constraints or edge between nodes (eg. xi , xj) <br />
• Higher order or hyper-edge between nodes (eg. x1 + x2 = x3)<br />
### Node consistency
• For every variable Vi, remove all elements of Di that do not satisfy the unary constraints for the variable<br />
• First step is to reduce the domains using node consistency<br />
### Arc consistency
• For every element xij of Di, for every edge from Vi to Vj, remove xij if it has no consistent value(s) in other domains satisfying the Constraints<br />
• Continue to iterate using arc consistency till no further reduction happens.<br />
### Path consistency
• For every element yij of Di, choose a path of length L with L variables, use a consistency checking method similar to above to reduce domains if possible<br /><hr />
![image](https://user-images.githubusercontent.com/58771543/124021777-95570100-da09-11eb-8a6f-09bc02030b6e.png)
