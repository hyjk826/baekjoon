# [Platinum IV] 새로운 수열 - 15318 

[문제 링크](https://www.acmicpc.net/problem/15318) 

### 성능 요약

메모리: 11396 KB, 시간: 116 ms

### 분류

수학(math), 누적 합(prefix_sum)

### 문제 설명

<p>다음과 같은 수열 A가 주어졌을 때,</p>

<p style="text-align:center">A = {a<sub>0</sub>, a<sub>1</sub>, ..., a<sub>N-2</sub>, a<sub>N-1</sub>}</p>

<p>새로운 수열 B는 다음과 같이 정의된다.</p>

<p style="text-align:center">B = {b<sub>0</sub>, b<sub>1</sub>, ..., b<sub>N-2</sub>, b<sub>N-1</sub>}</p>

<p style="text-align:center"><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44F TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-munderover space="4"><mjx-over style="padding-bottom: 0.142em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-over><mjx-box><mjx-munder><mjx-row><mjx-base style="padding-left: 0.044em;"><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em; padding-left: 0.13em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-texatom></mjx-under></mjx-row></mjx-munder></mjx-box></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.413em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.177em;"><mjx-texatom size="s" texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mi class="mjx-n"><mjx-c class="mjx-c25"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><msub><mi>b</mi><mi>i</mi></msub><mo>=</mo><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>k</mi><mo>=</mo><mn>0</mn></mrow><mrow data-mjx-texclass="ORD"><mi>N</mi><mo>−</mo><mn>1</mn></mrow></munderover><mrow data-mjx-texclass="ORD"><mo stretchy="false">(</mo><mo stretchy="false">(</mo><mo>−</mo><mn>1</mn><msup><mo stretchy="false">)</mo><mi>k</mi></msup><mo>×</mo><mo stretchy="false">(</mo><mi>k</mi><mo>+</mo><mn>1</mn><mo stretchy="false">)</mo><mo>×</mo><msub><mi>a</mi><mrow data-mjx-texclass="ORD"><mo stretchy="false">(</mo><mi>i</mi><mo>+</mo><mi>k</mi><mo stretchy="false">)</mo><mi mathvariant="normal">%</mi><mi>N</mi></mrow></msub><mo stretchy="false">)</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[b_i = \sum_{k=0}^{N-1}{((-1)^k \times (k+1) \times a_{(i+k)\%N})}\]</span> </mjx-container></p>

<p>수열 A가 주어지면, 수열 B를 구해보자.</p>

### 입력 

 <p>첫 줄에 N(1 ≤ N ≤ 300,000)이 주어진다. 두 번째 줄에 N개의 정수 a<sub>i</sub> (|a<sub>i</sub>| ≤ 10<sup>9</sup>)가 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 수열 B를 구성하는 N개의 정수 b<sub>i</sub>를 공백으로 구분하여 출력한다. |b<sub>i</sub>| ≤ 10<sup>18</sup>인 입력만 주어진다.</p>

