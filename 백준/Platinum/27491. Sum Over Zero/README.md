# [Platinum II] Sum Over Zero - 27491 

[문제 링크](https://www.acmicpc.net/problem/27491) 

### 성능 요약

메모리: 14604 KB, 시간: 124 ms

### 분류

값 / 좌표 압축(coordinate_compression), 자료 구조(data_structures), 다이나믹 프로그래밍(dp), 누적 합(prefix_sum), 세그먼트 트리(segtree)

### 문제 설명

<p>You are given an array $a_1, a_2, \ldots, a_n$ of $n$ integers. Consider $S$ as a set of segments satisfying the following conditions.</p>

<ul>
	<li>Each element of $S$ should be in form $[x, y]$, where $x$ and $y$ are integers between $1$ and $n$, inclusive, and $x \leq y$.</li>
	<li>No two segments in $S$ intersect with each other. Two segments $[a, b]$ and $[c, d]$ intersect if and only if there exists an integer $x$ such that $a \leq x \leq b$ and $c \leq x \leq d$.  </li>
	<li>For each $[x, y]$ in $S$, $a_x+a_{x+1}+ \ldots +a_y \geq 0$.</li>
</ul>

<p>The length of the segment $[x, y]$ is defined as $y-x+1$. $f(S)$ is defined as the sum of the lengths of every element in $S$. In a formal way, $f(S) = \sum_{[x, y] \in S} (y - x + 1)$. Note that if $S$ is empty, $f(S)$ is $0$.</p>

<p>What is the maximum $f(S)$ among all possible $S$?</p>

### 입력 

 <p>The first line contains one integer $n$ ($1 \leq n \leq 2 \cdot 10^5$).</p>

<p>The next line is followed by $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \leq a_i \leq 10^9$).</p>

### 출력 

 <p>Print a single integer, the maximum $f(S)$ among every possible $S$.</p>

