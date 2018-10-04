select * from instructor

create table instrcutor_audit(id char(5) NOT NULL,entry_date TEXT NOT NULL);

create or replace function auditlogfunc() returns trigger as $example$
begin
insert into instrcutor_audit(id,entry_date) values(new.id,current_timestamp);
return NEW;
end


$example$ LANGUAGE plpgsql 


select * from instructor

/* create trigger example_trigger after insert on instructor for each row execute procedure auditlogfunc(); */ 

create trigger e1 after insert on instructor for each row execute procedure auditlogfunc(); 

INSERT into instructor values('20112','Aparna','Music',80000);

create table instructor_sal_raise( id char(5),name char(20),dept_name char(20),salary numeric(8,2),changed_on timestamp(6) NOT NULL)

create function log_sal_change1() returns trigger as $example_table$
BEGIN
IF NEW.salary<>OLD.salary THEN
insert into instructor_sal_raise(id,name,dept_name,salary,changed_on) values(OLD.id,OLD.name,OLD.dept_name,OLD.salary,now());
END IF;
RETURN NEW;
END;
$example_table$ LANGUAGE plpgsql;

create trigger last_sal_changes1
before update on instructor
for each row
execute procedure log_sal_change1()

select * from instructor;

update instructor set salary=30000 , dept_name = 'Biology' where id='10101'

select * from instructor_sal_raise

select * from pg_trigger


/* STUDENT TRIGGER */
create table student_update(id char(5) NOT NULL,entry_date TEXT NOT NULL,old_dept TEXT NOT NULL,new_dept TEXT NOT NULL );

drop trigger last_dept_change on student 
drop table student_update

/* new funcion */
create or replace function Studentlogfunc() returns trigger as $example$
begin
if new.dept_name<>old.dept_name then
begin
print old.dept_name,new.dept_name;
insert into student_update(id,entry_date,old_dept,new_dept) values(old.id,current_timestamp,old.dept_name,new.dept_name);
end
end if;
return NEW;
end;
$example$ LANGUAGE plpgsql



create trigger last_dept_change
before update on student 
for each row
execute procedure Studentlogfunc()

update student set dept_name = 'CS' where id='00128';
select * from student
select * from student_update;
