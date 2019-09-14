# Use static library
add_library(MathFunctions STATIC mysqrt.c)

# Use shared library
#add_library(MathFunctions SHARED mysqrt.cxx)

install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.h DESTINATION include)