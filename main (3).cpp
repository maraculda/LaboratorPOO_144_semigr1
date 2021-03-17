#include <iostream>

using namespace std;

class Nod{
    private:

    char info;
    Nod *next;

    public:
    Nod() {
        info='\0';
        next=NULL;
    }
    friend class Coada_de_caractere;
};

class Coada_de_caractere
{
    private:

    Nod *first_element;
    Nod *last_element;
    Nod *start;

    public:

   // int a[MAX]; //Marimea maxima a cozii
    Coada_de_caractere()
    {
        first_element=NULL;
        last_element=NULL;
        start=NULL;
    }
    Coada_de_caractere(Nod *first_element)
		{
			this->first_element = first_element;
		}

		Coada_de_caractere(Nod *first_element, Nod *last_element)
		{
			this->first_element = first_element;
			this->last_element = last_element;
		}

    void add_node(char n)
    {
        Nod *tmp = new Nod;
        tmp->info = n;
        tmp->next= NULL;

        if(first_element == NULL)
            {
                first_element= tmp;
                last_element = tmp;
            }
            else
            {
                last_element->next = tmp;
                last_element = last_element->next;
            }
    }

    void push(char);

	void pop();

	bool isEmpty();

    void display()
    {
        Nod *tmp;
        tmp = first_element;
        while (tmp != NULL)
        {
            cout << tmp->info << endl;
            tmp = tmp->next;
        }
    }

    void golire()
    {
        Nod *tmp;
        tmp = first_element;
        while (!this->isEmpty())
        {
            this->pop();
        }
    }

    friend istream & operator >> (istream &in, Coada_de_caractere &c)
    {
        char l;
        cout << "Dupa ultimul element tastati '.'" << endl;

        while (in >> l)
        {
            if (l != '.')
                c.add_node(l);
            else
                break;
        }
        return in;
    }

    friend ostream & operator << (ostream &out, Coada_de_caractere &c)
    {
        c.display();
        c.golire();
        //out<<c.isEmpty();
        return out;
    }

    Coada_de_caractere operator + (Coada_de_caractere &c1)
    {
        Coada_de_caractere c2;
        //cout<<"INTRARE"<<endl;
        while(this->first_element!=NULL)
        {
            //cout<<"WHILE 1"<<endl;
            c2.add_node(this->first_element->info);
            this->first_element=this->first_element->next;
        }
        //cout<<"DUPA INTRARE"<<endl;
        while(c1.first_element!=NULL)
        {
            //cout<<"WHILE 2"<<endl;
            c2.add_node(c1.first_element->info);
            c1.first_element=c1.first_element->next;
        }
        //cout<<"IESIT"<<endl;
        return c2;
    }

    Coada_de_caractere& operator = (const Coada_de_caractere &c1)
    {
        Nod *f=c1.first_element;
        Coada_de_caractere c2;
        while(f!=NULL)
        {
            this->add_node(f->info);
            f=f->next;
        }
        return *this;
    }

    Coada_de_caractere operator - (Coada_de_caractere &c1)
    {
        Coada_de_caractere c2;

        while((this->first_element!=NULL) || (c1.first_element!=NULL))
        {
            if((!this->isEmpty()) && (!c1.isEmpty()))
            {
                if(int(this->first_element->info) >= int(c1.first_element->info))
                {
                    c2.add_node(this->first_element->info);
                   //this->golire();
                }
                else
                {
                    c2.add_node(c1.first_element->info);
                    //c1.first_element->golire();
                }
                this->pop();
                c1.pop();
                //this->first_element=this->first_element->next;
                //c1.first_element=c1.first_element->next;
            }
            else
                break;
        }

        return c2;
    }

    ~Coada_de_caractere()
    {
        if(first_element == NULL)
           return;

        if(first_element->next != 0)
        {
             delete this->first_element->next;
        }
        delete this->first_element;
    }
};

void Coada_de_caractere :: push (char d)
{
	Nod *tmp;
	tmp = new Nod();
	tmp->info = d;

	if(first_element == NULL)
	{
		tmp->next = NULL;
	}
	else
	{
		last_element->next = tmp;
	}
	//first_element = tmp;
}

void Coada_de_caractere :: pop()
{
	if(first_element == NULL)
		cout << "UNDERFLOW\n";

	else
	{
		Nod *tmp = first_element;
		first_element = first_element->next;
		delete(tmp);
	}
}

bool Coada_de_caractere::isEmpty()
{
    return (first_element == nullptr);
}

int main()
{
    int x;
    char y;
    Coada_de_caractere c1,c2,c3,c4,c5;
    while(x!=7)
    {
        cout<<"MENIU"<<endl<<endl;
        cout<<"Tastati optiunea pe care doriti sa o rulati:"<<endl;
        cout<<"1.CITIRE"<<endl;
        cout<<"2.PUSH"<<endl;
        cout<<"3.POP"<<endl;
        cout<<"4.VERIFICARE COADA GOALA"<<endl;
        cout<<"5.CONCATENARE"<<endl;
        cout<<"6.COMPARATIE ASCII"<<endl;
        cout<<"7.EXIT"<<endl<<endl;
        cout<<"OPTIUNEA: ";
        cin>>x;
        cout<<endl;
        if(x==1)
        {
            cin>>c1;
            cout<<endl;
        }
        if(x==2)
        {
            cout<<"Introduceti elementul: ";
            cin>>y;
            c1.push(y);
            cout<<endl;
            //cout<<c1<<endl;
            c1.display();
            cout<<endl;
        }
        if(x==3)
        {
            c1.pop();
            //cout<<c1<<endl;
            c1.display();
            cout<<endl;
        }
        if(x==4)
        {
            c1.isEmpty();
            if(!c1.isEmpty())
            {
                cout<<"Coada nu este goala!"<<endl<<endl;
            }
            else
            {
                cout<<"Coada este goala!"<<endl<<endl;
            }
        }
        if(x==5)
        {
            cout<<"INTRODUCETI ELEMENTELE NOII COZI:"<<endl;
            cin>>c2;
            cout<<endl;
            c3=c1+c2;
            cout<<c3<<endl<<endl;
        }
        if(x==6)
        {
            cout<<"INTRODUCETI ELEMENTELE NOII COZI:"<<endl;
            cin>>c4;
            cout<<endl;
            c5=c1-c4;
            cout<<c5<<endl<<endl;
        }
    }

    /*Coada_de_caractere s;
    s.add_node('A');
    s.add_node('X');
    s.add_node('C');
    Coada_de_caractere s1;
    s1.add_node('C');
    s1.add_node('D');
    s1.add_node('E');
    s1.add_node('F');
    Coada_de_caractere s2;
    Coada_de_caractere s3;
    Coada_de_caractere s4;
    //cin>>s3;
    //cin>>s4;
    //s2=s4-s3;
    //cout<<s2;
    //s.add_node('C');
      //  cout<<s.isEmpty()<<endl;
    //s.display();
    //s.push('D');
    //s.pop();
    //s.pop();
    //cout<<s.isEmpty()<<endl;
    //s.pop();
    //cout<<s.isEmpty()<<endl;
    //s3.display();
    //s4.display();
    //cout<<s<<endl;
    //s2=s+s1;
    //cout<<s2;
    //cout<<(s+s1);
    s2=s1-s;
    cout<<s2;
    */
}
