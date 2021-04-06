/* Write your T-SQL query statement below */
WITH A AS(
    SELECT
        task_id,
        subtasks_count,
        1 AS subtask_id
    FROM
        Tasks
    UNION
    ALL
    SELECT
        A.task_id,
        subtasks_count,
        subtask_id + 1
    FROM
        A
    WHERE
        subtask_id < subtasks_count
)
select
    A.task_id,
    A.subtask_id
from
    A
    left join Executed on Executed.task_id = A.task_id
    and Executed.subtask_id = A.subtask_id
where
    Executed.task_id is NULL