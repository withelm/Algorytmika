/* Write your T-SQL query statement below */
select
    top 1 question_id as survey_log
from
    survey_log
where
    action = 'answer'
group by
    question_id
order by
    count(1) desc