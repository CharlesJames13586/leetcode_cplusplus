### 37.Sodoku Solver

*
  Write a program to solve a Sudoku puzzle by filling the empty cells.

  写一个求解数独的程序，填满空的方格。

  A sudoku solution must satisfy all of the following rules:

  一个数独的解必须满足下列所有规则：

    1. Each of the digits 1-9 must occur exactly     once in each row.
    2. Each of the digits 1-9 must occur exactly     once in each column.
    3. Each of the the digits 1-9 must occur         exactly once in each of the 9 3x3             sub-boxes of the grid.
    
    &ensp;

    1. 每行必须包括数字1-9；
    2. 每列必须包括数字1-9；
    3. 每个3\*3的小方块必须包括数字1-9.


  Empty cells are indicated by the character '.'.

  空的格子以‘.’表示。

  ![Soduku](37-SodokuSolverResource/Sudoku.png)

  A sudoku puzzle...

  数独问题...

  ![Soduku](37-SodokuSolverResource/Sudoku-solution.png)

  ...and its solution numbers marked in red.

  ...被标记为红色的数字是他的解。

* **Note:**

  * The given board contain only digits 1-9 and the     character '.'.
  * You may assume that the given Sudoku puzzle will    have a single unique solution.
  * The given board size is always 9x9.

  &ensp;

  * 被给的数独板只包含数字1-9和‘.’；
  * 你可以假设被给的数独问题有且只有唯一解；
  * 被给的数独板大小总是9\*9。

* **解题思路：**

  &emsp;&emsp;本题我使用了暴力求解，就是一个一个试。从第一行第一列的方格开始扫描，当扫描到空的格子时，从1-9每个数字尝试一遍，当一个数字在当前是不违法的数字时，将数字填进去迭代求解下一个方格，直到所有方格都被合法的填写。如果在扫描一个方格时发现1-9所有数字都不合法，说明前面填写的某个数字在当时是合法的但不是解，这个时候就需要回溯。

  &emsp;&emsp;我们可以把每个空的方格看成一个节点，从第一个方格开始有九种可能，则有九个子节点。这样把遍历的过程看成对树进行深度遍历。在遍历的过程中对树进行剪枝可以提高运行速度。

  &emsp;&emsp;这种暴力求解的方法十分简洁易懂，由于数独问题的规模是一定的(9\*9)，所以这种方法不会超时。但在提交后发现运行20-24ms，只超过了27%的提交。不过空间击败了100%的提交。

  ![提交情况截图](37-SodokuSolverResource\submissions.png)


