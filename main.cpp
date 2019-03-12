#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;

 ifstream f("Numere.txt");


 struct pol
 {
     int coef, gr;
     pol *next;
 };


 void citire_polinomP(pol *&p, pol *&prim1, pol *&ultim1)
 {    int x,y;
       int i,n;
       f>>n;

    for(i=0;i<n;i++)
    {

        f>>x>>y;
        if(x!=0)
        { p=new pol;
            p->coef=x;
          p->gr=y;

        p->next=NULL;

        if(prim1==NULL)
        prim1=ultim1=p;
       else
        {ultim1->next=p;
        ultim1=p;}
        }

    }
 }


  void citire_polinomQ(pol *&q, pol *&prim2, pol *&ultim2)
{    int x,y;
     int i,n;
     f>>n;
      for(i=0;i<n;i++) /// n termeni
      {   f>>x>>y;
        if(x!=0)
        { q=new pol;
            q->coef=x;
          q->gr=y;
         q->next=NULL;
        if(prim2==NULL)
        prim2=ultim2=q;
        else
        {ultim2->next=q;
        ultim2=q;}
        }

    }
 }


 void afisareP(pol *&p, pol *&prim1)
 {

    p=prim1;
     cout<<"P(x)=";
    while(p!=NULL)
    {
        cout<<(*p).coef<<"X^"<<p->gr<<"+";
        p=(*p).next;
    }
    cout<<"\n";
 }

 void afisareQ(pol *&q, pol *&prim2)
 {

     q=prim2;
     cout<<"Q(x)=";
    while(q!=NULL)
    {
        cout<<(*q).coef<<"X^"<<q->gr<<"+";
        q=(*q).next;
    }
    cout<<"\n";
 }

 void afisareCoefDupaInmultireCuScalar(pol *&p, pol *&prim1,pol *&q, pol *&prim2 )
{
     int a;
     f>>a;

     p=prim1;
     cout<<"Coeficientii lui P inmultiti cu "<<a<<":  ";
     while(p!=NULL)
     {
         cout<<a*(p->coef)<<" ";
         p=p->next;
     }

      cout<<"\nCoeficientii lui Q:";

     q=prim2;
     while(q!=NULL)
     {
         cout<<a*(q->coef)<<" ";
         q=q->next;
     }
     cout<<"\n";
 }


 void afisare_PdeX(pol *&p, pol *&prim1)
 {   int s=0,x;
     f>>x;
     p=prim1;
     while(p!=NULL)
     {
         s=s+p->coef*pow(x,p->gr);
         p=p->next;
     }

     cout<<"P("<<x<<")="<<s;
     cout<<"\n";
 }

 void afisare_QdeX(pol *&q, pol *&prim2)
 {   int s=0,x;
     f>>x;
     q=prim2;
     while(q!=NULL)
     {
         s=s+q->coef*pow(x,q->gr);
         q=q->next;
     }

     cout<<"Q("<<x<<")="<<s;
     cout<<"\n";
 }



 void SumaPolPsiQ(pol *&p, pol *&prim1 , pol *&q, pol *&prim2,pol *&prim3, pol *&ultim3, pol *&r)
    {
        p=prim1; q=prim2;

        while(p!=NULL&&q!=NULL)
        {   if(p->gr==q->gr)
           {

               r=new pol;
             r->coef=p->coef+q->coef;
             r->gr=p->gr;
             r->next=NULL;

           if (prim3==NULL)
            prim3=ultim3=r;
           else
            { ultim3->next=r;
              ultim3=r;
           }

           p=p->next;
           q=q->next;

        }

        else
        if(p->gr>q->gr)
            { while(p!=NULL&&p->gr>q->gr)
              {
              r=new pol;
              r->coef=p->coef;
              r->gr=p->gr;
              r->next=NULL;

              if(prim3==NULL)
                prim3=ultim3=r;
              else
              {
               ultim3->next=r;
               ultim3=r;

              }
              p=p->next;

             }

        }
          else
            {if(p->gr<q->gr)
           while(p!=NULL&&q!=NULL&&p->gr<q->gr)
            {
              r=new pol;
              r->coef=q->coef;
              r->gr=q->gr;
              r->next=NULL;
              if(prim3==NULL)
                prim3=ultim3=r;
              else
              {ultim3->next=r;
              ultim3=r;}

              q=q->next;

             }}

        }



        while(p!=NULL)
        {
             r= new pol;
             r->coef=p->coef;
             r->gr=p->gr;
             r->next=NULL;

             if(prim3==NULL)
                prim3=ultim3=NULL;
             else
             {ultim3->next=r;
             ultim3=r;}

             p=p->next;


        }cout<<"Si aici?";


        while(q!=NULL)
        {
             r= new pol;
             r->coef=q->coef;
             r->gr=q->gr;
             r->next=NULL;

             if(prim3==NULL)
                prim3=ultim3=r;
             else
             {ultim3->next=r;
             ultim3=r;}

             q=q->next;


        }

    }

 void afisare_PplusQ(pol *&r,pol *&prim3)
 {
     r=prim3;
     cout<<"P+Q=";
    while(r!=NULL)
    {
        cout<<(*r).coef<<"X^"<<r->gr<<"+";
        r=(*r).next;
    }
    cout<<"\n";
 }



 void ProdusPsiQ(pol *&p, pol *&prim1,pol *&q, pol *&prim2,pol *&pr, pol *&prim4, pol *&ultim4)
 {  pol *prim=NULL, *ultim=NULL, *Prim=NULL, *Ultim=NULL;
    pol *c, *c1  ;

    p=prim1;

    while(p!=NULL)
    {   q=prim2;
        while(q!=NULL)
        {
             c=new pol;
             c->coef=p->coef*q->coef;
             c->gr=p->gr+q->gr;
             c->next=NULL;

             if(prim==NULL)
                prim=ultim=c;
             else
            {  ultim->next=c;
                ultim=c;

             }

            q=q->next;
        }

         cout<<"Produsul intre un termen si polinomul Q efectuat\n";




    c=prim;
     cout<<"C(x)=";
    while(c!=NULL)
    {
        cout<<(*c).coef<<"X^"<<c->gr<<"+";
        c=(*c).next;
    }
    cout<<"\n";


        SumaPolPsiQ(c1,Prim,c,prim,prim4,ultim4,pr);

      prim=ultim=NULL;
      Prim=Ultim=NULL;

      pr=prim4;        ///copii in c1 pe pr adica ultima suma

      while(pr!=NULL)
      {  c1=new pol;
         c1->gr=pr->gr;
         c1->coef=pr->coef;
         c1->next=NULL;
         if(Prim==NULL)
            Prim=Ultim=pr;
         else
            {Ultim->next=c1;
            Ultim=c1;}

          pr=pr->next;

      }

     if(p->next!=NULL)
      prim4=ultim4=NULL;

         p=p->next;
    }
cout<<"PRODUS EFECTUAT:\n\n";
    }

void afisare_produs( pol *&pr, pol *&prim4)
{
    pr=prim4;

    cout<<"P(x)*Q(x)=";
    while(pr!=NULL)
    {
        cout<<pr->coef<<"X^"<<pr->gr<<"+";
        pr=pr->next;
    }
    cout<<"\n";

}

int main()
{
       pol *prim1=NULL, *prim2=NULL, *ultim1=NULL, *ultim2=NULL;
       pol *prim3=NULL,*ultim3=NULL, *prim4=NULL, *ultim4=NULL;
       pol *p, *q, *r,*pr;

      citire_polinomP(p,prim1,ultim1);
      afisareP(q,prim1);

      citire_polinomQ(q,prim2, ultim2);
      afisareQ(q,prim2);


      afisareCoefDupaInmultireCuScalar(q,prim1,q,prim2);
      afisare_PdeX(q,prim1);
      afisare_QdeX(q,prim2);
      SumaPolPsiQ(p,prim1,q,prim2,prim3,ultim3,r);
      afisare_PplusQ(r,prim3);

     ProdusPsiQ(p,prim1,q,prim2,pr,prim4,ultim4);
      afisare_produs(pr,prim4);
      cout<<"Final";

    return 0;
}
