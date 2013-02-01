
//#pragma warning (disable : 4786)
#include <iostream>
#include "TextQuery.h"

#pragma warning (disable : 4786)

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <math.h>

//#include <cctype>
//#include <bitset>
//#include <cassert>
//#include <algorithm>

using namespace std;

class Query_base{
   friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base(){}
private:
	virtual set<line_no> 
		eval(const TextQuery &) const = 0;
	virtual ostream &
		display(ostream = cout) const = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const string &);
	Query(const Query & c):q(c.q),use(c.use) {++*use;}
	~Query() { decr_use();}
	Query & operator=(const Query &);
	set<TextQuery::line_no> 
		eval(const TextQuery & t) const {return q->eval(t);}
	ostream &
		display(ostream & os) const {return q->display(os);}
private:
    Query(Query_base * query):q(query),use(new size_t(1)){}
	Query_base * q;
	size_t * use;
	void decr_use()
	{
		if (--*use == 0)
		{
			delete q; delete use;
		}
	}
};

inline Query& Query::operator=(const Query &rhs)
{
    ++*rhs.use; 
    decr_use(); 
    q = rhs.q; 
    use = rhs.use; 
    return *this; 
}

inline std::ostream& 
operator<<(std::ostream &os, const Query &q)
{
    return q.display(os);
}

class WordQuery: public Query_base
{
	friend class Query;
	WordQuery(const string &s):query_word(s){}
	set<line_no> 
		eval(const TextQuery & t) const {return t.run_query(query_word);}
	ostream &
		display(ostream & os) const {return os << query_word;}
	
    string query_word;
};
int main(int argc , char ** argv)
{ 
     return 0;   
}


