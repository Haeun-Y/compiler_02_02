## functions
* **void ComputeHS(int nid, int nfree)** : ST[nid]부터 ST[nfree-1]까지의 문자들이 이루는 문자열의 hashcode 값을 계산하는 함수, hashcode를 반환할지 결정해야함
* **void LookupHS(int nid, int hscode)** : ST[nid]부터 시작되는 문자열, 즉 현재 해시테이블에 넣고자하는 문자열과 동일한 문자열이 이미 해시테이블에 존재하는지 확인하는 함수

</br>

## ErrorType
* enum errorTypes { noerror, illid, overst };
</br>

## 역할 분담
* 진주 : SkipSeperators, PrintHStable 함수 작성
* 영경 : PrintError, ReadID 함수 작성
* 하은 : ComputeHS, LookupHS 함수 작성
* 예원 : ADDHT 함수 작성 및 3/20 회의록 작성

</br>

## 과제 일정
* [ ] [3/20] 실습1
* [ ] [3/20 ~ 3/23] 역할 분담한 함수 작성
* [ ] [3/23] 메인함수 작성 및 전체 코드 정리
* [ ] [3/27] 실습2 및 과제 제출본 정리



</br>

## 참고
*  대소문자 구분
*  어떤 함수에서 대소문자 구분해야할지 ->  hashcode 계산시
*  에러처리
*  각 함수에서 단계별로 처리된 결과를 그 다음 단계함수에서 어떻게 활용하나?

