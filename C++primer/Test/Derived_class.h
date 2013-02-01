#ifndef _DERIVED_CLASS_H_
#define _DERIVED_CLASS_H_

#include <iostream>
#include <string>

using namespace std;

class Item_base
{
public:
      Item_base(const string & book = " ", 
		        double sales_price = 0.0):
	            ISBN(book),price(sales_price)
				{
					cout << "Item_base(string &, double)" << endl;
				}
	  
  	  string book() const
	  {
		  return ISBN;
	  }

      virtual double net_price(size_t n)
	  {
	      return n * price;    
	  }

	  Item_base(const Item_base & b):
	           ISBN(b.ISBN),price(b.price)
		{
          cout << "Item_base(const Item_base &)" << endl;
		}

      Item_base & operator=(Item_base & rhs)
	  {
	      price = rhs.price;
		  ISBN = rhs.ISBN;

		  cout << "Item_base & operator=(Item_base &)" 
			   << endl;

		  return *this;
	  }

	  virtual ~Item_base()
	  {
		  cout << "virtual ~Item_base()" << endl;
	  }

protected:
	 double price;   
private:
     string ISBN;
};

class Bulk_item : public Item_base
{
public:
	Bulk_item(const string & book = " ", 
		      double  sales_price = 0.0,
			  size_t  qty = 0, double  disc_rate = 0.0):
	          Item_base(book, sales_price),
			  min_qty(qty),discount(disc_rate)
	{
	   cout << "Bulk_item(const string &, double, size_t, double)" 
		    << endl;
	}

	virtual double net_price(size_t cnt) const
	{
      if (cnt >= min_qty)
      {
		  return cnt * (1 - discount) * price;
      }
	  else
	  {
		  return cnt * price;
	  }
	}

    Bulk_item(Bulk_item & b):
	Item_base(b),min_qty(b.min_qty),discount(b.discount)
	{
       cout << "Bulk_item(Bulk_item &)" << endl;
	}

	Bulk_item & operator=(Bulk_item & rhs)
	{
		if (this != & rhs)
		{
			Item_base::operator=(rhs);
			min_qty = rhs.min_qty;
			discount = rhs.discount;

			cout << "Bulk_item & operator=(Bulk_item & )" 
				 << endl;
		}
	}

	virtual ~Bulk_item()
	{
		cout << "virtual ~Bulk_item()" << endl;
	}

private:
	size_t min_qty;
	double discount;
};
   
    void func1(Item_base obj)
	{

	}

	void func2(Item_base & obj)
	{
		
	}

	Item_base func3()
	{
	  Item_base obj;
	  return obj;
	}

#endif

/*
	int main(int argc , char ** argv)
	{ 
		//Item_base iobj;
		
		//func1(iobj);
		
		//func2(iobj);
		
		//iobj = func3();
		
		//Item_base *p = new Item_base;
		
		//delete p;
		
		//Bulk_item bobj;
		
		//func1(bobj);
		
		//func2(bobj);
		
		//Bulk_item * p = new Bulk_item;
		
		//delete p
		
		return 0;   
}
*/