#pragma  once

/***********************************************************************
**���ܣ�����º�������,����Ƿº���������ӵĻ���
**���ߣ�                                                                   
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
**���ܣ��Ƚϴ�С
**���ߣ�                                                                   
***********************************************************************/
template <class T>
struct _less : public _binary_function <T, T, bool>{//����ķ��Ͷ����˲������ͺͷ�������
	bool operator()(const T& x, const T& y)const{return x<y;}
};



/***********************************************************************
**���ܣ��º��������� �󶨵ڶ������� ��һ�������ӵ���������
**���ߣ�                                                                   
***********************************************************************/
template <class Operation>
//��������_binder2nd�Ĳ������ͺͷ������ͣ�������Ŀ���Ǹ�����������ã�ʹ�����������Ƕ��ʹ��
class _binder2nd : public  _unary_function<typename Operation::first_argument_type,typename Operation::result_type>{
protected:
	Operation op;
	typename Operation::second_argument_type value;//���������ȡ����������Ϣ
public:
	_binder2nd(const Operation &x, const typename Operation::second_argument_type &y):op(x),value(y){}

	typename Operation::result_type operator()(const typename Operation::first_argument_type &x )const{//��������ʵҲ��һ���º���,������ֻ�ǹ̶��˵ڶ��������ķº���
		return op(x, value);//���ﺯ���ķ������͸�����ӵķº���һ��
	}
};

template <class Operation, class T>
inline _binder2nd<Operation>_bind2nd(const Operation& op, const T& x){
	typedef typename Operation::second_argument_type arg2_type;
	return _binder2nd<Operation>(op, arg2_type(x));
}

/***********************************************************************
**���ܣ�һ�������ķ��ж�
**���ߣ�                                                                   
***********************************************************************/
template<class Predicate>
class _unary_negate : public _unary_function<typename Predicate::argument_type, bool>{
protected:
	Predicate pred; //ν�ʵ������º���
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
**���ܣ����������ķ��ж�
**���ߣ�                                                                   
***********************************************************************/
template<class Predicate>
class _binary_negate : public _binary_function<typename Predicate::first_argument_type,typename Predicate::second_argument_type, bool>{
protected:
	Predicate pred; //ν�ʵ������º���
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