SELECT PT_NAME, PT_NO, GEND_CD, AGE, IFNULL(TLNO,'NONE') AS TLNO
FROM PATIENT
WHERE AGE<=12 AND GEND_CD = 'W'
ORDER BY AGE DESC, PT_NAME

/*
 1.  null 값이 포함 될 경우 다른 값으로 대체하는 방법 
    -> ifnull(abc,'replaced') as abc
 2. 2개 이상의 기준으로 정렬 방법 
    -> ORDER BY AGE DESC, PT_NAME
*/

