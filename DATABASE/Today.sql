select * from instructor;

/* question 4 */
select dept_name,count(*) as numofins from instructor group by dept_name order by numofins desc ;

/* question 5 */
select d.dept_name,count(i.id) as numofins from department d left outer join instructor i on  d.dept_name=i.dept_name group by d.dept_name
insert into department values ('cs','1',1000)


select * from takes;

/* question 6 */
select t.id,sum(c.credits) from takes t,course c where c.course_id=t.course_id and (t.grade != 'F' or t.grade != NULL)  group by t.id;

/* question 7 */
select distinct student.name from instructor i,teaches t,student,takes where i.name = 'Srinivasan' and i.id = t.id and t.course_id = takes.course_id and takes.id = student.id  ;

/* question 8 */
select max(i.salary),i.dept_name from instructor i,department d where i.dept_name = d.dept_name;
