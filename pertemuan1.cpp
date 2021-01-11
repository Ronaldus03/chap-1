#include<stdio.h>
#include<string.h>
#include<stdlib.h> // dynamic memeory allocation

struct course{
    char ID[10]; //10 byte
    int score; // 4 byete
};

struct student{
    char name[255]; //255 byete
    double gpa; // 8 byete
    course c; //object course
};

//const char hanya untun string

student *createstudent(const char *name, double gpa,const char *ID, int score){
    //alokasi memory allocation

    student *newstudent = (student*)malloc(sizeof(student));
    strcpy(newstudent->name, name);

    // (*newstudent).atributnya sama ja dengan newstudent -> atributnya

     newstudent->gpa = gpa;
     strcpy(newstudent ->c.ID, ID);
     newstudent->c.score = score;   

    return newstudent;
}
//tipe data yang di return : student*
//nama function: create student
//paramter : nama,gpa,course,

void removestudent(student *s){
    free(s);
    s = NULL;
}

void printstudent(student *s){
    printf("Name: %s\n",s->name);
    printf("GPA : %.2lf\n", s->gpa);
    printf("Couse ID: %s\n",s->c.ID);
    printf("Score : %d\n", s->c.score);
}
    
int main(){
    // student students[10]; // statc memeory allocation

   student *s1 = createstudent("ronald", 4.90,"LN01",100);
    printstudent(s1);
    removestudent(s1);
    printf("After remove\n");
    printstudent(s1);
    return 0;
}