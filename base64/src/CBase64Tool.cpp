/* 
 * File:   CBase64Tool.cpp
 * Author: Feng
 * 
 * Created on 2015年10月31日, 下午4:02
 */

#include "CBase64Tool.h"

CBase64Tool::CBase64Tool( ) {
}

CBase64Tool::CBase64Tool( const CBase64Tool& orig ) {
}

CBase64Tool::~CBase64Tool( ) {
}

/**
 * base64 编码
 * @param src
 * @return 
 */
string CBase64Tool::Base64Encode( const string src ) {
    
    int i, j, srcLen = src.length( );
    string dst( srcLen / 3 * 4 + 4, 0 );
    
    for ( i = 0, j = 0; i <= srcLen - 3; i += 3, j += 4 ) {
        dst[j] = (src[i] & 0xFC) >> 2;
        dst[j + 1] = ((src[i] & 0x03) << 4) + ((src[i + 1] & 0xF0) >> 4);
        dst[j + 2] = ((src[i + 1] & 0x0F) << 2) + ((src[i + 2] & 0xC0) >> 6);
        dst[j + 3] = src[i + 2] & 0x3F;
    }
    if ( srcLen % 3 == 1 ) {
        dst[j] = (src[i] & 0xFC) >> 2;
        dst[j + 1] = ((src[i] & 0x03) << 4);
        dst[j + 2] = 64;
        dst[j + 3] = 64;
        j += 4;
    } else if ( srcLen % 3 == 2 ) {
        dst[j] = (src[i] & 0xFC) >> 2;
        dst[j + 1] = ((src[i] & 0x03) << 4) + ((src[i + 1] & 0xF0) >> 4);
        dst[j + 2] = ((src[i + 1] & 0x0F) << 2);
        dst[j + 3] = 64;
        j += 4;
    }

    static unsigned char *base64 = (unsigned char*) ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=");
    for ( i = 0; i < j; ++i ) { //map 6 bit value to base64 ASCII character
        dst[i] = base64[(int) dst[i]];
    }

    return dst;
}




static inline bool is_base64(unsigned char c) {  
  return (isalnum(c) || (c == '+') || (c == '/'));  
}  
/**
 * base64解码
 * @param src
 * @return 
 */
string CBase64Tool::Base64Decode( const string encoded_string ) {
static const std::string base64_chars =   
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  
             "abcdefghijklmnopqrstuvwxyz"  
             "0123456789+/";
    
  int in_len = encoded_string.size();  
  int i = 0;  
  int j = 0;  
  int in_ = 0;  
  unsigned char char_array_4[4], char_array_3[3];  
  std::string ret;  
  
  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {  
    char_array_4[i++] = encoded_string[in_]; in_++;  
    if (i ==4) {  
      for (i = 0; i <4; i++)  
        char_array_4[i] = base64_chars.find(char_array_4[i]);  
  
      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);  
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);  
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];  
  
      for (i = 0; (i < 3); i++)  
        ret += char_array_3[i];  
      i = 0;  
    }  
  }  
  
  if (i) {  
    for (j = i; j <4; j++)  
      char_array_4[j] = 0;  
  
    for (j = 0; j <4; j++)  
      char_array_4[j] = base64_chars.find(char_array_4[j]);  
  
    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);  
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);  
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];  
  
    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];  
  }  
  
  return ret;  
}

