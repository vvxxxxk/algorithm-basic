# algorithm-basic

<details>
<summary> 기초 코드 작성요령 </summary>

* O(1) < O(logN) < O(N) < O(NlogN) < O(N^2) < O(2^n) < O(N!)

* 항상 타입 범위에 맞게 사용 (Integer Overflow)

* 실수는 저장/연산 과정에서 반드시 오차가 발생

* 실수를 비교할 때는 등호를 사용하면 안됨

* 배열은 주소값을 넘겨 원본에 영향을 줄 수 있지만 , 구조체와 STL(vector 등) 또한 함수 인자로 사용 시 값 복사가 일어나 원본에 영향 없음

* 공백이 포함된 문자열을 받으려면 scanf, cin을 사용하지 말 것. 아래 구문 사용
```bash
string s;
getline(cin, s);
cout << s;
```

* cout/cin 사용 시 아래 세 줄 작성할 것
```bash
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

* 줄 바꿈 시 endl 사용하지 말 것. 차라리 개행 문자를 사용

* 출력 맨 마지막에 공백 혹은 줄바꿈이 추가로 있어도 정답 처리
  
</details>

<details>
<summary> 출처 </summary>

blog: https://blog.encrypted.gg/

github: https://github.com/encrypted-def

youtube: https://www.youtube.com/@BaaaaaaaaaaaaaaaaaaaaarkingDog

</details>
