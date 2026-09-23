
#include <iostream>
using namespace std;

class account{
    protected:
   int account_number; 
   string holder_name; 
   float balance; 
   
   public:
   account(): account_number(0),holder_name(""),balance(0){}
   account(int acn, string n, float b): account_number(acn), holder_name(n), balance(b){}
  virtual void d(){
       cout<<"enter name: ";
       cin>>holder_name;
       cout<<"enter account number: ";
       cin>>account_number;
       cout<<"enter balance: ";
       cin>>balance;
   }

   // virtual void dis(){
   //  cout<<"name of account holder is: "<<holder_name<<endl;
   //  cout<<"account number is: "<<account_number<<endl;
   //  cout<<"Balance is: "<<balance<<endl;
   // }

    float getb(){
        return balance;
    }
    void sb(float b){
        balance=b;
    }
   virtual ~account(){}
   
};

class savingaccount:virtual public account{
    private:
    float deposite;
    //float withdrawl;
    float ad;
    
    public:
    savingaccount()
        : account(), deposite(0),ad(0) {}
    savingaccount(int acn, string n, float b,float d,float a): account(acn,n,b),deposite(d),ad(a){}
    
    void getd(){
        cout<<"enter deposite amount: ";
        cin>>ad;
    }
    void displays(){
        deposite=balance+ad;
        cout<<"deposite is: "<<deposite<<endl;
        balance=deposite;
    }
    
};

class currentaccount: public savingaccount{
    private:
    float withdrawal;
    float waa;
    public:
    currentaccount():savingaccount(), withdrawal(0),waa(0){}
    currentaccount(int acn, string n, float b,float d,float a,float w,float wa):savingaccount(acn,n,b,d,a),withdrawal(w),waa(wa){}
    
    void getw(){
        cout<<"enter withdrawal amonut: ";
        cin>>waa;
    }
    void display(){
        //balance=deposite;
        withdrawal=balance-waa;
        cout<<"withdrawal amount is: "<<withdrawal<<endl;
        balance=withdrawal;
    }
};
class fixedd: public account{
    private:
    float principle;
    float rate;
    float time_p;
     float simple_i;
    public:
    fixedd(): account(),principle(0),rate(0),time_p(0),simple_i(0){}
    fixedd(int acn, string n, float b,float p,float r, float t, float sim): account(acn,n,b),principle(p),rate(r),time_p(t),simple_i(sim){}

    void displayprt(){
        cout<<"enter principle valua: ";
        cin>>principle;
         cout<<"enter rate (in points): ";
        cin>>rate;
         cout<<"enter time period: ";
        cin>>time_p;
    }
    void displaysim(){
          simple_i=(principle*time_p*rate)/100;
          cout<<"simple interest is: "<<simple_i<<endl;
    }

};


int main()
{
    savingaccount s;
    currentaccount c;
    fixedd f;
    cout<<"____________Account holder data____________"<<endl;
    s.d();
    cout<<"\n";
    cout<<"____________information about deposite amount____________"<<endl;
    s.getd();
    s.displays();
    cout<<"\n";
    cout<<"____________information about withdrawal amount____________"<<endl;
    c.sb(s.getb());
    c.getw();
    c.display();
    cout<<"\n";
    cout<<"____________information about simple interest____________"<<endl;
    f.displayprt();
    f.displaysim();

    return 0;
}