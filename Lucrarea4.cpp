#include <iostream>

using namespace std;

class Uncopyable {
    protected: // allow construction
        Uncopyable() {} // and destruction of
        ~Uncopyable() {} // derived objects...
    private:
        Uncopyable(const Uncopyable&); // ...but prevent copying
        Uncopyable& operator=(const Uncopyable&);
};

class Student: private Uncopyable{       
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

    Student(string nume, int an, int nrCredite)
       :nume(nume),
        an(an),
        nrCredite(nrCredite)
    {}

    void afisareCredite(){
        cout<< nume <<": "<< nrCredite <<" credite\n";
    }

};

int main()
{
    Student student1("Andrei", 1, 56);
    Student student2("Isac", 4, 60);

    student1.afisareCredite();
    student2.afisareCredite();

    cout<<"\n";
    return 0;
}