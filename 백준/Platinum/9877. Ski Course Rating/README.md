# [Platinum I] Ski Course Rating - 9877 

[문제 링크](https://www.acmicpc.net/problem/9877) 

### 성능 요약

메모리: 20992 KB, 시간: 400 ms

### 분류

이분 탐색(binary_search), 자료 구조(data_structures), 분리 집합(disjoint_set), 병렬 이분 탐색(pbs)

### 문제 설명

<p>The cross-country skiing course at the winter Moolympics is described by an M x N grid of elevations (1 <= M,N <= 500), each elevation being in the range 0 .. 1,000,000,000.</p><p>Some of the cells in this grid are designated as starting points for the course.  The organizers of the Moolympics want to assign a difficulty rating to each starting point.  The difficulty level of a starting point P should be the minimum possible value of D such that a cow can successfully reach at least T total cells of the grid (1 <= T <= MN), if she starts at P and can only move from cell to adjacent cell if the absolute difference in elevation between the cells is at most D.  Two cells are adjacent if one is directly north, south, east, or west of the other.</p><p>Please help the organizers compute the difficulty rating for each starting point.</p>

### 입력 

 <ul><li>Line 1: The integers M, N, and T.</li><li>Lines 2..1+M: Each of these M lines contains N integer elevations.</li><li>Lines 2+M..1+2M: Each of these M lines contains N values that are either 0 or 1, with 1 indicating a cell that is a starting point.</li></ul>

### 출력 

 <ul><li>Line 1: The sum of difficulty ratings of all starting points (note that this may not fit into a 32-bit integer, even though individual difficulty ratings will).</li></ul>

