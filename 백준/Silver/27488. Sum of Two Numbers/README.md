# [Silver III] Sum of Two Numbers - 27488 

[문제 링크](https://www.acmicpc.net/problem/27488) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

애드 혹(ad_hoc), 구현(implementation), 수학(math)

### 문제 설명

<p>The sum of digits of a non-negative integer $a$ is the result of summing up its digits together when written in the decimal system. For example, the sum of digits of $123$ is $6$ and the sum of digits of $10$ is $1$.</p>

<p>In a formal way, the sum of digits of $\displaystyle a=\sum_{i=0}^{\infty} a_i \cdot 10^i$, where $0 \leq a_i \leq 9$, is defined as $\displaystyle\sum_{i=0}^{\infty}{a_i}$.</p>

<p>Given an integer $n$, find two non-negative integers $x$ and $y$ which satisfy the following conditions.</p>

<ul>
	<li> $x+y=n$, and</li>
	<li>The sum of digits of $x$ and the sum of digits of $y$ differ by at most $1$.</li>
</ul>

<p>It can be shown that such $x$ and $y$ always exist.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). </p>

<p>Each test case consists of a single integer $n$ ($1 \leq n \leq 10^9$)</p>

### 출력 

 <p>For each test case, print two integers $x$ and $y$.</p>

<p>If there are multiple answers, print any.</p>

