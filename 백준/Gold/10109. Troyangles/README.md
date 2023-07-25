# [Gold IV] Troyangles - 10109 

[문제 링크](https://www.acmicpc.net/problem/10109) 

### 성능 요약

메모리: 21820 KB, 시간: 264 ms

### 분류

다이나믹 프로그래밍

### 문제 설명

<p>Troy loves triangles. He especially likes counting triangles. He has an N-by-N grid consisting of either “<code>.</code>” or “<code>#</code>” characters. Help him count the number of triangles formed only by “<code>#</code>” characters in the grid. Triangles are of the form</p>

<pre>          #
    #    ### 
#, ###, #####, etc.</pre>

<p>More formally, a triangle of height h consists of h rows for some positive integer h. The ith row contains 2i − 1 “<code>#</code>” characters for i = 1, . . . , h. The rows are centred above each other so that they are symmetrical about a vertical line down their middle.</p>

### 입력 

 <p>The first line contains the number N (1 ≤ N ≤ 2000) representing the size of the grid. The next N lines each contain N characters as described above.</p>

### 출력 

 <p>Output the number of triangles in the grid.</p>

