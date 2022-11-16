# [Silver I] Cow Yahtzee - 6228 

[문제 링크](https://www.acmicpc.net/problem/6228) 

### 성능 요약

메모리: 2028 KB, 시간: 44 ms

### 분류

브루트포스 알고리즘(bruteforcing), 파싱(parsing), 문자열(string)

### 문제 설명

<p>In their usual clumsy way, the cows are play a version of Yahtzee, the dice-rolling game.  They roll N (1 <= N <= 20) dice, each having S (1 <= S <= 8) sides.  They are curious as to the number of ways a dice roll can meet a particular criterion (like "contains three 2's" or "contains one 2 and two 3's").</p>

<p>Help them learn about probability. Write a program that reads not only N and S but also some expressions that describe their criteria. Count the number ways the expression can be satisfied over the entire set of all possible dice rolls (the entire set of rolls for three two-sided dice is: {1,1,1; 1,1,2; 1,2,1; 1,2,2; 2,1,1; 2,1,2; 2,2,1; 2,2,2};</p>

<p>Expressions comprise combinations of a basic form that expresses the thought "want at least W copies of result R". It looks like this:</p>

<pre>WxR</pre>

<p>where (0 <= W <= N and 1 <= R <= S). Each test run will supply E expressions (1 <= E <= 20), each of which contains a number 1..10 of the basic forms separated by a '+', which means 'and' (see below). The set of lines expresses the thought that is the 'inclusive or' of each of the lines individually. Thus the pair of expressions shown below means "at least three rolls of five OR both at least one roll of 3 and also at least two rolls of 4":</p>

<pre>3x5
1x3+2x4</pre>

<p>Here are some of the combinations of four five-sided dice that satisfy the above expression: 5,5,5,1; 4,5,5,5; 3,4,4,2; 3,4,4,3; 3,4,4,5; 4,4,5,3.</p>

<p>Programming note: Be sure to verify that you can read in two integers from one line and a string from the next line. In some languages' I/O schema, this is harder than it looks!</p>

<p>Also note that the total number of dice combinations will never exceed 1,512,768 in the supplied test data.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, S, and E</li>
	<li>Lines 2..E+1: Line i+1 describes expression i as above.</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of ways the expression(s) can be satisfied by rolling the dice in all combinations.</li>
</ul>

