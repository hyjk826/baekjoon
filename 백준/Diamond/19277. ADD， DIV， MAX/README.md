# [Diamond I] ADD, DIV, MAX - 19277 

[문제 링크](https://www.acmicpc.net/problem/19277) 

### 성능 요약

메모리: 34840 KB, 시간: 544 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 문제 설명

<p>You are given an integer sequence $a_0, a_1, \ldots, a_{N-1}$.</p>

<p>You have to perform $Q$ queries, each query is one of the following:</p>

<ul>
	<li><strong>ADD</strong> $t=0$, <code>l r x</code>: for each $i$ between $l$ and $r$ inclusively, $a_i = a_i + x$.</li>
	<li><strong>DIV</strong> $t=1$, <code>l r x</code>: for each $i$ between $l$ and $r$ inclusively $a_i = {\rm floor}(a_i / x)$, where ${\rm floor}(y)$ is the biggest integer that is not greater than $y$.</li>
	<li><strong>MAX</strong> $t=2$. <code>l r x=0</code>: print ${\rm max}(a_l, a_{l+1}, \ldots, a_r)$.</li>
</ul>

### 입력 

 <p>Input is given in the following format:</p>

<p>$N$ $Q$</p>

<p>$a_0$ $a_1$ ... $a_{N-1}$</p>

<p>$t_1$ $l_1$ $r_1$ $x_1$</p>

<p>$t_2$ $l_2$ $r_2$ $x_2$</p>

<p>$\ldots$</p>

<p>$t_Q$ $l_Q$ $r_Q$ $x_Q$</p>

### 출력 

 <p>For each <strong>MAX</strong> query, print ${\rm max}(a_l, a_{l+1}, ..., a_r)$.</p>

