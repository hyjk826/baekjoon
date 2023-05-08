# [Platinum II] City Driving - 7630 

[문제 링크](https://www.acmicpc.net/problem/7630) 

### 성능 요약

메모리: 37892 KB, 시간: 264 ms

### 분류

최소 공통 조상, 트리

### 문제 설명

<p>You recently started frequenting San Francisco in your free time and realized that driving in the city is a huge pain. There are only N locations in the city that interest you, though, and you have decided to try to improve your driving experience. Since you lack a GPS and cannot remember too many different routes, you wrote down the directions and how long it takes to get between N different pairs of locations (the same in both directions), ensuring that using only these paths you can get from any location to any other one.</p>

<p>Now you are planning your trip for the weekend and you need to figure out the fastest way to get between Q pairs of locations in the city using only the routes you have written down.</p>

### 입력 

 <p>The input consists of multiple test cases. The first line contains a single integer N, 3 ≤ N ≤ 100,000, the number of locations of interest and the number of routes you wrote down. The next N lines each contain three integers u, v, and w (1 ≤ w ≤ 1,000), indicating that you have directions from location u to location v and vice-versa (0-indexed) which take w time. The following line contains a single integer Q, 1 ≤ Q ≤ 10,000, the number of pairs of locations you need to compute the travel time for. The next Q lines each contain two integers u and v, indicating that you should find the minimum time to get from location u to location v. The input terminates with a line with N = 0.</p>

### 출력 

 <p>For each test case, print out Q lines, one for each pair of locations u and v you are finding the fastest routes for. Each line should simply contain the minimum time it takes to travel from location u to location v.</p>

