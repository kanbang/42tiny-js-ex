#pragma once
#include "type_list.h"

namespace xtype
{
/**
  A TypeList with actual values.
*/
template <typename List>
struct LuaParam
{
  static std::string const tostring (bool)
  {
    return "";
  }
};

/**
  TypeListValues recursive template definition.
*/
template <typename Head, typename Tail>
struct LuaParam <TypeList <Head, Tail> >
{
  static std::string const tostring (bool comma = false)
  {
    std::string s;

    if (comma)
      s = ", ";

    s = s + typeid (Head).name ();

    return s + LuaParam <Tail>::tostring (true);
  }
};

// Specializations of type/value list for head types that are references and
// const-references.  We need to handle these specially since we can't count
// on the referenced object hanging around for the lifetime of the list.

template <typename Head, typename Tail>
struct LuaParam <TypeList <Head&, Tail> >
{
  static std::string const tostring (bool comma = false)
  {
    std::string s;

    if (comma)
      s = ", ";

    s = s + typeid (Head).name () + "&";

    return s + LuaParam <Tail>::tostring (true);
  }
};

template <typename Head, typename Tail>
struct LuaParam <TypeList <Head const&, Tail> >
{
  static std::string const tostring (bool comma = false)
  {
    std::string s;

    if (comma)
      s = ", ";

    s = s + typeid (Head).name () + " const&";

    return s + LuaParam <Tail>::tostring (true);
  }
};

//==============================================================================
/**
  Subclass of a TypeListValues constructable from the Lua stack.
*/

template <typename List, int Start = 1>
struct ArgList
{
};

template <int Start>
struct ArgList <None, Start> : public LuaParam <None>
{
  ArgList (lua_State*)
  {
  }
};

template <typename Head, typename Tail, int Start>
struct ArgList <TypeList <Head, Tail>, Start>
  : public LuaParam <TypeList <Head, Tail> >
{
  ArgList (lua_State* L)
    : LuaParam <TypeList <Head, Tail> > (Stack <Head>::get (L, Start),
                                            ArgList <Tail, Start + 1> (L))
  {
  }
};

}