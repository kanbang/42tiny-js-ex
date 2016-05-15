#pragma once

namespace xtype
{

class NoneType {};

template <class T, class U=NoneType>
struct TypeList
{
	typedef T Head;
	typedef U Tail;
};


//////////////////////////////////////////////////////////////////////////
template <typename List>
struct TypeListValues
{
};

template <typename Head, typename Tail>
struct TypeListValues <TypeList <Head, Tail> >
{
	Head hd;
	TypeListValues <Tail> tl;

	TypeListValues (Head hd_, TypeListValues <Tail> const& tl_)
		: hd (hd_), tl (tl_)
	{
	}
};

//////////////////////////////////////////////////////////////////////////
template
	<
	typename T1  = NoneType, typename T2  = NoneType, typename T3  = NoneType,
	typename T4  = NoneType, typename T5  = NoneType, typename T6  = NoneType,
	typename T7  = NoneType, typename T8  = NoneType, typename T9  = NoneType,
	typename T10 = NoneType, typename T11 = NoneType, typename T12 = NoneType,
	typename T13 = NoneType, typename T14 = NoneType, typename T15 = NoneType,
	typename T16 = NoneType, typename T17 = NoneType, typename T18 = NoneType
	> 
struct MakeTypeList
{
private:
	typedef typename MakeTypeList
		<
		T2 , T3 , T4 , 
		T5 , T6 , T7 , 
		T8 , T9 , T10, 
		T11, T12, T13,
		T14, T15, T16, 
		T17, T18
		>
		::Result TailResult;

public:
	typedef TypeList<T1, TailResult> Result;
};

template<>
struct MakeTypeList<>
{
	typedef NoneType Result;
};

//////////////////////////////////////////////////////////////////////////
template
	<
		class T01=NoneType,class T02=NoneType,class T03=NoneType,class T04=NoneType,class T05=NoneType,
		class T06=NoneType,class T07=NoneType,class T08=NoneType,class T09=NoneType,class T10=NoneType,
		class T11=NoneType,class T12=NoneType,class T13=NoneType,class T14=NoneType,class T15=NoneType,
		class T16=NoneType,class T17=NoneType,class T18=NoneType,class T19=NoneType,class T20=NoneType
	>
struct Seq
{
private:
	typedef typename Seq<     T02, T03, T04, T05, T06, T07, T08, T09, T10,
		T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>::Type 
		TailResult;
public:
	typedef TypeList<T01, TailResult> Type;
};

template<>
struct Seq<>
{
	typedef NoneType Type;
};

//////////////////////////////////////////////////////////////////////////
template <class TList> struct Length;
template <> struct Length<NoneType>
{
	enum { value = 0 };
};

template <class T, class U>
struct Length< TypeList<T, U> >
{
	enum { value = 1 + Length<U>::value };
};

//////////////////////////////////////////////////////////////////////////
template <class TList, unsigned int index> struct TypeAt;

template <class Head, class Tail>
struct TypeAt<TypeList<Head, Tail>, 0>
{
	typedef Head Result;
};

template <class Head, class Tail, unsigned int i>
struct TypeAt<TypeList<Head, Tail>, i>
{
	typedef typename TypeAt<Tail, i - 1>::Result Result;
};

}