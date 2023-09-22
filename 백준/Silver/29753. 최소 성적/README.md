# [Silver IV] 최소 성적 - 29753 

[문제 링크](https://www.acmicpc.net/problem/29753) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

임의 정밀도 / 큰 수 연산, 사칙연산, 구현, 수학

### 문제 설명

<p>이번 학기에 받아야 하는 최소 평균 평점 기준과 수강한 과목 중 한 과목을 제외한 모든 과목의 성적이 주어졌을 때, 최소 평균 평점 기준을 충족하기 위해 받아야 하는 나머지 한 과목의 최소 성적을 출력하시오. 성적에 따른 평점 환산표는 다음과 같다.</p>

<div style="overflow:auto;max-width:calc(100vw - 30px)">
<table align="center" border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="table-layout: fixed; text-align: center; width: 600px; height: 60px;">
	<tbody>
		<tr>
			<th scope="row" style="text-align: center; width: 75px;">성적</th>
			<td style="text-align: center; width: 50px;">A+</td>
			<td style="text-align: center; width: 50px;">A0</td>
			<td style="text-align: center; width: 50px;">B+</td>
			<td style="text-align: center; width: 50px;">B0</td>
			<td style="text-align: center; width: 50px;">C+</td>
			<td style="text-align: center; width: 50px;">C0</td>
			<td style="text-align: center; width: 50px;">D+</td>
			<td style="text-align: center; width: 50px;">D0</td>
			<td style="text-align: center; width: 50px;">F</td>
		</tr>
		<tr>
			<th scope="row" style="text-align: center; width: 75px;">평점</th>
			<td style="text-align: center; width: 50px;">4.50</td>
			<td style="text-align: center; width: 50px;">4.00</td>
			<td style="text-align: center; width: 50px;">3.50</td>
			<td style="text-align: center; width: 50px;">3.00</td>
			<td style="text-align: center; width: 50px;">2.50</td>
			<td style="text-align: center; width: 50px;">2.00</td>
			<td style="text-align: center; width: 50px;">1.50</td>
			<td style="text-align: center; width: 50px;">1.00</td>
			<td style="text-align: center; width: 50px;">0.00</td>
		</tr>
	</tbody>
</table>
</div>

<p>이번 학기의 평균 평점은 $($과목별 $($학점 $\times$ 평점$)$의 합 $\div$ 이번 학기에 수강한 과목의 학점 총합$)$을 소수점 이하 세 번째 자리에서 버림한 값이며, 이번 학기의 평균 평점이 최소 평균 평점 기준을 <strong>초과</strong>하는 경우 최소 평균 평점 기준을 충족한 것으로 인정된다. <strong>단, 실수 자료형을 사용할 경우 부동 소수점 오차가 발생할 수 있으므로 주의하라.</strong></p>

### 입력 

 <p>첫 번째 줄에 이번 학기에 수강한 과목 수 $N$과 이번 학기에 받아야 하는 최소 평균 평점 기준 $X$가 공백으로 구분되어 주어진다. $(2 \le N \le 24;$ $0.00 \le X \le 4.50;$ $X$는 소수점 이하 두 자리까지 주어지는 실수$)$</p>

<p>두 번째 줄부터 $N - 1$개의 줄에 걸쳐 각 과목의 학점 $c_i$와 성적 $g_i$가 공백으로 구분되어 주어진다. $(1 \le c_i \le 6;$ $g_i$는 <span style="color:#e74c3c;"><code>A+</code></span>, <span style="color:#e74c3c;"><code>A0</code></span>, <span style="color:#e74c3c;"><code>B+</code></span>, <span style="color:#e74c3c;"><code>B0</code></span>, <span style="color:#e74c3c;"><code>C+</code></span>, <span style="color:#e74c3c;"><code>C0</code></span>, <span style="color:#e74c3c;"><code>D+</code></span>, <span style="color:#e74c3c;"><code>D0</code></span>, <span style="color:#e74c3c;"><code>F</code></span>중 하나$)$</p>

<p>그다음 줄에는 나머지 한 과목의 학점 $L$이 주어진다. $(1 \le L\le 6)$</p>

### 출력 

 <p>최소 평균 평점 기준을 충족하기 위해 받아야 하는 나머지 한 과목의 최소 성적을 출력한다. 만약 어떤 성적을 받아도 최소 평균 평점 기준을 충족할 수 없다면 "<span style="color:#e74c3c;"><code>impossible</code></span>"을 출력한다.</p>

