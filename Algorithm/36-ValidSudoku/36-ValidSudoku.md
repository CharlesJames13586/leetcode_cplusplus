### 36.Valid Sudoku

* Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

  判断一个9\*9的数独是否是合法的。下列是一个填写的数独格子合法的规则：

  1. Each row must contain the digits 1-9 without repetition.
  2. Each column must contain the digits 1-9 without repetition.
  3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

  &ensp;
  1. 每一行必须包含数字1-9并且不能重复；
  2. 每一列必须包含数字1-9并且不能重复；
  3. 网格中9个3\*3的子方框必须包含数字1-9并且不能重复。

  ![Sudoku](36-ValidSudoku_Resource/250px-Sudoku-by-L2G-20050714.svg.png)<br>
  A partially filled sudoku which is valid.<br>
  一个合法的未填写完成的数独<br>

  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

  这个数独板可能是未填写完成的，空的格子用‘.’填充。

* **Example 1:**
  
  >Input:<br>
   [<br>
     &ensp;&ensp;["5","3",".",".","7",".",".",".","."],<br>
     &ensp;&ensp;["6",".",".","1","9","5",".",".","."],<br>
     &ensp;&ensp;[".","9","8",".",".",".",".","6","."],<br>
     &ensp;&ensp;["8",".",".",".","6",".",".",".","3"],<br>
     &ensp;&ensp;["4",".",".","8",".","3",".",".","1"],<br>
     &ensp;&ensp;["7",".",".",".","2",".",".",".","6"],<br>
     &ensp;&ensp;[".","6",".",".",".",".","2","8","."],<br>
     &ensp;&ensp;[".",".",".","4","1","9",".",".","5"],<br>
     &ensp;&ensp;[".",".",".",".","8",".",".","7","9"]<br>
   ]<br>
   Output: true<br>

* **Example 2:**

  >Input:<br>
   [<br>
     &ensp;&ensp;["8","3",".",".","7",".",".",".","."],<br>
     &ensp;&ensp;["6",".",".","1","9","5",".",".","."],<br>
     &ensp;&ensp;[".","9","8",".",".",".",".","6","."],<br>
     &ensp;&ensp;["8",".",".",".","6",".",".",".","3"],<br>
     &ensp;&ensp;["4",".",".","8",".","3",".",".","1"],<br>
     &ensp;&ensp;["7",".",".",".","2",".",".",".","6"],<br>
     &ensp;&ensp;[".","6",".",".",".",".","2","8","."],<br>
     &ensp;&ensp;[".",".",".","4","1","9",".",".","5"],<br>
     &ensp;&ensp;[".",".",".",".","8",".",".","7","9"]<br>
   ]<br>
   Output: false

   Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

   说明：除了左上角的“5”被修改为“8”，其它的都和例1相同。因为左上角3\*3的子方框中有两个“8”，所以它是不合法的。

* **Note:**

  * A Sudoku board (partially filled) could be valid but is not  necessarily solvable.
  * Only the filled cells need to be validated according to the mentioned rules.
  * The given board contain only digits 1-9 and the character '.'.
  * The given board size is always 9x9.

  &ensp;

  * 一个未完成的数独板可能是合法的但未必是可解的；
  * 只有填满的数独板需要根据规则去验证合法性；
  * 被给的板子只包括数字1-9和字符“.”；
  * 被给的板子的大小总是9\*9.

* **解题思路：**

  &emsp;&emsp;该题只需要根据规则去验证所给的数独板是否合法，不需要去求所给数独是否可解，一定程度上简化了题目。

  &emsp;&emsp;我们只需要分别检查行、列和3*3方格的合法性即可。

  &emsp;&emsp;判断(最多)九个数组的合法性，先定义一个九个元素的数组，分别对应1-9，当扫描一个数字时，将相应下标的元素进行修改，这样在每次扫描前检查对应元素是否进行过修改，如果进行过修改，就说明有重复。这算是一个哈希算法，哈希数组的长度与数字个数相同，每个数字都有自己单独的位置。扫描三次分别检测行、列和3*3方格的合法性是一种**牺牲时间换空间的**方法。

  &emsp;&emsp;除此之外还有一种**牺牲空间换时间的**方法，即定义三个大小为9数组，分别用来记录扫描到一个元素对应行、列和3*3方格的数字。这样只需要扫描一边，但需要知道的是这两种方法的复杂度都一样。