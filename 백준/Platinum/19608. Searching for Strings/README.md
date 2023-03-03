# [Platinum IV] Searching for Strings - 19608 

[문제 링크](https://www.acmicpc.net/problem/19608) 

### 성능 요약

메모리: 24304 KB, 시간: 32 ms

### 분류

해싱(hashing), 라빈–카프(rabin_karp), 문자열(string)

### 문제 설명

<p>You’re given a string N, called the needle, and a string H, called the haystack, both of which contain only lowercase letters “a”..“z”.</p>

<p>Write a program to count the number of distinct permutations of N which appear as a substring of H at least once. Note that N can have anywhere between 1 and |N|! distinct permutations in total – for example, the string “aab” has 3 distinct permutations (“aab”, “aba”, and “baa”).</p>

### 입력 

 <p>The first line contains N (1 ≤ |N| ≤ 200 000), the needle string.</p>

<p>The second line contains H (1 ≤ |H| ≤ 200 000), the haystack string.</p>

### 출력 

 <p>Output consists of one integer, the number of distinct permutations of N which appear as a substring of H.</p>

