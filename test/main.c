#define CTEST_MAIN
#define CTEST_COLOR_OK
#define CTEST_SEGFAULT

#include <../thirdparty/ctest.h>

int main(int argc, const char* argv[])
{
    return ctest_main(argc, argv);
}