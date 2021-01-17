/* Write your T-SQL query statement below */
select
    *
from
    Users
where
    LOWER(mail) REGEXP '^[a-z][0-9a-z_.-]{0,1000}@leetcode.com$'