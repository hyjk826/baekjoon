# [Diamond IV] Luggage - 20226 

[문제 링크](https://www.acmicpc.net/problem/20226) 

### 성능 요약

메모리: 2676 KB, 시간: 348 ms

### 분류

수학(math), 밀러–라빈 소수 판별법(miller_rabin), 정수론(number_theory), 폴라드 로(pollard_rho), 소수 판정(primality_test)

### 문제 설명

<p>Mr. Yokohama is estimating the delivery fare for a number of luggage pieces. The fare for a piece is determined by its width <i>w</i>, depth <i>d</i> and height <i>h</i>, each rounded up to an integer. The fare is proportional to the <em>sum</em> of them.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 338px; height: 275px;"></p>

<p>The list of the luggage pieces is at hand, but the list has the <em>product</em> <i>w</i>×<i>d</i>×<i>h</i> for each piece, instead of the <em>sum</em> <i>w</i>+<i>d</i>+<i>h</i> by mistake. This information is not enough to calculate the exact delivery fare.</p>

<p>Mr. Yokohama therefore decided to estimate the minimum possible delivery fare. To this end, given the listed <em>product</em> <i>p</i> for each of the luggage pieces, the minimum possible <em>sum</em> <i>s</i>=<i>w</i>+<i>d</i>+<i>h</i> satisfying <i>p</i>=<i>w</i>×<i>d</i>×<i>h</i> should be found.</p>

<p>You are requested to help Mr. Yokohama by writing a program that, when given the product <i>p</i>, computes the minimum sum <i>s.</i></p>

### 입력 

 <p>The input consists of multiple datasets. Each of the datasets has one line containing an integer <i>p</i> (0 < <i>p</i> < 10<sup>15</sup>).</p>

<p>The end of the input is indicated by a line containing a zero.</p>

<p>The number of datasets does not exceed 300.</p>

### 출력 

 <p>For each dataset, output a single line containing an integer <i>s</i>. <i>s</i> should be the minimum possible sum <i>w</i>+<i>d</i>+<i>h</i> of three positive integers, <i>w,</i> <i>d,</i> and <i>h,</i> satisfying <i>p</i>=<i>w</i>×<i>d</i>×<i>h.</i></p>

