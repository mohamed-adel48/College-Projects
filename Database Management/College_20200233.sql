/* Mohamed Adel/20200233 - Kerolos Atef/20200150 */

create database College
use College
Create table Professor
(
Prof_id int primary key identity (100,1)  Not Null ,
prof_name varchar (25) ,
prof_email varchar (35) ,
Department_code int,

)


/* Professor Table */
Insert into Professor Values ('Mohamed Ali','Mohamed.ali@cic-cairo.com','5')
Insert into Professor Values ('Mohamed Abdelhakem','Mohamed.ahmed@cic-cairo.com','1')
Insert into Professor Values ('Shehab Kandil','Shehab.Kandil@cic-cairo.com','1')
Insert into Professor Values ('Dalia Magdi','Dalia.Magdi@cic-cairo.com','6')
Insert into Professor Values ('Nagwa Yaseen','Nagwa.Yaseen@cic-cairo.com','4')
Insert into Professor Values ('Maha Attia','Maha.Attia@cic-cairo.com','6')
Insert into Professor Values ('Dina Salem','Dina.Salem@cic-cairo.com','4')
Insert into Professor Values ('Mahmoud Salah','Mahmoud.Salah@cic-cairo.com','2')
Insert into Professor Values ('Neaam Mohey','Neaam.Mohey@cic-cairo.com','3')
Insert into Professor Values ('Aya Faheem','Aya.Faheem@cic-cairo.com','3')
---------------------------------------------------------------------------------------

Create table Department
(
Department_code int primary key identity (1,1) Not Null ,
Department_name varchar (25),
Prof_id int,
TA_id int,
)
/* Department Table */
Insert into Department  Values ('Math','100','200')
Insert into Department  Values ('Physics','101','201')
Insert into Department  Values ('English','102','202')
Insert into Department  Values ('Data Science','103','203')
Insert into Department  Values ('Electronics','104','204')
Insert into Department  Values ('game development','105','206')

---------------------------------------------------------------------------------------
Create table TA
(
TA_id int identity (200,1)  Not Null,
TA_name varchar (25),
TA_email varchar (35) ,
Department_code int foreign key references  Department (Department_code),
primary key (TA_id),

)

/* TA Table */
Insert into TA  Values ('Wesam Zorik','Wesam.Zorik@cic-cairo.com','1')
Insert into TA  Values ('Menna Tarek','Menna.Tarek@cic-cairo.com','5')
Insert into TA  Values ('Mustafa Mohamed','Mustafa.Mohamed@cic-cairo.com','1')
Insert into TA  Values ('Heba Salah','Heba.Salah@cic-cairo.com','2')
Insert into TA  Values ('Ahmed Abbas','Ahmed.Abbas@cic-cairo.com','1')
Insert into TA  Values ('Amena Mohamed','Amena.Mohamed@cic_cairo.com','2')
Insert into TA  Values ('Omnia Ayman','Omnia.Ayman@cic_cairo.com','5')
Insert into TA  Values ('Lamees.ahmed','Lamees.ahmed@cic_cairo.com','6')
Insert into TA  Values ('Rahma.mohamed','Rahma.mohamed@cic_cairo.com','4')
Insert into TA  Values ('Asmaa Ragab','Asmaa.Ragab@cic_cairo.com','2')

---------------------------------------------------------------------------------------

Create table Semester
(
Semester_num int identity (1,1) Not null,
Semester_year int,
Semester_term varchar (25),
Semester_Start_date date,
Semester_End_date date,
primary key (Semester_num)
)
/* Semester Table */
Insert into Semester Values ('2020','1st Term','9/28/2020','2/1/2021')
Insert into Semester Values ('2021','2nd Term','3/1/2021','7/1/2021')
Insert into Semester Values ('2021','3nd Term','9/28/2021','2/1/2022')
Insert into Semester Values ('2022','4nd Term','3/1/2022','7/1/2022')
Insert into Semester Values ('2022','5nd Term','9/28/2022','2/1/2023')
Insert into Semester Values ('2023','6nd Term','3/1/2023','7/1/2023')
Insert into Semester Values ('2023','7nd Term','9/28/2023','2/1/2024')
Insert into Semester Values ('2024','8nd Term','3/1/2024','7/1/2024')

---------------------------------------------------------------------------------------
Create table Building
(
Building_number int identity (1,1) not null,
Building_name varchar (25),
Building_Location varchar (25),
primary key (Building_number)
)

/* Building Table */
Insert into Building Values ('CS','tagamo3')
Insert into Building Values ('Mass Comm','tagamo3')
Insert into Building Values ('Business AD','Zayed')
Insert into Building Values ('Engineering','tagamo3')
Insert into Building Values ('Management','Zayed')
Insert into Building Values ('Business Tech','Zayed')

---------------------------------------------------------------------------------------
Create table Rooms
(
Room_number int not null,
Building_number int,
primary key (Room_number)
)
/* Room Table */
Insert into Rooms Values ('105','5')
Insert into Rooms Values ('106','3')
Insert into Rooms Values('205','6')
Insert into Rooms Values ('207','4')
Insert into Rooms Values ('307','1')
Insert into Rooms Values ('305','2')

---------------------------------------------------------------------------------------

Create table Course
(
Course_code int not null,
Course_name varchar (25),
Credit_Hours int,
Department_code int foreign key references  Department (Department_code),
primary key (Course_code)
)

/* Course Table */
Insert into Course Values('124','Electronics','3','5')
Insert into Course Values('150','CE2','2','3')
Insert into Course Values('170','CE1','2','3')
Insert into Course Values('186','Mathematics 2','4','1')
Insert into Course Values('220','Physics','4','2')
Insert into Course Values('224','C++','4','6')
Insert into Course Values('225','Discrete Mathematics','3','1')
Insert into Course Values('306','Database','4','4')
Insert into Course Values('410','Computer Ethics','3','4')

---------------------------------------------------------------------------------------

Create table Class
(
Class_code int identity (1,1) not null,
Class_name varchar (35),
Class_time TIME(7),
Prof_id int foreign key references Professor (Prof_id),
Course_code int,
Room_number int,
Semester_num int,
TA_id int foreign key references TA (TA_id),
 primary key (Class_code),
)
/* Class Table */
 
Insert into Class Values ('Period 1','08:00:00','100','410','106','1','200')
Insert into Class Values ('Period 2','09:00:00','101','150','105','1','201')
Insert into Class Values ('Period 3','10:00:00','102','170','207','2','202')
Insert into Class Values ('Period 4','11:00:00','103','124','307','2','203')
Insert into Class Values ('Period 5','12:00:00','104','224','307','3','204')
Insert into Class Values ('Period 6','01:00:00','105','225','305','3','205')
Insert into Class Values ('Period 7','02:00:00','106','306','205','4','206')
Insert into Class Values ('Period 8','03:00:00','107','220','106','4','207')
Insert into Class Values ('Period 9','04:00:00','108','186','205','5','208')

---------------------------------------------------------------------------------------
Create table Student 
(
Stu_id int identity (1,1) not null,
Stu_name varchar (25),
Gender Char(1),
birth_day date,
Stu_address varchar (25),
Department_code int foreign key references  Department (Department_code),
Prof_id int foreign key references Professor (Prof_id),
primary key (Stu_id),
)

/* Student Table */
Insert into Student Values ('Mohamed Adel','m','2002-08-04','Giza,6 October','1','100')
Insert into Student Values ('Kerolos Atef','m','2000-09-05','Shoubra','1','101')
Insert into Student Values ('Nour Allam','f','2002-01-09','El-Shoruk','2','102')
Insert into Student Values ('ismail Elhussein','m','2001-03-07','El-zamalek','4','102')
Insert into Student Values ('Salma Ahmed','f','2002-07-12','Nasr city','6','103')
Insert into Student Values ('Tasnim Ayman','f','2002-02-25','sheikh Zayed','5','105')
Insert into Student Values ('Mustafa Hamdy','m','2002-11-08','Qalyubia','2','104')
Insert into Student Values ('bassil haroun','m','2002-05-17','El-haram','3','100')
Insert into Student Values ('said afifi','m','2001-12-07','menoufia','4','107')
Insert into Student Values ('arwa ali','f','2000-07-24','El-fayoum','3','106')

---------------------------------------------------------------------------------------
/* Foreign keys*/

Alter table Professor 
add constraint FK_Department_code
Foreign key (Department_code)
references Department (Department_code)

Alter table Department
add constraint FK_Prof_id
Foreign key (Prof_id)
references Professor (Prof_id)

Alter table Department
add constraint FK_TA_id
Foreign key (TA_id)
references TA (TA_id)

Alter table Rooms
add constraint FK_Building_number
Foreign key (Building_number)
references Building (Building_number)

Alter table Class with nocheck
add constraint FK_Semester_num 
Foreign key (Semester_num )
references Semester (Semester_num )

Alter table Class with nocheck
add constraint FK_Room_number 
Foreign key (Room_number )
references Rooms (Room_number )

Alter table Class with nocheck
add constraint FK_Course_code 
Foreign key (Course_code )
references Course (Course_code )
---------------------------------------------------------------------------------------

select * From Student

Select Stu_id from Student where Stu_id between 2 and 8

Select Stu_name , birth_day from Student where Gender = 'm'

select * From Course 

select Course_code, Course_name from Course where Credit_Hours  = 3

select Building_name from Building where Building_Location = 'tagamo3'
---------------------------------------------------------------------------------------