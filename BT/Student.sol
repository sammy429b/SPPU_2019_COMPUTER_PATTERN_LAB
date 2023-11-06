// SPDX-License-Identifier: GPL 3.0
pragma solidity ^0.8.0;
    contract StudentData {
        struct Student {
            uint256 studentID;
            string name;
            uint256 age;
        }

        Student[] public students; // Array of students
        
        // Add a new student
        function addStudent(uint256 _studentID, string memory _name, uint256 _age) public {
            Student memory newStudent = Student(_studentID, _name, _age);
            students.push(newStudent);
        }
        
        // Get the total number of students
        function getStudentCount() public view returns (uint256) {
            return students.length;
        }

        // Get student details by index
        function getStudentById(uint256 id) public view returns (uint256, string memory, uint256) {
            for (uint i = 0; i < students.length; i++){
                if(students[i].studentID == id){
                Student memory student = students[i];
                return (student.studentID, student.name, student.age);
                }   
        }
        
        Student memory nstudent = Student(0 , "NULL", 0);
            return (nstudent.studentID,nstudent.name,nstudent.age);
        }
}