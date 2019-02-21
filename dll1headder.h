
#ifndef dll1headder_H
#define dll1headder_H
namespace dll1spec{
class dll1class{
public:
    static __declspec(dllexport) float dllcalculate(char* fx,float t);
    static __declspec(dllexport) float num(char *s);
};
}


#endif // dll1headder_H
