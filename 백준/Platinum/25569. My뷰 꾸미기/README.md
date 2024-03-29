# [Platinum IV] My뷰 꾸미기 - 25569 

[문제 링크](https://www.acmicpc.net/problem/25569) 

### 성능 요약

메모리: 6708 KB, 시간: 120 ms

### 분류

조합론(combinatorics), 분할 정복을 이용한 거듭제곱(exponentiation_by_squaring), 페르마의 소정리(flt), 수학(math), 모듈로 곱셈 역원(modular_multiplicative_inverse), 정수론(number_theory)

### 문제 설명

<p style="text-align: center;"><img alt="카카오_뷰_로고" src="" style="max-height:270px; object-fit:contain; display:inline-block;"></p>

<p>카카오 뷰는 사용자가 관심을 가질 만한 주제를 분석하고, 이를 바탕으로 큐레이팅을 진행하는 카카오톡의 서비스이다. '발견'을 통해 흥미로운 주제의 콘텐츠를 탐색하고, 마음에 드는 콘텐츠는 My뷰에 등록해서 지속적으로 구독할 수 있다.</p>

<p>당신은 $N$개의 관심 분야를 정하고, 관심 분야마다 $2$명의 에디터를 골라 그들의 콘텐츠를 받아보기로 했다.</p>

<p>$i\ (1 \le i \le N)$번째 관심 분야의 에디터 $2$명은 각각 현재까지 $A_i$개, $B_i$개의 글을 작성하였다. 당신은 각 관심 분야마다, 에디터 $2$명의 글이 <strong>같은 개수만큼 등장하도록</strong> My뷰를 꾸밀 것이다. 또한, 에디터마다 최소 $1$개 이상씩의 글이 등장하도록 할 것이다.</p>

<p>당신은 위 방법대로 My뷰를 구성할 수 있는 경우의 수가 얼마나 되는지 알아보고자 한다.</p>

<p>경우의 수를 셀 때 글들의 정렬 순서는 고려하지 않는다고 하자. 즉, 큐레이션에 포함된 글들이 모두 동일하다면 정렬 순서가 다르더라도 같은 경우로 취급한다.</p>

### 입력 

 <p>첫 번째 줄에 정수 $N$이 주어진다. $(1 \le N \le 300\,000)$</p>

<p>두 번째 줄부터 $N$개의 줄에 걸쳐, $i + 1$번째 줄에 $A_i, B_i$가 공백을 사이에 두고 주어진다. $(1 \le A_i, B_i \le 300\,000)$</p>

### 출력 

 <p>지문에 주어진 방법대로 My뷰를 구성할 수 있는 경우의 수를 출력하라. 답이 커질 수 있으므로 $10^9+7$로 나눈 나머지를 출력한다.</p>

