#pragma once
#include "type_list.h"

namespace xtype
{

template <class MemFn, class D = MemFn>
struct FuncTraits
{
};

/* Ordinary function pointers. */

template <class R, class D>
struct FuncTraits <R (*) (), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef NoneType Params;
  static R call (D fp, TypeListValues <Params>)
  {
    return fp ();
  }
};

template <class R, class P1, class D>
struct FuncTraits <R (*) (P1), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1> Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd);
  }
};

template <class R, class P1, class P2, class D>
struct FuncTraits <R (*) (P1, P2), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2> > Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd, tvl.tl.hd);
  }
};

template <class R, class P1, class P2, class P3, class D>
struct FuncTraits <R (*) (P1, P2, P3), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3> > > Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd, tvl.tl.hd, tvl.tl.tl.hd);
  }
};

template <class R, class P1, class P2, class P3, class P4, class D>
struct FuncTraits <R (*) (P1, P2, P3, P4), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4> > > > Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd);
  }
};

template <class R, class P1, class P2, class P3, class P4, class P5, class D>
struct FuncTraits <R (*) (P1, P2, P3, P4, P5), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5> > > > > Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd);
  }
};

template <class R, class P1, class P2, class P3, class P4, class P5, class P6, class D>
struct FuncTraits <R (*) (P1, P2, P3, P4, P5, P6), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5,  TypeList <P6> > > > > > Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd);
  }
};

template <class R, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class D>
struct FuncTraits <R (*) (P1, P2, P3, P4, P5, P6, P7), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6, TypeList <P7> > > > > > > Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.hd);
  }
};

template <class R, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8, class D>
struct FuncTraits <R (*) (P1, P2, P3, P4, P5, P6, P7, P8), D>
{
  static bool const isMemberFunction = false;
  typedef D DeclType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6, TypeList <P7, TypeList <P8> > > > > > > > Params;
  static R call (D fp, TypeListValues <Params> tvl)
  {
    return fp (tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.tl.hd);
  }
};

/* Non-const member function pointers. */

template <class T, class R, class D>
struct FuncTraits <R (T::*) (), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef NoneType Params;
  static R call (T* obj, D fp, TypeListValues <Params>)
  {
    return (obj->*fp)();
  }
};

template <class T, class R, class P1, class D>
struct FuncTraits <R (T::*) (P1), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1> Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd);
  }
};

template <class T, class R, class P1, class P2, class D>
struct FuncTraits <R (T::*) (P1, P2), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2> > Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class D>
struct FuncTraits <R (T::*) (P1, P2, P3), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3> > > Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4> > > > Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5> > > > > Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class P6, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5, P6), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6> > > > > > Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5, P6, P7), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6, TypeList <P7> > > > > > > Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5, P6, P7, P8), D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6, TypeList <P7, TypeList <P8> > > > > > > > Params;
  static R call (T* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.tl.hd);
  }
};

/* Const member function pointers. */

template <class T, class R, class D>
struct FuncTraits <R (T::*) () const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef NoneType Params;
  static R call (T const* obj, D fp, TypeListValues <Params>)
  {
    return (obj->*fp)();
  }
};

template <class T, class R, class P1, class D>
struct FuncTraits <R (T::*) (P1) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1> Params;
  static R call (T const* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd);
  }
};

template <class T, class R, class P1, class P2, class D>
struct FuncTraits <R (T::*) (P1, P2) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2> > Params;
  static R call (T const* obj, R (T::*fp) (P1, P2) const,
    TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class D>
struct FuncTraits <R (T::*) (P1, P2, P3) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3> > > Params;
  static R call (T const* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4> > > > Params;
  static R call (T const* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5> > > > > Params;
  static R call (T const* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class P6, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5, P6) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6> > > > > > Params;
  static R call (T const* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5, P6, P7) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6, TypeList <P7> > > > > > > Params;
  static R call (T const* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.hd);
  }
};

template <class T, class R, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8, class D>
struct FuncTraits <R (T::*) (P1, P2, P3, P4, P5, P6, P7, P8) const, D>
{
  static bool const isMemberFunction = true;
  typedef D DeclType;
  typedef const T ClassType;
  typedef R ReturnType;
  typedef TypeList <P1, TypeList <P2, TypeList <P3, TypeList <P4, TypeList <P5, TypeList <P6, TypeList <P7, TypeList <P8> > > > > > > > Params;
  static R call (T const* obj, D fp, TypeListValues <Params> tvl)
  {
    return (obj->*fp)(tvl.hd, tvl.tl.hd, tvl.tl.tl.hd, tvl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.hd, tvl.tl.tl.tl.tl.tl.tl.tl.hd);
  }
};

}