# Write your MySQL query statement below
select b.name as Department,
a.name as Employee,
a.salary as Salary
from Employee as a
left join Department as b
on a.departmentId = b.id
where a.salary = (
    select max(salary)
    from Employee
    where departmentId = a.departmentId
);