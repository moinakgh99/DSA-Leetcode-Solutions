# Write your MySQL query statement below

-- select email as Email
-- from Person
-- group by email
-- having count(*) > 1;

select distinct a.email as Email
from Person as a
join Person as b
on a.email = b.email
and a.id <> b.id;