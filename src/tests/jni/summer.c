#include "Summer.h"
 
int csum(int x, int y)
{
    return x + y;
}
 
JNIEXPORT jint JNICALL Java_Summer_sum(JNIEnv *env, jobject jobj, jint x, jint y)
{
    return csum(x, y);
}