/*

Copyright 2026 Jared Robert Wright

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

/*

This query is written for PostgreSQL and will likely fail in other database engines.
This was tested to work on the actual database but LeetCode won't run it

*/

CREATE OR REPLACE FUNCTION Top3EarnersByDepartment() RETURNS TABLE (Department VARCHAR(255), Employee VARCHAR(255), Salary INT) LANGUAGE plpgsql AS $$
BEGIN
	DECLARE
	   	DeptId INT;
    	EmpSalary INT;
    	SalaryCount INT;
    	DeptName VARCHAR(255);
    	EmpName VARCHAR(255);
	BEGIN
    	-- load temp table with departments
		DROP TABLE IF EXISTS dept;
		DROP TABLE IF EXISTS TopEarners;
    	CREATE TEMP TABLE dept AS SELECT * FROM Department;
   		CREATE TEMP TABLE TopEarners (Department VARCHAR(255), Employee VARCHAR(255), Salary INT);

    	WHILE EXISTS (SELECT * FROM dept) LOOP
        	-- get next department ID
        	SELECT id INTO DeptId FROM dept ORDER BY id ASC LIMIT 1;
        	-- get department name
        	SELECT name INTO DeptName FROM dept WHERE id = DeptId ORDER BY id ASC LIMIT 1;
        
        	-- loop through employee table to get top earners
        	-- start by setting salary count and highest department salary
        	SalaryCount := 0;
        	SELECT Employee.salary INTO EmpSalary FROM Employee WHERE departmentId = DeptId ORDER BY salary DESC LIMIT 1;

        	-- loop while we have entries to process
        	WHILE SalaryCount < 3  AND EXISTS (SELECT * FROM Employee WHERE Employee.departmentId = DeptId AND Employee.salary = EmpSalary) LOOP
            	CREATE TEMP TABLE tmp AS SELECT * FROM Employee WHERE Employee.departmentId = DeptId AND Employee.salary = EmpSalary;
            	INSERT INTO TopEarners (Department, Employee, Salary) SELECT DeptName, name, EmpSalary FROM tmp;
            	-- get next highest salary
            	SELECT Employee.salary INTO EmpSalary FROM Employee WHERE Employee.departmentId = DeptId AND Employee.salary < EmpSalary ORDER BY Employee.salary DESC LIMIT 1;
            	SalaryCount := SalaryCount + 1;
            	DROP TABLE tmp;
        	END LOOP;

        	-- remove current department from temp table
        	DELETE FROM dept WHERE id = DeptId;
    	END LOOP;

    	RETURN QUERY SELECT * FROM TopEarners;
	END;
END $$;

SELECT Top3EarnersByDepartment();