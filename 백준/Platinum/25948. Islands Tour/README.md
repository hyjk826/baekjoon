# [Platinum V] Islands Tour - 25948 

[문제 링크](https://www.acmicpc.net/problem/25948) 

### 성능 요약

메모리: 143612 KB, 시간: 992 ms

### 분류

그래프 이론, 그래프 탐색, 위상 정렬, 방향 비순환 그래프

### 문제 설명

<p>There are beautiful islands connected with zip-lines. A tourist can go from one island to another island sliding through a zip-line that connects the islands. Sliding through a zip-line above sunset sea, a tourist can see breathtaking sceneries of nature with twinkling lights over the sunlit sea waters. These islands are fantastic attractions among tourists. Each island is full of flowers of numerous colors. Travelling from an arbitrary island, a tourist called Optimizer wants to visit as many distinct islands as possible.</p>

<p>The islands are represented as a directed graph $G(V, E)$. A zip-line from an island $v$ to another island $w$ is represented as a directed edge $(v, w) ∈ E$. We assume that each island has at most one outgoing zip-line, that is, for each vertex $v ∈ V$, we have at most one outgoing edge.</p>

<p>For example, the figure below shows an example of the islands represented as a directed graph.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 239px; height: 245px;"></p>

<p>The dotted path in the following graph denotes a longest tour that visits as many distinct islands as possible.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 232px; height: 240px;"></p>

<p>Given a directed graph $G(V, E)$ that represents the islands and their connections using zip-lines, write a program to output the maximum number of islands that can be visited by Optimizer. Note that Optimizer can start from an arbitrary island and cannot visit the same island twice or more.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, $m$ and $n$ ($0 ≤ m ≤ n ≤ 1\,000\,000$), where $m$ is the number of zip-line connections (edges) and $n$ is the number of islands (vertices). The islands are numbered from $0$ to $n - 1$. In the following $m$ lines, the $i$-th line contains two integers $v_i$ and $w_i$ that represent a directed edge $(v_i , w_i)$ from $v_i$ to $w_i$. We assume that each vertex has at most one outgoing edge.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the maximum number of distinct islands that can be visited by riding zip-lines starting from an arbitrary island.</p>

