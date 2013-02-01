#pragma  once

/***********************************************************************
**功能：定义仿函数基类,这个是仿函数进行配接的基础
**作者：                                                                   
***********************************************************************/
template <class Arg, class Result>
struct _unary_function{
	typedef Arg argument_type;
	typedef Result result_type;
};

template <class Arg1, class Arg2, class Result>
struct _binary_function{
	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Result result_type;
};

/***********************************************************************
**功能：比较大小
**作者：                                                                   
***********************************************************************/
template <class T>
struct _less : public _binary_function <T, T, bool>{//这里的泛型定义了参数类型和返回类型
	bool operator()(const T& x, const T& y)const{return x<y;}
};



/***********************************************************************
**功能：仿函数适配器 绑定第二个参数 第一个参数从迭代器中来
**作者：                                                                   
***********************************************************************/
template <class Operation>
//这里声明_binder2nd的参数类型和返回类型，声明的目的是给其他配接器用，使得配接器可以嵌套使用
class _binder2nd : public  _unary_function<typename Operation::first_argument_type,typename Operation::result_type>{
protected:
	Operation op;
	typename Operation::second_argument_type value;//这里就是提取函数类型信息
public:
	_binder2nd(const Operation &x, const typename Operation::second_argument_type &y):op(x),value(y){}

	typename Operation::result_type operator()(const typename Operation::first_argument_type &x )const{//适配器其实也是一个仿函数,在这里只是固定了第二个参数的仿函数
		return op(x, value);//这里函数的返回类型跟被配接的仿函数一致
	}
};

template <class Operation, class T>
inline _binder2nd<Operation>_bind2nd(const Operation& op, const T& x){
	typedef typename Operation::second_argument_type arg2_type;
	return _binder2nd<Operation>(op, arg2_type(x));
}

/***********************************************************************
**功能：一个参数的否定判断
**作者：                                                                   
***********************************************************************/
template<class Predicate>
class _unary_negate : public _unary_function<typename Predicate::argument_type, bool>{
protected:
	Predicate pred; //谓词单参数仿函数
public:
	explicit _unary_negate(const Predicate& x): pred(x){}
	bool operator()(const typename Predicate::argument_type &x)const {
		return !pred(x);
	}
};

template<class Predicate>
inline _unary_negate<Predicate> _not1(const Predicate& pred){
	return _unary_negate<Predicate>(pred);
}

/***********************************************************************
**功能：两个参数的否定判断
**作者：                                                                   
***********************************************************************/
template<class Predicate>
class _binary_negate : public _binary_function<typename Predicate::first_argument_type,typename Predicate::second_argument_type, bool>{
protected:
	Predicate pred; //谓词单参数仿函数
public:
	explicit _binary_negate(const Predicate& x): pred(x){}
	bool operator()(const typename Predicate::first_argument_type& x,typename Predicate::second_argument_type& y)const {
		return !pred(x, y);
	}
};

template<class Predicate>
inline _binary_negate<Predicate> _not2(const Predicate& pred){
	return _binary_negate<Predicate>(pred);
}