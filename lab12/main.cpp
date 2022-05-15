#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element
{
    int number;
    element *next;
    element *prev;
};

struct doubleList
{
    element* head;
    element* tail;
    int counter;
};

void addTail(doubleList &l, int value)
{
    element *el=new element;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;
    if (l.tail!=nullptr)
    {
        l.tail->next=el;
        el->prev=l.tail;
    }
    else
        l.head=el;
    l.tail=el;
    l.counter++;
}

void addHead(doubleList &l,int value)
{
    element *el=new element;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;
    if (l.head!=nullptr)
    {
        l.head->prev=el;
        el->next=l.head;
    }
    else
        l.tail=el;
    l.head=el;
    l.counter++;
}

void addPosition(doubleList &l, int value,int position)
{
    if (position==1)
    {
        addHead(l,value);
        return;
    }
    if (position==l.counter+1)
    {
        addTail(l,value);
        return;
    }
    if (position<0 || position>l.counter)
    {
        cout << "nie ma takiej pozycji"<<endl;
        return;
    }

    element *temp=l.head;
    int i=1;
    while (i<position-1)
    {
        temp=temp->next;
        i+=1;
    }
    element *el=new element;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
    l.counter++;
}

void deleteTail(doubleList &l)
{
    element *temp=l.tail;
    if (l.counter==1)
    {
        l.tail=nullptr;
        l.head=nullptr;
    }
    else
    {
        l.tail=l.tail->prev;
        l.tail->next=nullptr;

    }
    delete temp;
    l.counter--;
}

void deleteHead(doubleList &l)
{
    element *temp=l.head;

    if (l.counter==1)
    {
        l.tail=nullptr;
        l.head=nullptr;

    }
    else
    {
        l.head=l.head->next;
        l.head->prev=nullptr;
    }
    delete temp;
    l.counter--;

}

void deletePosition(doubleList &l, int position)
{
    if (position==1)
    {
        deleteHead(l);
        return;
    }
    if (position==l.counter)
    {
        deleteTail(l);
        return;
    }
    if (position<0 || position>l.counter)
    {
        cout << "nie ma takiej pozycji"<<endl;
        return;
    }
    element *temp=l.head;
    int i=1;
    while (i<position-1)
    {
        temp=temp->next;
        i++;

    }
    element *tempUs=temp->next;
    temp->next=tempUs->next;
    temp->next->prev=temp;
    delete tempUs;
    l.counter--;
}

void show(doubleList l)
{
    int i=0;
    element *temp=l.head;
    while(i<l.counter)
    {

        cout << temp->number << "  ";
        temp=temp->next;
        i++;
    }

    cout <<endl;

}

void show2(doubleList l)
{
    int i=l.counter;
    element *temp=l.tail;
    while(i>0)
    {

        cout << temp->number << "  ";
        temp=temp->prev;
        i--;
    }

    cout <<endl;

}

int losuj()
{
    srand(time(NULL));
    return rand()%50;
}

void mini(doubleList l)
{
    int i=1;
    element *temp=l.head;
    int m=temp->number;
    temp=temp->next;
    int pos=0;
    while (i<l.counter)
    {
        if (m>temp->number)
        {
            m=temp->number;
            pos=l.counter;
        }
        temp=temp->next;
        i++;
    }
    cout << "minimum jest rowne: "<<m<<endl;
    cout << "minimum jest na pozycji: "<<pos<<endl;
}

int main()
{
    doubleList l;
    l.head=nullptr;
    l.tail=nullptr;
    l.counter=0;

    cout<< "Podaj co chcesz zrobic"<<endl;
    int index;
    cin >>index;
    while (true)
    {

    switch (index)
    {
    case 1:
        {
            if(l.head==nullptr)
                cout<<"jest pusta"<<endl;
            else
                cout<<"nie jest pusta"<<endl;
            break;
        }
    case 2:
        {int war;
        //cout << "podaj wartosc"<<endl;
        //cin >> war;
        addTail(l,losuj());
        break;
    }
    case 3:
        {int war;
        //cout << "podaj wartosc"<<endl;
        //cin >> war;
        addHead(l,losuj());
        break;
        }
    case 4:
        {
            int war,pos;
            cout << "podaj pozycje"<<endl;
           // cin >> war;
            cin >>pos;
            addPosition(l,losuj(),pos);
            break;
        }
    case 5:
        {
            deleteTail(l);
            break;
        }
    case 6:
        {
            deleteHead(l);
            break;
        }
    case 7:
        {cout << "podaj pozycje"<<endl;
        int pos;
        cin >> pos;
        deletePosition(l,pos);
        break;}
    case 8:
        {show(l);break;}
    case 9:
        {

            show2(l);
            break;
        }
    case 10:
        {
            mini(l);
            break;
        }

    case 11:
        {
            while (l.counter>0)
            {
                deletePosition(l, l.counter);

            }
            break;
        }
    case 12:
        return 0;
    default:
        cout <<"nieprawidlowy wybor"<<endl;
    }
    cout << "co chcesz zrobic"<<endl;
    cin >>index;
    }


}

