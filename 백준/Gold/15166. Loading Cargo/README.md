# [Gold I] Loading Cargo - 15166 

[문제 링크](https://www.acmicpc.net/problem/15166) 

### 성능 요약

메모리: 9884 KB, 시간: 36 ms

### 분류

이분 그래프, 다이나믹 프로그래밍, 그래프 이론

### 문제 설명

<p>We need to ship N capsules containing different potentially hazardous chemicals using an aircraft. The aircraft has one cargo compartment on the left with free space for L capsules and one cargo compartment on the right with free space for R capsules. According to the safety regulations, some capsules conflict with each other and cannot be loaded into the same cargo compartment (in case there is leakage and reaction). Given this information, your job is to determine whether all the capsules can be loaded into the aircraft.</p>

### 입력 

 <p>The input starts with a line containing four integers L, R, N and C, where L (0 ≤ L ≤ 2 000) is the capacity of the left cargo compartment, R (0 ≤ R ≤ 2 000) is the capacity of the right cargo compartment, N (0 ≤ N ≤ 2 000) is the number of capsules and C (0 ≤ C ≤ 200 000) is the number of conflicts.</p>

<p>The next C lines describe the conflicts. Each of these lines contain two integers X (0 ≤ X ≤ N − 1) and Y (0 ≤ Y ≤ N − 1 and X ≠ Y ) representing a pair of capsules that conflict with each other. Each pair of capsules that conflict only appear once in the input. The capsules are numbered from 0 to N − 1.</p>

### 출력 

 <p>Display Yes if all the capsules can be loaded into the aircraft and display No otherwise.</p>

