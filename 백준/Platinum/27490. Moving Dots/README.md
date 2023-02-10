# [Platinum V] Moving Dots - 27490 

[문제 링크](https://www.acmicpc.net/problem/27490) 

### 성능 요약

메모리: 2152 KB, 시간: 228 ms

### 분류

이분 탐색(binary_search), 조합론(combinatorics), 수학(math)

### 문제 설명

<p>We play a game with $n$ dots on a number line.</p>

<p>The initial coordinate of the $i$-th dot is $x_i$. These coordinates are distinct. Every dot starts moving simultaneously with the same constant speed.</p>

<p>Each dot moves in the direction of the closest dot (different from itself) until it meets another dot. In the case of a tie, it goes to the left. Two dots meet if they are in the same coordinate, after that, they stop moving.</p>

<p>After enough time, every dot stops moving. The result of a game is the number of distinct coordinates where the dots stop.</p>

<p>Because this game is too easy, calculate the sum of results when we play the game for every subset of the given $n$ dots that has at least two dots. As the result can be very large, print the sum modulo $10^9+7$.</p>

### 입력 

 <p>The first line contains one integer $n$ ($2 \leq n \leq 3000$).</p>

<p>The next line contains $n$ integers $x_1, x_2, \ldots, x_n$ ($1 \leq x_1 < x_2 < \ldots < x_n \leq 10^9$), where $x_i$ represents the initial coordinate of $i$-th dot.</p>

### 출력 

 <p>Print the sum of results modulo $10^9+7$.</p>

