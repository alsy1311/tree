#include<iostream>

using namespace std;

class Container

{

public:

    virtual void insert(int value) = 0;

    // Ýòî ïîòîì çàìåíèì íà ïåðåãðóæåííûé îïåðàòîð <<

    // Âèðòóàëüíûé äåñòðóêòîð

    virtual bool exists(int value) = 0;

    virtual void print() = 0;

    virtual void remove(int value) = 0;

    virtual ~Container();

};

Container::~Container() { }

class SimpleTree : public Container

{

protected:

    int R;

struct el

{

    int value;

    struct el* left;

    struct el* right;

    struct el* parent;

};

struct el* root;

public:

SimpleTree()

{

    root = NULL;

    R = 0;

}

void insert(int value)

{

    R += 1;

    if (R == 1 )

    {

        root = create(value);

    }

    else

    {

    struct el* s = create(value);

    insert(root,s);

    }

}

void print()

{

    print_tree(root);

}

bool exists(int value)

{

    struct el* c = create(value);

    struct el* k = find(root,c);

    delete(c);

    if (k != NULL)

    {

        return true;

    }

    else

    {

        return false;

    }

}

void remove(int value)



{



    struct el* c = create(value);



    struct el* k = find(root, c);



    struct el* t = LAST_ELEMENT(k -> right);

    delete(c);

    DELETE(k, t);



}



void DELETE(struct el* k, struct el* t)



{



    if (k -> right != NULL)



    {



        k -> right -> parent = k -> parent;



        if (k -> parent -> right == k )



        {



            k -> parent -> right = k -> right;



        }



        else



        {



            k -> parent -> left = k -> right;



        }



        if (k -> left != NULL)



        {



            if (k -> right -> left == NULL)



                {



                    k -> left -> parent = k -> right ;



                    k -> right -> left = k -> left;



                }



            else



                {



                    k -> left -> parent = t ;



                    t -> left = k -> left;



                }



        }



    }



    else



    {



        k -> left -> parent = k -> parent;



        if (k -> parent -> right == k )



        {



            k -> parent -> right = k -> left;



        }



        else



        {



            k -> parent -> left = k -> left;



        }



    }



   delete k;



}



struct el* LAST_ELEMENT( struct el* p )



{



    if (p != NULL)



    {



        if (p -> left != NULL)



    {



        return LAST_ELEMENT(p -> left);



    }



    else



    {



        return( p );



    }







    }



    else



    {



        return (p -> parent);



    }



};



struct el* create(int a)







{ struct el* s = new struct el;







  s -> value = a;







  s -> left = NULL;







  s -> right = NULL;







  s -> parent = NULL;







  return s;







};







void insert(struct el* root, struct el* s)







{







    if (root -> value >= s -> value )







    {







        if (root -> left == NULL)







        {







            root -> left = s ;







            s -> parent = root ;















        }







        else







        {







            insert ( root -> left, s);







        }







    }







    else







    {







        if (root -> right == NULL)







        {







            root -> right = s ;







            s -> parent = root ;







        }







        else







        {







            insert (root -> right, s);







        }















    }







}







void print_tree(struct el* root)







{







    cout << root -> value << endl;







    if ( root -> left != NULL )







    {







        print_tree(root -> left);







    }







    if ( root -> right != NULL )







    {







        print_tree( root -> right);







    }







}







struct el* find(struct el* root, struct el* c)







{







    if (root -> value == c -> value)







    {







        return root;







    }







    if (root -> value < c -> value)







    {







        if (root -> right != 0)







        {







            return find(root -> right, c);







        }







        else







        {







            return NULL;







        }















    }







     if (root -> value > c -> value)







    {







        if (root -> right != 0)







        {







            return find(root -> left, c);







        }







        else







        {







            return NULL;







        }







    }







    return NULL;







};















};







int main()







{







    Container* c = new SimpleTree();







    for(int i = 1; i < 10; i++)







    c->insert(i*i);







    cout << "List after creation: " << endl ;







    c->print();







    if(c->exists(25))







    cout << "Search for value 25: found" << endl;







    if(!c->exists(111))







    cout << "Search for value 111: not found" << endl;



    c->remove(25);







    cout << "List after deletion of the element:" << endl;







    c->print();



    delete c;







    return 0;







}
