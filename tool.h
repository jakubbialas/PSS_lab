#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <vector>
#include <deque>
#include <map>

    template < class T >
    std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
    {
        os << "[ ";
        for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            os << *ii << " ";
        }
        os << "]";
        return os;
    }

    template < class T >
    std::ostream& operator << (std::ostream& os, const std::deque<T>& v)
    {
        os << "[ ";
        for (typename std::deque<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            os << *ii << " ";
        }
        os << "]";
        return os;
    }

    template < class K, class T >
    std::ostream& operator << (std::ostream& os, const std::map<K,T>& v)
    {
        os << "[ ";
        for (typename std::map<K,T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            os << (*ii).first << ": " << (*ii).second << "\n";
        }
        os << "]";
        return os;
    }

#endif // TOOL_H
