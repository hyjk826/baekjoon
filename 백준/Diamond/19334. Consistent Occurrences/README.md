# [Diamond V] Consistent Occurrences - 19334 

[문제 링크](https://www.acmicpc.net/problem/19334) 

### 성능 요약

메모리: 8604 KB, 시간: 2376 ms

### 분류

이분 탐색, 자료 구조, 그리디 알고리즘, 해싱, mo's, 오프라인 쿼리, 문자열, 접미사 배열과 LCP 배열, 트리를 사용한 집합과 맵

### 문제 설명

<p>Let us define a <em>consistent set of occurrences of string $t$ in string $s$</em> as a set of occurrences of $t$ in $s$ such that no two occurrences intersect (in other words, no character position in $s$ belongs to two different occurrences).</p>

<p>You are given a string $s$ consisting of $n$ lowercase English letters, and $m$ queries. Each query contains a single string $t_i$.</p>

<p>For each query, print the maximum size of a consistent set of occurrences of $t$ in $s$.</p>

### 입력 

 <p>The first line contains two space-separated integers $n$ and $m$: the length of string $s$ and the number of queries ($1 \le n \le 10^{5}$, $1 \le m \le 10^{5}$).</p>

<p>The second line contains the string $s$ consisting of $n$ lowercase English letters.</p>

<p>Each of the next $m$ lines contains a single string $t_i$ consisting of lowercase English letters: the $i$-th query ($1 \le |t_i| \le n$, where $|t_i|$ is the length of the string $t_i$).</p>

<p>It is guaranteed that the total length of all $t_i$ does not exceed $10^{5}$ characters.</p>

### 출력 

 <p>For each query $i$, print one integer on a separate line: the maximum size of a consistent set of occurrences of $t_i$ in $s$.</p>

