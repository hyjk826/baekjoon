# [Platinum V] The Way - 14553 

[문제 링크](https://www.acmicpc.net/problem/14553) 

### 성능 요약

메모리: 2032 KB, 시간: 84 ms

### 분류

벌래캠프–매시(berlekamp_massey), 다이나믹 프로그래밍(dp)

### 문제 설명

<p>여우와 토끼는 사이가 좋았다. 하지만 어느 날 토끼가 여우에게 갓겜 "히어로즈 오브 더 스톰"을 추천했고, 여우는 게임을 해보고 너무 화가나서 토끼를 쫓으러 갔다.</p>

<p>히어로즈 오브 더 스톰의 맵을 단순화 시켜서 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 \times N$</span></mjx-container>격자라고 하고, 가장 왼쪽 위에서 토끼가 나왔다. 여우는, 토끼를 쫓아 가면서, 한번 왔던 격자에, 다시 돌아가지 못하도록 함정을 설치했다. 그래서 토끼는 칸을 중복해서 지나지 못한다. 토끼는 가장 오른쪽 아래 칸으로 안전을 보장받기 위해 가려고 한다.</p>

<p>이걸 보던 뉴쉐프는, 토끼가 도망칠 수 있는 가짓수가 궁금했다. 뉴쉐프의 궁금증을 풀어주자.</p>

### 입력 

 <p>첫째 줄에, 격자의 가로 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>1000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le N \le 1000$</span></mjx-container>)</p>

### 출력 

 <p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 \times N$</span></mjx-container> 격자를 칸을 중복해서 지나지 않고, 왼쪽 위에서 오른쪽 아래로 가는 경우의 수를 1000000009(<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup><mo>+</mo><mn>9</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9 + 9$</span></mjx-container>)로 나눈 나머지를 구하라.</p>

