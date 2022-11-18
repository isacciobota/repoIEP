#include <iostream>

using namespace std;

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

    string getNume(){
        return nume;
    }

};

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
            Student *student1Orig = student1;
            Student *student2Orig = student2;
            student1 = rhs.student1;
            student2 = rhs.student2;
            delete student1Orig;
            delete student2Orig;
            nume = rhs.nume;
            return *this;
        }

    void afisareMembrii(){
        cout<< nume << ": "<< (*student1).getNume() << ", " << (*student2).getNume() << "\n\n";
    }

};

int main()
{
    Student student1("Andrei", 1, 56);
    Student student2("Isac", 4, 60);

    EchipaProiect echipa1("Echipa 1", &student1, &student2);

    echipa1.afisareMembrii();

    return 0;
}