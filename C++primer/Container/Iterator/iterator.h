#pragma  once

#define  _STL_TEMPLATE_NULL template<>

//�����ڲ�״̬��ȡ
struct  _true_type{};
struct  _false_type{};

//Ĭ�����
template<class type>
struct _type_traits{

	typedef _false_type  has_trivial_default_constructor;
	typedef _false_type  has_trivial_copy_constructor;
	typedef _false_type  has_trivial_assignment_constructor;
	typedef _false_type  has_trivial_destructor;
	typedef _false_type  is_POD_type;

};

//���������ָ��
template<class T>  
struct _type_traits<T*>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

//��������ǻ�������

_STL_TEMPLATE_NULL struct _type_traits<char>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

_STL_TEMPLATE_NULL struct _type_traits<int>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

_STL_TEMPLATE_NULL struct _type_traits<unsigned int>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

_STL_TEMPLATE_NULL struct _type_traits<unsigned long>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

_STL_TEMPLATE_NULL struct _type_traits<float>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

_STL_TEMPLATE_NULL struct _type_traits<double>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

_STL_TEMPLATE_NULL struct _type_traits<unsigned short>{

	typedef _true_type  has_trivial_default_constructor;
	typedef _true_type  has_trivial_copy_constructor;
	typedef _true_type  has_trivial_assignment_constructor;
	typedef _true_type  has_trivial_destructor;
	typedef _true_type  is_POD_type;

};

//���͵���ȡ
struct _input_iterator_tag{};
struct _output_iterator_tag{};
struct _forward_iterator_tag{};
struct _bidirectional_iterator_tag{};
struct _randomaccess_iterator_tag{};

//����ǵ������ǽṹ��
template<class Iterator>
struct _iterator_traits
{	
	typedef typename Iterator::iterator_category   iterator_category;
	typedef typename Iterator::value_type             value_type;
	typedef typename Iterator::difference_type     difference_type;
	typedef typename Iterator::pointer                  pointer;
	typedef typename Iterator::reference               reference;
};

//����ǵ�������ԭ��ָ̬��
template<class T>
struct _iterator_traits<T*>
{	
	typedef _randomaccess_iterator_tag iterator_category;

	typedef T             value_type;
	typedef ptrdiff_t  difference_type;
	typedef T*            pointer;
	typedef T&           reference;
};

/*
template<class Iterator>
inline typename _iterator_traits<Iterator>::value_type* value_type(const Iterator &){
	return static_cast<typename _iterator_traits<Iterator>::value_type*>(0);
}
*/

