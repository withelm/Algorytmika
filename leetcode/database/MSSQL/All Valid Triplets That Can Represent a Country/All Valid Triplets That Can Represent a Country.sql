/* Write your T-SQL query statement below */
select
    A.student_name as member_A,
    B.student_name as member_B,
    C.student_name AS member_C
from
    SchoolA as A
    left join SchoolB as B on A.student_name <> B.student_name
    left join SchoolC as C on A.student_name <> C.student_name
    and B.student_name <> C.student_name
where
    A.student_id <> B.student_id
    and C.student_id <> B.student_id
    and A.student_id <> C.student_id
group by
    A.student_name,
    B.student_name,
    C.student_name