# [Platinum IV] Distinctive Character - 15019 

[문제 링크](https://www.acmicpc.net/problem/15019) 

### 성능 요약

메모리: 9668 KB, 시간: 92 ms

### 분류

그래프 이론, 문자열, 그래프 탐색, 너비 우선 탐색, 비트마스킹

### 문제 설명

<p>Tira would like to join a multiplayer game with n other players. Each player has a character with some features. There are a total of k features, and each character has some subset of them.</p>

<p>The similarity between two characters A and B is calculated as follows: for each feature f, if both A and B have feature f or if none of them have feature f, the similarity increases by one.</p>

<p>Tira does not have a character yet. She would like to create a new, very original character so that the maximum similarity between Tira’s character and any other character is as low as possible.</p>

<p>Given the characters of the other players, your task is to create a character for Tira that fulfils the above requirement. If there are many possible characters, you can choose any of them.</p>

### 입력 

 <p>The first line of input contains two integers n and k, where 1 ≤ n ≤ 10<sup>5</sup> is the number of players (excluding Tira) and 1 ≤ k ≤ 20 is the number of features.</p>

<p>Then follow n lines describing the existing characters. Each of these n lines contains a string of k digits which are either 0 or 1. A 1 in position j means the character has the j’th feature, and a 0 means that it does not have the j’th feature.</p>

### 출력 

 <p>Output a single line describing the features of Tira’s character in the same format as in the input. If there are multiple possible characters with the same smallest maximum similarity, any one of them will be accepted.</p>

