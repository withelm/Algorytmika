/* Write your T-SQL query statement below */
select
    top (1) Name
from
    Vote as v
    left join Candidate as c on v.CandidateId = c.Id
group by
    Name
order by
    count(1) desc