#include <iostream>
#include <string>   
#include <chrono>
#include <ctime>  
#include <string.h>

using  namespace std; 
class Activitate
{
    protected:
        unsigned nr_reprize;
        unsigned nr_min_per_repriza;
        string nume_sport;
    public:
    Activitate(const string& nume_sport, unsigned nr_reprize, unsigned nr_min_per_repriza):
        nr_reprize(nr_reprize), nr_min_per_repriza(nr_min_per_repriza), nume_sport(nume_sport)
    {
        cout<<"S-a folosit constructorul din CLASA DE BAZA"<<endl;
        cout<<"Nume sport : "<<this->nume_sport<<endl;
        cout<<"Nr reprize: "<<this->nr_reprize<<" de cate "<<this->nr_min_per_repriza<<" minute"<<endl<<endl;
    }

    Activitate(const Activitate& act):
        nr_reprize(act.nr_reprize), nr_min_per_repriza(act.nr_min_per_repriza), nume_sport(act.nume_sport)
    {
        cout<<"S-a folosit COPY CONSTRUCTORUL din CLASA DE BAZA"<<endl;
    }
    //Activitate(const Activitate& act)= delete;

    Activitate(Activitate&& act):
        nr_reprize(act.nr_reprize), nr_min_per_repriza(act.nr_min_per_repriza), nume_sport(act.nume_sport)
    {
        cout<<"S-a folosit MOVE CONSTRUCTORUL din CLASA DE BAZA"<<endl;
    }

    //Activitate(Activitate&& act)= delete;

    unsigned getNr_reprize() const
    {
        return nr_reprize;
    }

    unsigned getNr_min_per_repriza() const
    {
        return nr_min_per_repriza;
    }

    string getNume_sport() const
    {
        return nume_sport;
    }
    void setNr_reprize(unsigned repriza)
    {
        if(repriza >0)
            nr_reprize=repriza;
        cout<<"Setter aplicat!\n";
    }

    void setNr_min_per_repriza(unsigned min)
    {
        if(min >0)
            nr_min_per_repriza=min;
        cout<<"Setter aplicat!\n";
    }

    void setNume_sport(string sport)
    {
        nume_sport=sport;
        cout<<"Setter aplicat!\n";
    }
    void print_detalii()
    {
        cout<<"Activitatea este "<<nume_sport<<" si dureaza "<<nr_reprize<<" reprize a cate "<<nr_min_per_repriza<<" minute"<<endl<<endl;
    }

    ~Activitate()
   {
        cout<<"S-a apelat destructorul din CLASA DE BAZA"<<endl;
        print_detalii();
   }
};
class Meci: public Activitate{
    private:
        
        string echipa1;
        string echipa2;

    public:
    Meci (unsigned nr_reprize, unsigned nr_min_per_repriza, const string& nume_sport, const string& echipa1, const string& echipa2): 
        Activitate( nume_sport, nr_reprize, nr_min_per_repriza),echipa1(echipa1), echipa2(echipa2)
    {
        cout<<"Am folosit constructorul din SUBCLASA\n";
        cout<<"Nume sport : "<<this->nume_sport<<"\n";
        cout<<"Meciul are "<<this->nr_reprize<<" reprize a cate "<<this->nr_min_per_repriza<<" minute\n";
        cout<<this->echipa1<<" - "<<this->echipa2<<endl<<endl;
    }

    Meci (const Meci& meci):
        Activitate(meci), echipa1(meci.echipa1), echipa2(meci.echipa2)
    {
        cout<<"S-a apelat COPY CONSTRUCTOR din SUBCLASA"<<endl;
    }
    //Meci (const Meci& meci)= delete;
    
    Meci (Meci&& meci):
        Activitate(move(meci)), echipa1(meci.echipa1), echipa2(meci.echipa2)
    {
        cout<<"S-a apelat MOVE CONSTRUCTOR din SUBCLASA"<<endl;
    }
    //Meci (Meci&& meci)= delete;

    string getEchipa1() const
    {
        return echipa1;
    }

    string getEchipa2() const
    {
        return echipa2;
    }

    void setEchipa1(string echipa)
    {
        echipa1=echipa;
        cout<<"Setter aplicat!\n";
    }

    void setEchipa2(string echipa)
    {
        echipa2=echipa;
        cout<<"Setter aplicat!\n";
    }

    int minute_meci(string sport)
    {
        if(sport=="baschet")
            return 40;
        if(sport=="fotbal")
            return 90;
        if(sport=="handbal")
            return 60;
        return 0;
    }
    int minute_meci()
    {
        return nr_reprize*nr_min_per_repriza;
    }
    void print_detalii()
    {
        Activitate::print_detalii();
        cout<<"Meciul: "<<echipa1<<" - "<<echipa2<<endl<<endl;
    }
    

   Meci& operator=(const Meci& m); 
   
   ~Meci()
   {
    cout<<"S-a apelat destructorul din SUBCLASA"<<endl;
    print_detalii();
   }

};

Meci& Meci::operator=(const Meci& m)
{
    printf("aici\n");
    nr_min_per_repriza=m.nr_min_per_repriza;
    nr_reprize=m.nr_reprize;
    nume_sport=m.nume_sport;
    echipa1=m.echipa1;
    echipa2=m.echipa2;
    return *this;
}

int main()
{
    int folosire_egal=0;
    Meci* meci1 = new Meci(1, 10, "baschet", "Poli", "UVT");
    Meci* meci2 = new Meci(2, 10, "baschet", "Arad", "Iasi");
    Activitate* act1 = new Activitate("baschet", 11, 10);
    Activitate* act2 = new Meci(22,45, "fotbal", "City", "United");
    //act2->print_detalii();
    Meci meci4 = Meci(44,45, "fotbal", "Real", "Barca");
    Meci meci3 = meci4;
    meci3.print_detalii();

    Meci meci5 = Meci(55, 30, "handbal", "Gyor", "CSM");
    Meci meci6 = std::move(meci5);
    //meci1->print_detalii_meci();
    //meci2->print_detalii_meci();

    // meci1->setEchipa1("Partizan");
    // meci1->setEchipa2("Barcelona");
    // meci1->setNume_sport("baschet");
    // meci1->setNr_min_per_repriza(10);
    // meci1->setNr_reprize(4);

    // meci1->print_detalii();
    
    // printf("Meciul dureaza %d minute\n", meci1->minute_meci());
    // printf("Meciul dureaza %d minute\n", meci1->minute_meci("baschet"));

    // meci1->print_detalii();
    // meci2->print_detalii();
    // *meci1=*meci2;
    // folosire_egal=1;

    // meci1->print_detalii_meci();
    // meci2->print_detalii_meci();
    if(folosire_egal==1)
    {
        delete meci1;
    }
    else
    {
        delete meci1;
        delete meci2;
    }
    delete act1;
    delete act2;
    return 0;
}   