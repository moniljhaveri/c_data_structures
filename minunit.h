/* file: minunit.h */
#define mu_assert(message, test) \
    do                           \
    {                            \
        if (!(test))             \
            return message;      \
    } while (0)
#define mu_run_test(test)       \
    do                          \
    {                           \
        char *message = test(); \
        tests_run++;            \
        if (message)            \
            return message;     \
    } while (0)
inline int mu_arr_assert(int numElem, int *expArr, int *actArr) __attribute__((always_inline)); 
inline int mu_arr_assert(int numElem, int *expArr, int *actArr)
{
    for(int i = 0; i < numElem; i++)
    {
        if(*expArr != *actArr){
            return 0; 
        }
        expArr++; 
        actArr++; 
    }
    return 1; 

}
extern int tests_run;
