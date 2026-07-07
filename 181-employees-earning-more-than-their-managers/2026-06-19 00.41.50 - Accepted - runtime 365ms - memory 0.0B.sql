# Write your MySQL query statement below
select a.name as Employee
from Employee as a
left join Employee as b
on a.managerId = b.Id
where a.salary > b.salary;