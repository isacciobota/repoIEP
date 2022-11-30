#include <iostream>
#include <memory>

using namespace std;

class Uncopyable {
    protected: // allow construction
        Uncopyable() {} // and destruction of
        ~Uncopyable() {} // derived objects...
    private:
        Uncopyable(const Uncopyable&); // ...but prevent copying        
        Uncopyable& operator=(const Uncopyable&);
};

class Student{       
  private:                     
    string nume;
    int an;
    int nrCredite;

  public:  
    Student(){ //Default constructor
        nume = "newStudent";
        an = 1;
        nrCredite = 0;
    }   
    ~Student(){ //Destructor
        cout<< nume << " was removed\n";
    }

    Student(const Student& s) //Copy constructor
    {
        nume = s.nume;
        an = s.an;
        nrCredite = s.nrCredite;
    }

    Student(string nume, int an, int nrCredite) //Constructor
       :nume(nume),
        an(an),
        nrCredite(nrCredite)
    {}

    Student& operator=(const Student& rhs){ //assignment operators return a reference to *this
        if(this == &rhs) 
            return *this;
        nume = rhs.nume;
        an = rhs.an;
        nrCredite = rhs.nrCredite;
        return *this;
    }

    void afisareCredite(){
        cout<< nume <<": "<< nrCredite <<" credite\n";
    }

    void setNume(string nume){
        this->nume = nume;
    }

    string getNume(){
        return nume;
    }

};

// Resource managing class (item 14)
class SchimbExperienta: private Uncopyable{ //Prohibit copying
    private:
        Student *student;    
    public:
        SchimbExperienta(Student *student)
            :student(student)
        {
            cout<<student->getNume()<<" a venit in schimb de experienta\n"; 
        } // acquire resource
        
        ~SchimbExperienta(){ 
             cout<<student->getNume()<<" was deleted\n"; 
        } // release resource
};

void schimbExperienta(Student *student){
    SchimbExperienta s(student);
}

Student* createStudent(){
    return (new Student);
}

class EchipaProiect{
    private:
        string nume;
        Student *student1;
        Student *student2;
    public:
        EchipaProiect(){ // Default Constructor
            nume = "echipaDefault";
            student1 = new Student();
            student2 = new Student();
        }

        EchipaProiect(string nume, Student *student1, Student *student2) // Constructor
           :nume(nume),
            student1(student1),
            student2(student2)
        {}

        ~EchipaProiect(){ //Destructor
            delete student1;
            delete student2;
            cout<< nume << " was removed\n";
        }   

        EchipaProiect(const EchipaProiect& s) //Copy constructor
        {
            nume = s.nume;
            student1 = s.student1;
            student2 = s.student2;
        }

        EchipaProiect& operator=(const EchipaProiect& rhs){ //assignment operators return a reference to *this
            auto_ptr<Student> student1Orig(student1); //Item 13 resource management
            auto_ptr<Student> student2Orig(student2); //Item 13 resource management
            student1 = rhs.student1;
            student2 = rhs.student2;
            nume = rhs.nume;
            return *this;
        }

    void afisareMembrii(){
        cout<< nume << ": "<< (*student1).getNume() << ", " << (*student2).getNume() << "\n";
    }

};

int main()
{
    Student student1("Andrei", 1, 56);
    Student student2("Isac", 4, 60);

    EchipaProiect echipa1("Echipa 1", &student1, &student2);
    EchipaProiect echipa2 = echipa1; //used the copy assignment operator successfully

    echipa1.afisareMembrii();
    echipa2.afisareMembrii();
    cout<<"\n";

    cout<<"Using auto_ptr:\n";
    auto_ptr<Student> student3(createStudent());
    student3->setNume("studentAutoPtr");
    cout<<student3->getNume()<<'\n';
    auto_ptr<Student> student4(student3);
    //cout<<student3->getNume()<<'\n'; 
                    // not working because auto_ptrs has an unusual 
                    // characteristic: copying them (via copy constructor or copy assignment operator) sets them to null
    cout<<student4->getNume()<<'\n';

    cout<<"\nUsing shared_ptr:\n";
    shared_ptr<Student> student5(createStudent());
    student5->setNume("studentSharedPtr");
    cout<<student5->getNume()<<'\n';
    shared_ptr<Student> student6(student5);
    cout<<student5->getNume()<<'\n'; 
    cout<<student6->getNume()<<'\n';

    cout<<"\n";
    Student student7("Bob", 2, 30);
    schimbExperienta(&student7);
    
    cout<<"\nDestructors:\n";
    return 0;
}