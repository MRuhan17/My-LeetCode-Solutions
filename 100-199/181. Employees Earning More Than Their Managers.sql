SELECT e1.name as Employee from employee e1 join employee e2 on e1.managerId = e2.Id and e1.salary > e2.salary;
