/*
    &   둘 다 true일 때 true, 나머지 false
    |   하나라도 true일 때 true, 나머지 false
    ^   두 피연산자가 같으면 false, 나머지 true
    ~   피연산자의 비트를 모두 반전

    1) idx번째 비트 끄기
        S = S & ~(1 << idx)

    2) idx번째 비트 XOR 연산
        S = S ^ (1 << idx)

    3) 최하위 켜져있는 비트 찾기
        idx = S & -S = S & ~(S+1)

    4) 크기가 n인 집합의 모든 비트 켜기
        (1 << n) - 1

    5) idx번째 비트 켜기
        S = S | (1 << idx)

    6) idx번째 비트가 켜져있는지 확인
        if (S & (1 << idx))
*/