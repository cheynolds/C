// Structs
#include <stdio.h>
#include <string.h>

// Structs - structures, are a collection of variables. A struct is a derived type

struct student 
{
	char name[20];
	char grade;
};

struct car
{
	char name[20];
	char type;
	float tankSize;
	struct student passenger;
};

// the derived type is student, we can now create identifiers of the student type
// just like we can create an identifier of the int type

// Prototypes
void print(struct student s);
void load(struct student s);
void loadStudent(struct student *s);
void printCar(struct car c);
void loadCar(struct car *c);

void initStruct();
void structPointers();
void structParams();
void moreStructs();
void print(struct student s);
void load(struct student s);
void loadStudent(struct student *s);
void printCar(struct car c);
void loadCar(struct car *c);

int main (void)
{
	// structs behave in a simliar fashion to other types
	// they are declared the same way
	struct student aStudent;
	char myGrade;
	char myName[20];

	myGrade = 'A';
	strcpy(myName, "Test");

	// accessing a struct is simliar to other variables, except
	// now there are multiple parts to access, what we do is qualify
	// the variable by saying aStudent, then use the dot operator '.'
	// to specify which part of the student we are going to look at
	aStudent.grade = 'A';
	strcpy(aStudent.name, "Steve");

	printf("Our student is %s, their grade is %c, the ref is %x %x\n", 
		aStudent.name, aStudent.grade, aStudent, &aStudent);
	printf("Our student is %s, their grade is %c, the ref is %x %x\n", 
		aStudent.name, aStudent.grade, &aStudent, aStudent);
	printf("Data at aStudent is %d", aStudent);
	
	initStruct();
	structPointers();
	structParams();
	moreStructs();

	return 0;
}

void initStruct()
{
	// Initializing structs
	struct student fred = { "Fred", 'B' };
	print(fred);
}

void structPointers()
{
	// Pointers and structures

	struct student fred = { "Fred", 'B' };
	struct student *pStudent;
	pStudent = &fred;

	// normally when we want to access the value of a pointer, we dereference it
	// To do that we use the star operator *, however, because operators have
	// different precedence, we need to force the * to have a higher precedence
	// than the . operator, so () will do that for us
	printf("Name: %s\t Grade: %c\n", 
		(*pStudent).name, (*pStudent).grade);

	// That is a bit cumbersome, so there is another way to do it, with the arrow
	// operator ->
	// We use it in lieu of the dot operator
	printf("Name: %s\t Grade: %c\n", pStudent->name, pStudent->grade);

	// broken version
	/*printf("Name: %s\t Grade: %c\n", 
		*pStudent.name, *pStudent.grade);*/
}

void structParams()
{
	// structs as parameters
	struct student parameter = { "", '\0' };
	printf("parameter mem address: %x", &parameter);
	load(parameter);
	print(parameter);

	// notice that we don't get anything back
	loadStudent(&parameter);
	print(parameter);
}

void moreStructs()
{
	struct car oldsmobile = { "", '\0', 0.0 };
	struct car oldsmobile1={"",'\0',0.0};
	struct car toyota;
	struct student students[2] = { {"Abe", 'C'}, {"Joe", 'D' } };
	int i;

	for (i = 0; i < 2; i++)
		print(students[i]);

	oldsmobile.passenger.grade = 'A';
	//oldsmobile.passenger = 'A';
	strcpy(oldsmobile.passenger.name, "New Guy");
	oldsmobile.passenger.name[0] = 'T';
	strcpy(oldsmobile.name, "Some Car");
	oldsmobile.tankSize = 24.2f;
	oldsmobile.type = 'S';
	print (oldsmobile.passenger);
	printCar (oldsmobile);

	loadCar(&toyota);
	printCar(toyota);

	printf("Oldsmobile address is %x\n", &oldsmobile);
	printf("Type address is %x\n", &oldsmobile.type);
	printf("Tank address is %x\n", &oldsmobile.tankSize);
	printf("Address of student in the ols is %x\n", &oldsmobile.passenger);	
	printf("Address of student.name in the ols is %x\n", &oldsmobile.passenger.name);
	printf("Address of student.grade in the ols is %x\n", &oldsmobile.passenger.grade);
	//loadStudent(&oldsmobile.&passenger);
	loadStudent(&oldsmobile.passenger);
}

void print(struct student s)
{
	printf("Our student is %s, their grade is %c, the ref is %d\n", 
		s.name, s.grade, s);
	printf("parameter mem address: %x\n", &s);
}

void load(struct student s)
{
	s.grade = 'F';
	strcpy(s.name, "Initial");
	printf("parameter mem address: %x\n", &s);
	print(s);
}

void loadStudent(struct student *s)
{
	s->grade = 'F';
	strcpy(s->name, "Initial");
}

void printCar(struct car c)
{
	printf ("Name: %s\n", c.name);
	printf ("Type: %c\n", c.type);
	printf ("Tank: %lf\n", c.tankSize);
	print (c.passenger);
}

void loadCar(struct car *c)
{
	strcpy(c->name, "Loaded Name");
	c->type = 'S';
	printf("How many gallons: ");
	scanf("%f", &c->tankSize);
	loadStudent(&c->passenger);
}
