
TinyJs Bind Helper

class cboy
{
public:
    int set_age(int n) 
    {
        cout << "call from js: boy::set_age(" << n << ")" << endl;
        m_age += n;
        return m_age; 
    }

    void set_name(string name) 
    {
        cout << "call from js: boy::set_name(" << name << ")" << endl;
        m_name = name;
    }

    string do_some_thing(int n, double d, string str)
    {
        cout << "call from js: boy::do_some_thing(" << n << ", " << d << ", " << str << ")" << endl;
        return "ok";
    }
private:
    int     m_age;
    string  m_name;
};

static double mySqr(double d)
{ 
    cout << "call from js: mySqr(" << d << ")" << endl;
    return d*d;
}

static string myStringConcat(string strL, string strR) 
{
    cout << "call from js: myStringConcat(" << strL << ", " << strR << ")" << endl;
    return strL+strR;
}

static double myDoSomeThing(int n, double d, string str1, string str2)
{
    cout << "call from js: myDoSomeThing(" << n << ", " << d << ", " << str1 << ", " << str2 << ")" << endl;
    return n+d;
}

void test()
{
    CTinyJsEx s;

    cboy boy;
    s.AddMemFun( "set_boy_age", &boy, &cboy::set_age );
    s.AddMemFun( "set_boy_name", &boy, &cboy::set_name );
    s.AddMemFun( "boy_do_some_thing", &boy, &cboy::do_some_thing );

    s.AddFun( "sqr", &mySqr );
    s.AddFun( "strcon", &myStringConcat );
    s.AddFun( "do_some_thing", &myDoSomeThing );

    s.Execute( "set_boy_age(5);                                             \
               set_boy_name('egg');                                         \
               boy_do_some_thing(100, 0.9, 'job');                          \
               sqr('2');                                                    \
               strcon('str1', 'str2');                                      \
               do_some_thing(1, 0.5, 'str1', 'str2') " );
}

int _tmain(int argc, _TCHAR* argv[])
{
    test();
    system("pause");
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
Run Result:

call from js: boy::set_age(5)
call from js: boy::set_name(egg)
call from js: boy::do_some_thing(100, 0.9, job)
call from js: mySqr(2)
call from js: myStringConcat(str1, str2)
call from js: myDoSomeThing(1, 0.5, str1, str2)
请按任意键继续. . .
