/* 
 * File:   CBase64Tool.h
 * Author: Feng
 *
 * Created on 2015年10月31日, 下午4:02
 */

#ifndef CBASE64TOOL_H
#define	CBASE64TOOL_H


#include <string>

using namespace std;

class CBase64Tool {
public:
    CBase64Tool();
    CBase64Tool(const CBase64Tool& orig);
    virtual ~CBase64Tool();
    
    string Base64Encode( const string src );
    string Base64Decode( const string encoded_string );
    
private:

};

#endif	/* CBASE64TOOL_H */

