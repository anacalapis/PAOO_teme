#include <iostream>
#include <string>   
#include <chrono>
#include <ctime>  
#include <string.h>

using  namespace std;
class Meci{
    private:
        unsigned nr_reprize;
        unsigned nr_min_per_repriza;
        string nume_sport;
        string echipa1;
        string echipa2;

    public:
    Meci (unsigned nr_repriza, unsigned nr_min_per_repriza, const string& nume_sport, const string& echipa1, const string& echipa2): 
        nr_reprize(nr_repriza), nr_min_per_repriza(nr_min_per_repriza), nume_sport(nume_sport), echipa1(echipa1), echipa2(echipa2)
    {
        cout <<"Am folosit constructorul corect cu o lista de initializare \n"; 
    }

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

    string getEchipa1() const
    {
        return echipa1;
    }

    string getEchipa2() const
    {
        return echipa2;
    }

    void setNr_reprize(unsigned repriza)
    {
        if(repriza >0)
            nr_reprize=repriza;
    }

    void setNr_min_per_repriza(unsigned min)
    {
        if(min >0)
            nr_min_per_repriza=min;
    }

    void setNume_sport(string sport)
    {
        nume_sport=sport;
    }

    void setEchipa1(string echipa)
    {
        echipa1=echipa;
    }

    void setEchipa2(string echipa)
    {
        echipa2=echipa;
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
    void print_detalii_meci()
    {
        cout<<"Meciul de "<<nume_sport<<" dintre echipele "<<echipa1<<" si "<<echipa2<<" este alcatuit din "<<nr_reprize<<" reprize a cate "<<nr_min_per_repriza<<" minute"<<endl;
    }

   Meci operator=(Meci m); 
   
   ~Meci()
   {
    cout<<"S-a apelat destructorul"<<endl;
   }

};

Meci Meci::operator=(Meci m)
{
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
    Meci* meci1 = new Meci(4, 10, "baschet", "Poli", "UVT");
    Meci* meci2 = new Meci(4, 10, "baschet", "Arad", "Iasi");
    meci1->print_detalii_meci();
    meci2->print_detalii_meci();
    
    printf("Meciul dureaza %d minute\n", meci1->minute_meci());
    printf("Meciul dureaza %d minute\n", meci1->minute_meci("fotbal"));

    meci1=meci2;
    folosire_egal=1;

    meci1->print_detalii_meci();
    meci2->print_detalii_meci();
    if(folosire_egal==1)
    {
        delete meci1;
    }
    else
    {
        delete meci1;
        delete meci2;
    }
    
    return 0;
}   