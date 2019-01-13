#include<iostream>
#include <vector>
#include <set>
#include <map>
 
using namespace std;
 
/* -------------------This is the part you need to copy ----------------------*/
 
#if DEBUG && !ONLINE_JUDGE
 
    // Author :  Nikhil Garg
    
    #define debug(args...)     (Debugger()) , args
 
    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}
        
        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << endl;}
        
        private:
        bool first;
        std::string separator;
    };
 
    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
 
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }
    
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif
 
/*-------------------------------Stop here---------------------------------*/
 
int main()          
{
 
    // Usage howto and testing debug macro
    
    int T= 1;
    debug(T, 2, 10, "String");
    vector<int> A;
    set<double> s;
    s.insert(12.3); s.insert(20.98);
    debug("Vector A", A, "Set S", s);
    pair<int, string> P(41, "Nikhil");
    pair<double, pair<int, string> > PP(12.2, P);
    debug(PP);
    map<int, int> freq;
    freq[21] = 3;
    freq[89] = 5;
    debug(freq);
 
    int B[20];
    B[0] = 123; B[1] = 232; B[2] = 92;
    typedef vector<int> VI;
    debug(VI(B, B+3));
    
    return 0;
}